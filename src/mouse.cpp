#include "mouse.h"

namespace mouse_auto {
  Mouse::Mouse() {

  }
  Mouse::~Mouse() {

  }
  void Mouse::mouse_move(int x, int y) {
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
  }
  void Mouse::mouse_wheel(int direction) {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.mouseData = direction > 0 ? WHEEL_DELTA : -1 * WHEEL_DELTA;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL | MOUSEEVENTF_ABSOLUTE;
    input.mi.dx = 0;
    input.mi.dy = 0;
    SendInput(1, &input, sizeof(INPUT));
  }
  void Mouse::mouse_down(int button) {
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
  }
  void Mouse::mouse_up(int button) {
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
  }
}