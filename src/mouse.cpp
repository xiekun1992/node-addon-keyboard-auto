#include "mouse.h"

namespace mouse_auto {
  Mouse::Mouse() {
#if __linux == 1
    display = XOpenDisplay(0);
    root = DefaultRootWindow(display);
#endif
  }
  Mouse::~Mouse() {
#if __linux == 1
    XCloseDisplay(display);
#endif
  }
  void Mouse::mouse_move(int x, int y) {
#if _WIN32 == 1
    double fScreenWidth = (double)GetSystemMetrics(SM_CXSCREEN) - 1;
    double fScreenHeight = (double)GetSystemMetrics(SM_CYSCREEN) - 1;
    double fx = x * (65535.0f / fScreenWidth);
    double fy = y * (65535.0f / fScreenHeight);

    INPUT input;
    // https://stackoverflow.com/questions/17315672/screen-goes-black-when-i-use-sendinput-to-send-mouse-cursor-positions
    ZeroMemory(&input, sizeof(input));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    // printf("%d %d\n", fx, fy);
    input.mi.dx = fx;
    input.mi.dy = fy;
    SendInput(1, &input, sizeof(INPUT));
#elif __linux == 1
    XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
    XSync(display, false);
#endif
  }
  void Mouse::mouse_wheel(int direction) { // -1: up, 1: down
#if _WIN32 == 1
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.mouseData = direction > 0 ? WHEEL_DELTA : -1 * WHEEL_DELTA;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL | MOUSEEVENTF_ABSOLUTE;
    input.mi.dx = 0;
    input.mi.dy = 0;
    SendInput(1, &input, sizeof(INPUT));
#elif __linux == 1
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
#endif
  }
  void Mouse::mouse_down(int button) { // 1: left(Button1), 2: middle(Button2), 3: right(Button3)
#if _WIN32 == 1
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = 0;
    input.mi.dy = 0;
    switch (button) {
      case 1: input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE; break;
      case 2: input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_ABSOLUTE; break;
      case 3: input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_ABSOLUTE; break;
    }
    SendInput(1, &input, sizeof(INPUT));
#elif __linux == 1
    XTestFakeButtonEvent(display, button, true, 0);
    XFlush(display);
#endif
  }
  void Mouse::mouse_up(int button) {
#if _WIN32 == 1
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = 0;
    input.mi.dy = 0;
    switch (button) {
      case 1: input.mi.dwFlags = MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE; break;
      case 2: input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP | MOUSEEVENTF_ABSOLUTE; break;
      case 3: input.mi.dwFlags = MOUSEEVENTF_RIGHTUP | MOUSEEVENTF_ABSOLUTE; break;
    }
    SendInput(1, &input, sizeof(INPUT));
#elif __linux == 1
    XTestFakeButtonEvent(display, button, false, 0);
    XFlush(display);
#endif
  }
}