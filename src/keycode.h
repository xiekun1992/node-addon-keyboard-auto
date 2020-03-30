#pragma once
#ifndef _NODE_ADDON_KEYBOARD_AUTO_KEYCODE
#define _NODE_ADDON_KEYBOARD_AUTO_KEYCODE

#include <iostream>
#include <map>
#include <string>
#include <X11/keysym.h>
using namespace std;

namespace Keycode {
  class Keycode {
    public: 
      Keycode();
      ~Keycode();
      int charToKeycode(string str);
    private:
      map<string, int> keymap;
  };
}

#endif