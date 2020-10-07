#pragma once
#ifndef _NODE_ADDON_KEYBOARD_AUTO_KEYCODE
#define _NODE_ADDON_KEYBOARD_AUTO_KEYCODE

#include <iostream>
#include <map>
#include <string>
#if __linux == 1

#include <X11/keysym.h>

#elif _WIN32 == 1

#include <windows.h>

#endif
using namespace std;

namespace keycode_auto {
  class Keycode {
    public: 
      Keycode();
      ~Keycode();
      int charToKeycode(string str);
      string keycodeToChar(int keycode);
    private:
      map<string, int> keymap;
  };
}

#endif