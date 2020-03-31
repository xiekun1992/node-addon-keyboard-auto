#include "keyboard.h"

namespace keyboard_auto {
  Keyboard::Keyboard() {
#if __linux == 1
    display = XOpenDisplay(NULL);
#elif _WIN32 == 1
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wScan = 0;
#endif
  }
  Keyboard::~Keyboard() {
#if __linux == 1
    XCloseDisplay(display);
    display = NULL;
#elif _WIN32 == 1
#endif
  }
  bool Keyboard::keydown(string keystr) {
    int code = kc.charToKeycode(keystr);
    if (code > 0) {
#if __linux == 1
      unsigned int keycode = XKeysymToKeycode(display, code);
      XTestFakeKeyEvent(display, keycode, True, 0);
      XFlush(display);
#elif _WIN32 == 1
      ip.ki.dwFlags = 0 | KEYEVENTF_EXTENDEDKEY;
      if (code == 65535) {
        ip.ki.wVk = VkKeyScanEx(keystr.at(0), kbl);;
      } else {
        ip.ki.wVk = code;
      }
	    SendInput(1, &ip, sizeof(INPUT));
#endif
      return true;
    }
    return false;
  }
  bool Keyboard::keyup(string keystr) {
    int code = kc.charToKeycode(keystr);
    if (code > 0) {
#if __linux == 1
      unsigned int keycode = XKeysymToKeycode(display, code);
      XTestFakeKeyEvent(display, keycode, False, 0);
      XFlush(display);
#elif _WIN32 == 1
      ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_EXTENDEDKEY;
      if (code == 65535) {
        ip.ki.wVk = VkKeyScanEx(keystr.at(0), kbl);;
      } else {
        ip.ki.wVk = code;
      }
      SendInput(1, &ip, sizeof(INPUT));
#endif
      return true;
    }
    return false;
  }
}