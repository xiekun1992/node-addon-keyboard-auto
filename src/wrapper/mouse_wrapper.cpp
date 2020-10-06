#include "mouse_wrapper.h"

mouse_auto::Mouse m;

Napi::Value Mouse::mouse_move(const Napi::CallbackInfo& info) {
  if (info.Length() < 2) {
    Napi::Error::New(info.Env(), "params x and y required").ThrowAsJavaScriptException();
  }
  int x = info[0].As<Napi::Number>().Int32Value();
  int y = info[1].As<Napi::Number>().Int32Value();
  m.mouse_move(x, y);
  return info.Env().Undefined();
}
Napi::Value Mouse::mouse_down(const Napi::CallbackInfo& info) {
  if (info.Length() < 1) {
    Napi::Error::New(info.Env(), "param button required").ThrowAsJavaScriptException();
  }
  int button = info[0].As<Napi::Number>().Int32Value();
  m.mouse_down(button);
  return info.Env().Undefined();
}
Napi::Value Mouse::mouse_up(const Napi::CallbackInfo& info) {
  if (info.Length() < 1) {
    Napi::Error::New(info.Env(), "param button required").ThrowAsJavaScriptException();
  }
  int button = info[0].As<Napi::Number>().Int32Value();
  m.mouse_up(button);
  return info.Env().Undefined();
}
Napi::Value Mouse::mouse_wheel(const Napi::CallbackInfo& info) {
  if (info.Length() < 1) {
    Napi::Error::New(info.Env(), "param button required").ThrowAsJavaScriptException();
  }
  int direction = info[0].As<Napi::Number>().Int32Value();
  m.mouse_wheel(direction);
  return info.Env().Undefined();
}
Napi::Object Mouse::initMethods(Napi::Env env, Napi::Object exports) {
  exports.Set("mousemove", Napi::Function::New(env, Mouse::mouse_move));
  exports.Set("mousedown", Napi::Function::New(env, Mouse::mouse_down));
  exports.Set("mouseup", Napi::Function::New(env, Mouse::mouse_up));
  exports.Set("mousewheel", Napi::Function::New(env, Mouse::mouse_wheel));
  return exports;
}