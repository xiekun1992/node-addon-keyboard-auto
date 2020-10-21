#include "mouse_wrapper.h"

mouse_auto::Mouse mouse;
namespace Mouse {
  Napi::Value mouse_move(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2) {
      throw Napi::Error::New(env, "params x and y required");
    } else if (!info[0].IsNumber() || !info[1].IsNumber()) {
      throw Napi::TypeError::New(env, "expect x and y to be type of number");
    }
    mouse.mouse_move(
      info[0].As<Napi::Number>().Int32Value(),
      info[1].As<Napi::Number>().Int32Value()
    );
    return env.Undefined();
  }
  Napi::Value mouse_wheel(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1) {
      throw Napi::Error::New(env, "param direction required");
    } else if (!info[0].IsNumber()) {
      throw Napi::TypeError::New(env, "expect direction to be type of number");
    }
    mouse.mouse_wheel(info[0].As<Napi::Number>().Int32Value());
    return env.Undefined();
  }
  Napi::Value mouse_down(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1) {
      throw Napi::Error::New(env, "param button required");
    } else if (!info[0].IsNumber()) {
      throw Napi::TypeError::New(env, "expect button to be type of number");
    }
    mouse.mouse_down(info[0].As<Napi::Number>().Int32Value());
    return env.Undefined();
  }
  Napi::Value mouse_up(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1) {
      throw Napi::Error::New(env, "param button required");
    } else if (!info[0].IsNumber()) {
      throw Napi::TypeError::New(env, "expect button to be type of number");
    }
    mouse.mouse_up(info[0].As<Napi::Number>().Int32Value());
    return env.Undefined();
  }
  Napi::Object initMethods(Napi::Env env, Napi::Object exports) {
    exports.Set("mousemove", Napi::Function::New(env, Mouse::mouse_move));
    exports.Set("mousewheel", Napi::Function::New(env, Mouse::mouse_wheel));
    exports.Set("mousedown", Napi::Function::New(env, Mouse::mouse_down));
    exports.Set("mouseup", Napi::Function::New(env, Mouse::mouse_up));
    return exports;
  }
}