#include "listener.h"

std::function<void(long*)> lambda_mouse_handler;
std::function<void(long*)> lambda_keyboard_handler;

LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
  PKBDLLHOOKSTRUCT hookStruct = (PKBDLLHOOKSTRUCT)lParam;
  switch (wParam) {
    case WM_KEYDOWN: 
      lambda_keyboard_handler(
        new long[3]{L_KEYDOWN, (long)hookStruct->vkCode, (long)hookStruct->scanCode}
      );
      break;
    case WM_KEYUP: 
      lambda_keyboard_handler(
        new long[3]{L_KEYUP, (long)hookStruct->vkCode, (long)hookStruct->scanCode}
      );
      break;
  }
  // printf("%ld %ld %ld\n", wParam, hookStruct->vkCode, hookStruct->scanCode);
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}
LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
  // Get event information
  PMSLLHOOKSTRUCT p = (PMSLLHOOKSTRUCT)lParam;
  long mouseData = p->mouseData;
  switch (wParam) {
    case WM_MOUSEWHEEL: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEWHEEL, (long)p->pt.x, (long)p->pt.y, 0, (long)(mouseData >> 16)}
      );
      break;
    case WM_MOUSEMOVE: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEMOVE, (long)p->pt.x, (long)p->pt.y, 0, (long)(mouseData >> 16)}
      );
      break;
    case WM_LBUTTONDOWN: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEDOWN, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_LEFT, (long)(mouseData >> 16)}
      );
      break;
    case WM_LBUTTONUP: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEUP, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_LEFT, (long)(mouseData >> 16)}
      );
      break;
    case WM_RBUTTONDOWN: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEDOWN, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_RIGHT, (long)(mouseData >> 16)}
      );
      break;
    case WM_RBUTTONUP: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEUP, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_RIGHT, (long)(mouseData >> 16)}
      );
      break;
    case WM_MBUTTONDOWN: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEDOWN, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_MIDLLE, (long)(mouseData >> 16)}
      );
      break;
    case WM_MBUTTONUP: 
      lambda_mouse_handler(
        new long[5]{L_MOUSEUP, (long)p->pt.x, (long)p->pt.y, L_MOUSE_BUTTON_MIDLLE, (long)(mouseData >> 16)}
      );
      break;
  }
  // printf("%ld %lf", p->mouseData, p->mouseData >> 16);
  // printf("%ld  %ld  %ld  %ld\n", wParam, p->mouseData, p->pt.x, p->pt.y);
  //    SetCursorPos(
  //        /* X */ int(screen_centre_x + cos(angle) * 300),/* Y */ int(screen_centre_y + sin(angle) * 300)
  //    );
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}
namespace listener_auto {
  Listener::Listener(std::function<void(long*)> const& mlambda, std::function<void(long*)> const& klambda) {
    lambda_mouse_handler = mlambda;
    lambda_keyboard_handler = klambda;
    mouseHook = SetWindowsHookEx(
        WH_MOUSE_LL,/* Type of hook */
        mouseHookProc,/* Hook process */
        NULL,/* Instance */
        NULL);
    keyboardHook = SetWindowsHookEx(
        WH_KEYBOARD_LL,
        keyboardHookProc,
        NULL,
        NULL
    );
    // https://stackoverflow.com/questions/4509521/does-getmessage-need-a-gui
    // MSG msg;
    // PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);
    // http://www.winprog.org/tutorial/message_loop.html
    // message loop check, without this, hooks won't work
    MSG Msg;
		while (GetMessage(&Msg, NULL, 0, 0) > 0)
		{
      if (Msg.message == WM_QUIT) {
        break;
      }
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
  }
  Listener::~Listener() {
    // PostQuitMessage(0);
    UnhookWindowsHookEx(mouseHook);
    UnhookWindowsHookEx(keyboardHook);
  }
}
