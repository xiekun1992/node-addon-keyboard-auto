#pragma once
#ifndef _NODE_ADDON_MOUSE_AUTO
#define _NODE_ADDON_MOUSE_AUTO

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#if __linux == 1

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>

#endif

namespace mouse_auto {
  class Mouse {
    private:
#if __linux == 1
      Display* display;
      Window root;
#endif
    public:
      Mouse();
      ~Mouse();
      void mouse_move(int x, int y);
      void mouse_down(int button);
      void mouse_up(int button);
      void mouse_wheel(int direction);
  };
}

#endif