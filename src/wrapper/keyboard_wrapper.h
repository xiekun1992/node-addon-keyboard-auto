#pragma once
#ifndef _KEYBOARD_WRAPPER
#define _KEYBOARD_WRAPPER

#include <napi.h>
#include "../keycode.h"
#include "../keyboard.h"

namespace Keyboard {
  Napi::Value keydown(const Napi::CallbackInfo& info);
  Napi::Value keyup(const Napi::CallbackInfo& info);
  Napi::Object initMethods(Napi::Env env, Napi::Object exports);
}

#endif