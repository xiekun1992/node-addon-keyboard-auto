#include "listener.h"

std::function<void(long*)> lambda_mouse_handler;
std::function<void(long*)> lambda_keyboard_handler;
int stop = 0;

void callback(XPointer pointer, XRecordInterceptData* hook) {
  static int cursorx, cursory;
  if (hook->category != XRecordFromServer) {
    XRecordFreeData(hook);
    return;
  }
  XRecordDatum* data = (XRecordDatum*)hook->data;
  int event_type = data->type;

  BYTE btncode, keycode;
  btncode = keycode = data->event.u.u.detail;
  int rootx = data->event.u.keyButtonPointer.rootX;
  int rooty = data->event.u.keyButtonPointer.rootY;

  switch(event_type) {
    case KeyPress: 
      lambda_keyboard_handler(
        new long[3]{L_KEYDOWN, keycode, 0}
      ); 
      break;
    case KeyRelease: 
      lambda_keyboard_handler(
        new long[3]{L_KEYUP, keycode, 0}
      ); 
      break;
    case ButtonPress: 
      switch(btncode) {
        case 1: 
          lambda_mouse_handler(
            new long[5]{L_MOUSEDOWN, cursorx, cursory, L_MOUSE_BUTTON_LEFT, 0}
          );
          break;
        case 2: 
          lambda_mouse_handler(
            new long[5]{L_MOUSEDOWN, cursorx, cursory, L_MOUSE_BUTTON_MIDLLE, 0}
          );
          break;
        case 3: 
          lambda_mouse_handler(
            new long[5]{L_MOUSEDOWN, cursorx, cursory, L_MOUSE_BUTTON_RIGHT, 0}
          );
          break;
        case 4: 
          lambda_mouse_handler(
            new long[5]{L_MOUSEWHEEL, cursorx, cursory, 0, -1}
          ); 
          break; // scroll up
        case 5: 
          lambda_mouse_handler(
            new long[5]{L_MOUSEWHEEL, cursorx, cursory, 0, 1}
          ); 
          break; // scroll down
      }
      break;
    case ButtonRelease: 
      switch(btncode) {
        case 1: 
          lambda_mouse_handler(
            new long[5]{L_MOUSEUP, cursorx, cursory, L_MOUSE_BUTTON_LEFT, 0}
          );
          break;
        case 2: 
          lambda_mouse_handler(
            new long[5]{L_MOUSEUP, cursorx, cursory, L_MOUSE_BUTTON_MIDLLE, 0}
          );
          break;
        case 3: 
          lambda_mouse_handler(
            new long[5]{L_MOUSEUP, cursorx, cursory, L_MOUSE_BUTTON_RIGHT, 0}
          );
          break;
        case 4: break; // scroll up
        case 5: break; // scroll down
      }
      break;
    case MotionNotify: 
      cursorx = rootx;
      cursory = rooty;
      lambda_mouse_handler(
        new long[5]{L_MOUSEMOVE, cursorx, cursory, 0, 0}
      );
      break;
  }
  XRecordFreeData(hook);
}

namespace listener_auto {
  Listener::Listener(std::function<void(long*)> const& mlambda, std::function<void(long*)> const& klambda) {
    lambda_mouse_handler = mlambda;
    lambda_keyboard_handler = klambda;

    ctrl_display = XOpenDisplay(NULL);
    data_display = XOpenDisplay(NULL);
    if (!ctrl_display || !data_display) {
      // error occur
      exit(1);
    }
    XSynchronize(ctrl_display, true);
    
    int major, minor;
    if (!XRecordQueryVersion(ctrl_display, &major, &minor)) {
      exit(2);
    }

    XRecordRange* record_range;
    XRecordClientSpec record_client_spec;
    XRecordContext record_context;
    record_range = XRecordAllocRange();
    if (!record_range) {
      exit(3);
    }
    record_range->device_events.first = KeyPress;
    record_range->device_events.last = MotionNotify;
    record_client_spec = XRecordAllClients;
    record_context = XRecordCreateContext(ctrl_display, 0, &record_client_spec, 1, &record_range, 1);
    if (!record_context) {
      exit(4);
    }
    if (!XRecordEnableContextAsync(data_display, record_context, callback, NULL)) {
      exit(5);
    }
    while (true) {
      XRecordProcessReplies(data_display);
      if (stop) {
        break;
      }
    }
    XRecordDisableContext(ctrl_display, record_context);
    XRecordFreeContext(ctrl_display, record_context);
    XFree(record_range);
    XCloseDisplay(data_display);
    XCloseDisplay(ctrl_display);
  }
  Listener::~Listener() {}
  void Listener::close() {
    stop = 1;
  }
}