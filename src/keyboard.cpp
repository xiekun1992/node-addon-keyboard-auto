#include "keyboard.h"
#include "keycode.h"

Display* display;
Keycode::Keycode kc;

Napi::Value Keyboard::init(const Napi::CallbackInfo& info) {
  display = XOpenDisplay(NULL);
  return info.Env().Undefined();
}
Napi::Value Keyboard::destroy(const Napi::CallbackInfo& info) {
  XCloseDisplay(display);
  return info.Env().Undefined();
}
Napi::Value Keyboard::keydown(const Napi::CallbackInfo& info) {
  if (info.Length() < 1) {
    Napi::Error::New(info.Env(), "param keycode expected").ThrowAsJavaScriptException();
  }
  string keystr = info[0].As<Napi::String>().ToString();
  int code = kc.charToKeycode(keystr);
  if (code > 0) {
    unsigned int keycode = XKeysymToKeycode(display, code);
    XTestFakeKeyEvent(display, keycode, True, 0);
    XFlush(display);
    return Napi::Boolean::New(info.Env(), true);
  }
  return Napi::Boolean::New(info.Env(), false);
}
Napi::Value Keyboard::keyup(const Napi::CallbackInfo& info) {
  if (info.Length() < 1) {
    Napi::Error::New(info.Env(), "param keycode expected").ThrowAsJavaScriptException();
  }
  string keystr = info[0].As<Napi::String>().ToString();
  int code = kc.charToKeycode(keystr);
  if (code > 0) {
    unsigned int keycode = XKeysymToKeycode(display, code);
    XTestFakeKeyEvent(display, keycode, False, 0);
    XFlush(display);
    return Napi::Boolean::New(info.Env(), true);
  }
  return Napi::Boolean::New(info.Env(), false);
}

Napi::Object Keyboard::initMethods(Napi::Env env, Napi::Object exports) {
  exports.Set("init", Napi::Function::New(env, Keyboard::init));
  exports.Set("destroy", Napi::Function::New(env, Keyboard::destroy));
  exports.Set("keydown", Napi::Function::New(env, Keyboard::keydown));
  exports.Set("keyup", Napi::Function::New(env, Keyboard::keyup));
  return exports;
}