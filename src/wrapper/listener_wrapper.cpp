#include "listener_wrapper.h"

std::thread nativeThread;
Napi::ThreadSafeFunction tsfn;
int threadId = 0;
listener_auto::Listener* listener_ptr = NULL;

Napi::Value Listener::initListener(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  // input check
  if (info.Length() < 1) {
    throw Napi::Error::New(env, "param callback required");
  } else if (!info[0].IsFunction()) {
    throw Napi::TypeError::New(env, "expect callback to be a function");
  }

  tsfn = Napi::ThreadSafeFunction::New(env, info[0].As<Napi::Function>(), "tsfn", 0, 1, [](Napi::Env) {
    nativeThread.join();
  });
  
  nativeThread = std::thread([] () {
#if _WIN32 == 1
    threadId = GetCurrentThreadId();
#endif
    const std::string event{"event"};
    const std::string x{"x"};
    const std::string y{"y"};
    const std::string button{"button"};
    const std::string direction{"direction"};
    const std::string scanCode{"scanCode"};
    const std::string vkCode{"vkCode"};

    auto callback = [=](Napi::Env env, Napi::Function jsCallback, long* value) {
      Napi::Object obj = Napi::Object::New(env);
      obj.Set(Napi::String::New(env, event), Napi::Number::New(env, (double)value[0]));
          
      switch (value[0]) {
        case L_KEYDOWN:
        case L_KEYUP: 
          obj.Set(Napi::String::New(env, vkCode), Napi::Number::New(env, (double)value[1]));
          obj.Set(Napi::String::New(env, scanCode), Napi::Number::New(env, (double)value[2]));
          break;
        default: 
          obj.Set(Napi::String::New(env, x), Napi::Number::New(env, (double)value[1]));
          obj.Set(Napi::String::New(env, y), Napi::Number::New(env, (double)value[2]));
          obj.Set(Napi::String::New(env, button), Napi::Number::New(env, (double)value[3]));
          obj.Set(Napi::String::New(env, direction), Napi::Number::New(env, (double)value[4]));
      }
      jsCallback.Call({
        // Napi::Number::New(env, *value)
        obj
      });
      delete value;
    };
    auto mouse_handler = [=](long* value) {
      tsfn.BlockingCall(value, callback);
    };
    auto keyboard_handler = [=](long* value) {
      tsfn.BlockingCall(value, callback);
    };

    listener_ptr = new listener_auto::Listener(mouse_handler, keyboard_handler);
    // while(true) {
    //   double* value = new double(1000);
    //   napi_status status = tsfn.BlockingCall(value, callback);
    //   // if (status != napi_ok) {
    //   //   break;
    //   // }
    //   std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
  });
  return env.Undefined();
}
Napi::Value Listener::releaseListener(const Napi::CallbackInfo& info) {
#if _WIN32 == 1
  PostThreadMessageA(threadId, WM_QUIT, 0, 0);
#elif __linux == 1
  listener_ptr->close();
#endif
  delete listener_ptr;
  tsfn.Release();
  return info.Env().Undefined();
}
Napi::Value Listener::setBlock(const Napi::CallbackInfo& info) {
  listener_ptr->setBlock(info[0].As<Napi::Boolean>().ToBoolean());
  return info.Env().Undefined();
}

Napi::Object Listener::initMethods(Napi::Env env, Napi::Object exports) {
  exports.Set("initListener", Napi::Function::New(env, Listener::initListener));
  exports.Set("releaseListener", Napi::Function::New(env, Listener::releaseListener));
  exports.Set("setBlock", Napi::Function::New(env, Listener::setBlock));
  return exports;
}