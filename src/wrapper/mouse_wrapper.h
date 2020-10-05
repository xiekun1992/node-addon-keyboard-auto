#pragma once

#ifndef _MOUSE_WRAPPER
#define _MOUSE_WRAPPER

#include <napi.h>
#include <windows.h>
#include "../mouse.h"

namespace Mouse {
  Napi::Value mouse_move(const Napi::CallbackInfo& info);
  Napi::Value mouse_wheel(const Napi::CallbackInfo& info);
  Napi::Value mouse_down(const Napi::CallbackInfo& info);
  Napi::Value mouse_up(const Napi::CallbackInfo& info);
  Napi::Object initMethods(Napi::Env env, Napi::Object exports);
}

#endif