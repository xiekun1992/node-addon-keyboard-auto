#pragma once

#ifndef _KEYCODE_WRAPPER
#define _KEYCODE_WRAPPER

#include <napi.h>
#include "../keycode.h"

namespace Keycode {
  Napi::Number charToKeycode(const Napi::CallbackInfo& info);
  Napi::String keycodeToChar(const Napi::CallbackInfo& info);
  Napi::Object initMethods(Napi::Env env, Napi::Object exports);
}

#endif