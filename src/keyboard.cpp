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
// #include "keycode.h"

// Display* display;
// Keycode::Keycode kc;

// Napi::Value Keyboard::init(const Napi::CallbackInfo& info) {
//   display = XOpenDisplay(NULL);
//   return info.Env().Undefined();
// }
// Napi::Value Keyboard::destroy(const Napi::CallbackInfo& info) {
//   XCloseDisplay(display);
//   return info.Env().Undefined();
// }
// Napi::Value Keyboard::keydown(const Napi::CallbackInfo& info) {
//   if (info.Length() < 1) {
//     Napi::Error::New(info.Env(), "param keycode expected").ThrowAsJavaScriptException();
//   }
//   string keystr = info[0].As<Napi::String>().ToString();
//   int code = kc.charToKeycode(keystr);
//   if (code > 0) {
//     unsigned int keycode = XKeysymToKeycode(display, code);
//     XTestFakeKeyEvent(display, keycode, True, 0);
//     XFlush(display);
//     return Napi::Boolean::New(info.Env(), true);
//   }
//   return Napi::Boolean::New(info.Env(), false);
// }
// Napi::Value Keyboard::keyup(const Napi::CallbackInfo& info) {
//   if (info.Length() < 1) {
//     Napi::Error::New(info.Env(), "param keycode expected").ThrowAsJavaScriptException();
//   }
//   string keystr = info[0].As<Napi::String>().ToString();
//   int code = kc.charToKeycode(keystr);
//   if (code > 0) {
//     unsigned int keycode = XKeysymToKeycode(display, code);
//     XTestFakeKeyEvent(display, keycode, False, 0);
//     XFlush(display);
//     return Napi::Boolean::New(info.Env(), true);
//   }
//   return Napi::Boolean::New(info.Env(), false);
// }

// Napi::Object Keyboard::initMethods(Napi::Env env, Napi::Object exports) {
//   exports.Set("init", Napi::Function::New(env, Keyboard::init));
//   exports.Set("destroy", Napi::Function::New(env, Keyboard::destroy));
//   exports.Set("keydown", Napi::Function::New(env, Keyboard::keydown));
//   exports.Set("keyup", Napi::Function::New(env, Keyboard::keyup));
//   return exports;
// }