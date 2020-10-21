#include <napi.h>
#include "keyboard_wrapper.h"
#include "listener_wrapper.h"
#include "mouse_wrapper.h"
#include "keycode_wrapper.h"


Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  Mouse::initMethods(env, exports);
  Listener::initMethods(env, exports);
  Keyboard::initMethods(env, exports);
  Keycode::initMethods(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);