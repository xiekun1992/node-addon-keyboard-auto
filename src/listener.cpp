#include "listener.h"

std::function<void(long*)> lambda_mouse_handler;
std::function<void(long*)> lambda_keyboard_handler;

#if _WIN32 == 1

LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
  PKBDLLHOOKSTRUCT hookStruct = (PKBDLLHOOKSTRUCT)lParam;
  switch (wParam) {
    case WM_KEYDOWN: 
      lambda_keyboard_handler(
        new long[3]{L_KEYDOWN, (long)hookStruct->vkCode, (long)hookStruct->scanCode}
      );
      break;
    case WM_KEYUP: 
      lambda_keyboard_handler(
        new long[3]{L_KEYUP, (long)hookStruct->vkCode, (long)hookStruct->scanCode}
      );
      break;
  }
  // printf("%ld %ld %ld\n", wParam, hookStruct->vkCode, hookStruct->scanCode);
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}
LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
  // Get event information
  PMSLLHOOKSTRUCT p = (PMSLLHOOKSTRUCT)lParam;
  long mouseData = p->mouseData;
  switch (wParam) {
    case WM_MOUSEWHEEL: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEWHEEL, (long)p->pt.x, (long)p->pt.y, 0, (long)(mouseData >> 16)}
      );
      break;
    case WM_MOUSEMOVE: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEMOVE, (long)p->pt.x, (long)p->pt.y, 0, (long)(mouseData >> 16)}
      );
      break;
    case WM_LBUTTONDOWN: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEDOWN, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_LEFT, (long)(mouseData >> 16)}
      );
      break;
    case WM_LBUTTONUP: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEUP, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_LEFT, (long)(mouseData >> 16)}
      );
      break;
    case WM_RBUTTONDOWN: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEDOWN, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_RIGHT, (long)(mouseData >> 16)}
      );
      break;
    case WM_RBUTTONUP: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEUP, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_RIGHT, (long)(mouseData >> 16)}
      );
      break;
    case WM_MBUTTONDOWN: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEDOWN, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_MIDLLE, (long)(mouseData >> 16)}
      );
      break;
    case WM_MBUTTONUP: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEUP, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_MIDLLE, (long)(mouseData >> 16)}
      );
      break;
  }
  // printf("%ld %lf", p->mouseData, p->mouseData >> 16);
  // printf("%ld  %ld  %ld  %ld\n", wParam, p->mouseData, p->pt.x, p->pt.y);
  //    SetCursorPos(
  //        /* X */ int(screen_centre_x + cos(angle) * 300),/* Y */ int(screen_centre_y + sin(angle) * 300)
  //    );
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}
#elif __linux == 1
Display* data_display = NULL;
Display* ctrl_display = NULL;
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
        new long[3]{L_KEYDOWN, (long)XStringToKeysym(XKeysymToString(XKeycodeToKeysym(ctrl_display, keycode, 0))), 0}
      ); 
      break;
    case KeyRelease: 
      lambda_keyboard_handler(
        new long[3]{L_KEYUP, (long)XStringToKeysym(XKeysymToString(XKeycodeToKeysym(ctrl_display, keycode, 0))), 0}
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
#endif

namespace listener_auto {
  Listener::Listener(std::function<void(long*)> const& mlambda, std::function<void(long*)> const& klambda) {
    lambda_mouse_handler = mlambda;
    lambda_keyboard_handler = klambda;
#if _WIN32 == 1
    mouseHook = SetWindowsHookEx(
        WH_MOUSE_LL,/* Type of hook */
        mouseHookProc,/* Hook process */
        NULL,/* Instance */
        NULL);
    keyboardHook = SetWindowsHookEx(
        WH_KEYBOARD_LL,
        keyboardHookProc,
        NULL,
        NULL
    );
    // https://stackoverflow.com/questions/4509521/does-getmessage-need-a-gui
    // MSG msg;
    // PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);
    // http://www.winprog.org/tutorial/message_loop.html
    // message loop check, without this, hooks won't work
    MSG Msg;
		while (GetMessage(&Msg, NULL, 0, 0) > 0)
		{
      if (Msg.message == WM_QUIT) {
        break;
      }
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
 #elif __linux == 1
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
      usleep(100); // reduce cpu overhead
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
 #endif
  }
  Listener::~Listener() {
    // PostQuitMessage(0);
#if _WIN32 == 1
    UnhookWindowsHookEx(mouseHook);
    UnhookWindowsHookEx(keyboardHook);
#endif
  }
  void Listener::close() {
#if __linux == 1
    stop = 1;
#endif
  }
}