#pragma once
#ifndef _NODE_ADDON_MOUSE_AUTO
#define _NODE_ADDON_MOUSE_AUTO

#include <windows.h>
#include <stdio.h>

namespace mouse_auto {
  class Mouse {
    public:
      Mouse();
      ~Mouse();
      void mouse_move(int x, int y);
      void mouse_wheel(int direction);
      void mouse_down(int button);
      void mouse_up(int button);
  };
}

#endif
