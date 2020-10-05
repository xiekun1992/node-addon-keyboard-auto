#pragma once

#ifndef _NODE_ADDON_LISTENER
#define _NODE_ADDON_LISTENER


#include <stdio.h>
#include <functional>
#include <chrono>
#include <thread>
#if _WIN32 == 1
#include <windows.h>
#endif

#define L_MOUSEWHEEL            0
#define L_MOUSEMOVE             1
#define L_MOUSEDOWN             2
#define L_MOUSEUP               3
#define L_KEYDOWN               4
#define L_KEYUP                 5

#define L_MOUSE_BUTTON_LEFT     1
#define L_MOUSE_BUTTON_MIDLLE   2
#define L_MOUSE_BUTTON_RIGHT    3

namespace listener_auto {
  class Listener {
    private:
      HHOOK mouseHook;
      HHOOK keyboardHook;
      // static LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);
      // static LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
    public:
      Listener(std::function<void(long*)> const& mlambda, std::function<void(long*)> const& klambda);
      ~Listener();
      void close();
  };
}

#endif