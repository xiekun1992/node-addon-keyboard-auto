#include "keycode_wrapper.h"

keycode_auto::Keycode kc;
namespace Keycode {
  Napi::Number charToKeycode(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1) {
      throw Napi::Error::New(env, "param keystr required");
    } else if (!info[0].IsString()) {
      throw Napi::TypeError::New(env, "expect keystr to be type of string");
    }
    int keycode = kc.charToKeycode(info[0].As<Napi::String>().ToString());
    return Napi::Number::New(env, keycode);
  }
  Napi::String keycodeToChar(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1) {
      throw Napi::Error::New(env, "param keycode required");
    } else if (!info[0].IsNumber()) {
      throw Napi::TypeError::New(env, "expect keycode to be type of number");
    }
    string keystr = kc.keycodeToChar(info[0].As<Napi::Number>().Int32Value());
    return Napi::String::New(env, keystr);
  }
  Napi::Object initMethods(Napi::Env env, Napi::Object exports) {
    exports.Set("charToKeycode", Napi::Function::New(env, Keycode::charToKeycode));
    exports.Set("keycodeToChar", Napi::Function::New(env, Keycode::keycodeToChar));
    return exports;
  }
}