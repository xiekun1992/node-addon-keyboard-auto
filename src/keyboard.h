#pragma once
#ifndef _NODE_ADDON_KEYBOARD_AUTO
#define _NODE_ADDON_KEYBOARD_AUTO

#include <stdio.h>
#include <iostream>
#include <string>
#include "keycode.h"
#if __linux == 1

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

#elif _WIN32 == 1

// #define WINVER 0x0500 // SendInput needs this
#include <windows.h>

#endif
namespace keyboard_auto {
  class Keyboard
  {
  private:
#if __linux == 1
    Display* display;
#elif _WIN32 == 1
    INPUT ip;
    HKL kbl = GetKeyboardLayout(0);
#endif
    keycode_auto::Keycode kc;
  public:
    Keyboard();
    ~Keyboard();
    bool keydown(string keystr);
    bool keyup(string keystr);
  };
}

#endif