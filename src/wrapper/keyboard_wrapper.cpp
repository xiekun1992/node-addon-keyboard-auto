#include "keyboard_wrapper.h"

keyboard_auto::Keyboard kb;

// Napi::Value Keyboard::init(const Napi::CallbackInfo& info) {
//   display = XOpenDisplay(NULL);
//   return info.Env().Undefined();
// }
// Napi::Value Keyboard::destroy(const Napi::CallbackInfo& info) {
//   XCloseDisplay(display);
//   return info.Env().Undefined();
// }
Napi::Value Keyboard::keydown(const Napi::CallbackInfo& info) {
  if (info.Length() < 1) {
    Napi::Error::New(info.Env(), "param keystr expected").ThrowAsJavaScriptException();
  }
  string keystr = info[0].As<Napi::String>().ToString();
  return Napi::Boolean::New(info.Env(), kb.keydown(keystr));
}
Napi::Value Keyboard::keyup(const Napi::CallbackInfo& info) {
  if (info.Length() < 1) {
    Napi::Error::New(info.Env(), "param keystr expected").ThrowAsJavaScriptException();
  }
  string keystr = info[0].As<Napi::String>().ToString();
  return Napi::Boolean::New(info.Env(), kb.keyup(keystr));
}

Napi::Object Keyboard::initMethods(Napi::Env env, Napi::Object exports) {
  // exports.Set("init", Napi::Function::New(env, Keyboard::init));
  // exports.Set("destroy", Napi::Function::New(env, Keyboard::destroy));
  exports.Set("keydown", Napi::Function::New(env, Keyboard::keydown));
  exports.Set("keyup", Napi::Function::New(env, Keyboard::keyup));
  return exports;
}