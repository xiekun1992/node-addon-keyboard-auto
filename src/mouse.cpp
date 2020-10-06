#include "mouse.h"

namespace mouse_auto {
  Mouse::Mouse() {
    display = XOpenDisplay(0);
    root = DefaultRootWindow(display);
    printf("%ld", root);
  }
  Mouse::~Mouse() {
    printf("%ld", root);
    XCloseDisplay(display);
  }
  void Mouse::mouse_move(int x, int y) {
    // Display* display = XOpenDisplay(0);
    // Window root = DefaultRootWindow(display);
    // printf("%d", 1);
    // XTestFakeMotionEvent(display, 742, x, y, 0);
    // XFlush(display);
    XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
    XSync(display, false);
    // XSync(display, false);
    // XCloseDisplay(display);
  }
  void Mouse::mouse_down(int button) { // 1: left(Button1), 2: middle(Button2), 3: right(Button3)
    XTestFakeButtonEvent(display, button, true, 0);
    XFlush(display);
  }
  void Mouse::mouse_up(int button) {
    XTestFakeButtonEvent(display, button, false, 0);
    XFlush(display);
  }
  void Mouse::mouse_wheel(int direction) { // -1: up, 1: down
    int button;
    if (-1 == direction) {
      button = Button4;
    }
    if (1 == direction) {
      button = Button5;
    }
    XTestFakeButtonEvent(display, button, true, 0);
    XFlush(display);
    XTestFakeButtonEvent(display, button, false, 0);
    XFlush(display);
  }
}