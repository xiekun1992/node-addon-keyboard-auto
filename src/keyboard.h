#pragma once
#ifndef _NODE_ADDON_KEYBOARD_AUTO
#define _NODE_ADDON_KEYBOARD_AUTO

#include <napi.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

namespace Keyboard {
  Napi::Value init(const Napi::CallbackInfo& info);
  Napi::Value destroy(const Napi::CallbackInfo& info);
  Napi::Value keydown(const Napi::CallbackInfo& info);
  Napi::Value keyup(const Napi::CallbackInfo& info);
  Napi::Object initMethods(Napi::Env env, Napi::Object exports);
}

#endif