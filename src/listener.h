#pragma once

#ifndef _NODE_ADDON_LISTENER
#define _NODE_ADDON_LISTENER

#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <chrono>
#include <thread>

#if _WIN32 == 1

#include <windows.h>

#elif __linux == 1

#include <unistd.h>
#include <X11/Xlibint.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <X11/keysymdef.h>
#include <X11/keysym.h>
#include <X11/extensions/record.h>
#include <X11/extensions/XTest.h>

/* for this struct, refer to libxnee */
typedef union {
  unsigned char    type ;
  xEvent           event ;
  xResourceReq     req   ;
  xGenericReply    reply ;
  xError           error ;
  xConnSetupPrefix setup;
} XRecordDatum;

#endif

#define L_MOUSEWHEEL            0
#define L_MOUSEMOVE             1
#define L_MOUSEDOWN             2
#define L_MOUSEUP               3
#define L_KEYDOWN               4
#define L_KEYUP                 5
#define L_MOUSEMOVEREL          6

#define L_MOUSE_BUTTON_LEFT     1
#define L_MOUSE_BUTTON_MIDLLE   2
#define L_MOUSE_BUTTON_RIGHT    3

namespace listener_auto {
  class Listener {
    private:
#if _WIN32 == 1
      HHOOK mouseHook;
      HHOOK keyboardHook;
      // static LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);
      // static LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
#elif __linux == 1
      // Display* data_display = NULL;
      // Display* ctrl_display = NULL;
      // int stop = 0;
#endif
    public:
      Listener(std::function<void(long*)> const& mlambda, std::function<void(long*)> const& klambda);
      ~Listener();
      void close();
      void setBlock(bool block);
  };
}

#endif