{
  "targets": [
    {
      # 不要用'-'命名，不然会报<command-line>: error: expected initializer before ‘-’ token的错误
      "target_name": "keyboard_auto",
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "sources": [
        "src/keyboard.cpp", 
        "src/keycode.cpp",
        "src/listener.cpp",
        "src/mouse.cpp",
        "src/wrapper/wrapper.cpp",
        "src/wrapper/keyboard_wrapper.cpp",
        "src/wrapper/listener_wrapper.cpp",
        "src/wrapper/mouse_wrapper.cpp"
      ],
      "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")"],
      "dependecies": ["<!(node -p \"require('node-addon-api').gyp\")"],
      "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
      "conditions": [
        [
          "OS == 'linux'", {
            "link_settings": {
              "libraries": ["-lX11", "-lXtst", "-lstdc++", "-lXext"]
            }
          }
        ]
      ]
    }
  ] 
}