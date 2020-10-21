#pragma once
#ifndef _LISTENER_WRAPPER
#define _LISTENER_WRAPPER

#include <napi.h>
#include <chrono>
#include <thread>
#include <map>
#include "../listener.h"

namespace Listener {
  Napi::Value initListener(const Napi::CallbackInfo& info);
  Napi::Value releaseListener(const Napi::CallbackInfo& info);
  Napi::Object initMethods(Napi::Env env, Napi::Object exports);
}

#endif
