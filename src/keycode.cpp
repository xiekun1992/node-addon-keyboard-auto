#include "keycode.h"

namespace keycode_auto {
  Keycode::Keycode() {
#if __linux == 1 
    keymap["a"] = XK_A;
    keymap["b"] = XK_B;
    keymap["c"] = XK_C;
    keymap["d"] = XK_D;
    keymap["e"] = XK_E;
    keymap["f"] = XK_F;
    keymap["g"] = XK_G;
    keymap["h"] = XK_H;
    keymap["i"] = XK_I;
    keymap["j"] = XK_J;
    keymap["k"] = XK_K;
    keymap["l"] = XK_L;
    keymap["m"] = XK_M;
    keymap["n"] = XK_N;
    keymap["o"] = XK_O;
    keymap["p"] = XK_P;
    keymap["q"] = XK_Q;
    keymap["r"] = XK_R;
    keymap["s"] = XK_S;
    keymap["t"] = XK_T;
    keymap["u"] = XK_U;
    keymap["v"] = XK_V;
    keymap["w"] = XK_W;
    keymap["x"] = XK_X;
    keymap["y"] = XK_Y;
    keymap["z"] = XK_Z;

    keymap["0"] = XK_0;
    keymap["1"] = XK_1;
    keymap["2"] = XK_2;
    keymap["3"] = XK_3;
    keymap["4"] = XK_4;
    keymap["5"] = XK_5;
    keymap["6"] = XK_6;
    keymap["7"] = XK_7;
    keymap["8"] = XK_8;
    keymap["9"] = XK_9;

    keymap["f1"] = XK_F1;
    keymap["f2"] = XK_F2;
    keymap["f3"] = XK_F3;
    keymap["f4"] = XK_F4;
    keymap["f5"] = XK_F5;
    keymap["f6"] = XK_F6;
    keymap["f7"] = XK_F7;
    keymap["f8"] = XK_F8;
    keymap["f9"] = XK_F9;
    keymap["f10"] = XK_F10;
    keymap["f11"] = XK_F11;
    keymap["f12"] = XK_F12;

    keymap["escape"] = XK_Escape;
    keymap["tab"] = XK_Tab;
    keymap["capslock"] = XK_Caps_Lock;
    keymap["shiftleft"] = XK_Shift_L;
    keymap["controlleft"] = XK_Control_L;
    keymap["meta"] = XK_Meta_L;
    // keymap["meta"] = XK_Super_L;
    keymap["altleft"] = XK_Alt_L;
    keymap["space"] = XK_space;
    keymap["altright"] = XK_Alt_R;
    keymap["controlright"] = XK_Control_R;
    keymap["shiftright"] = XK_Shift_R;
    keymap["printscreen"] = XK_Print;
    keymap["pause"] = XK_Pause;
    keymap["insert"] = XK_Insert;
    keymap["scrolllock"] = XK_Scroll_Lock;
    keymap["numlock"] = XK_Num_Lock;
    keymap["backspace"] = XK_BackSpace;
    keymap["delete"] = XK_Delete;
    keymap["enter"] = XK_Return;
    keymap["contextmenu"] = XK_Menu;

    keymap["`"] = XK_grave;
    keymap["~"] = XK_asciitilde;
    keymap["!"] = XK_exclam;
    keymap["@"] = XK_at;
    keymap["#"] = XK_numbersign;
    keymap["$"] = XK_dollar;
    keymap["%"] = XK_percent;
    keymap["^"] = XK_asciicircum;
    keymap["&"] = XK_ampersand;
    keymap["*"] = XK_asterisk;
    keymap["("] = XK_parenleft;
    keymap[")"] = XK_parenright;
    keymap["-"] = XK_minus;
    keymap["_"] = XK_underscore;
    keymap["="] = XK_equal;
    keymap["+"] = XK_plus;
    keymap["["] = XK_bracketleft;
    keymap["]"] = XK_bracketright;
    keymap["{"] = XK_braceleft;
    keymap["}"] = XK_braceright;
    keymap["\\"] = XK_backslash;
    keymap["|"] = XK_bar;
    keymap[";"] = XK_semicolon;
    keymap[":"] = XK_colon;
    keymap["'"] = XK_apostrophe;
    keymap["\""] = XK_quotedbl;
    keymap[","] = XK_comma;
    keymap["."] = XK_period;
    keymap["/"] = XK_slash;
    keymap["<"] = XK_less;
    keymap[">"] = XK_greater;
    keymap["?"] = XK_question;


    keymap["up"] = XK_Up;
    keymap["down"] = XK_Down;
    keymap["left"] = XK_Left;
    keymap["right"] = XK_Right;
    keymap["pageup"] = XK_Page_Up;
    keymap["pagedown"] = XK_Page_Down;
    keymap["home"] = XK_Home;
    keymap["end"] = XK_End;
#elif _WIN32 == 1
    keymap["a"] = 0x41;
    keymap["b"] = 0x42;
    keymap["c"] = 0x43;
    keymap["d"] = 0x44;
    keymap["e"] = 0x45;
    keymap["f"] = 0x46;
    keymap["g"] = 0x47;
    keymap["h"] = 0x48;
    keymap["i"] = 0x49;
    keymap["j"] = 0x4A;
    keymap["k"] = 0x4B;
    keymap["l"] = 0x4C;
    keymap["m"] = 0x4D;
    keymap["n"] = 0x4E;
    keymap["o"] = 0x4F;
    keymap["p"] = 0x50;
    keymap["q"] = 0x51;
    keymap["r"] = 0x52;
    keymap["s"] = 0x53;
    keymap["t"] = 0x54;
    keymap["u"] = 0x55;
    keymap["v"] = 0x56;
    keymap["w"] = 0x57;
    keymap["x"] = 0x58;
    keymap["y"] = 0x59;
    keymap["z"] = 0x5A;

    keymap["0"] = 0x30;
    keymap["1"] = 0x31;
    keymap["2"] = 0x32;
    keymap["3"] = 0x33;
    keymap["4"] = 0x34;
    keymap["5"] = 0x35;
    keymap["6"] = 0x36;
    keymap["7"] = 0x37;
    keymap["8"] = 0x38;
    keymap["9"] = 0x39;

    keymap["f1"] = VK_F1;
    keymap["f2"] = VK_F2;
    keymap["f3"] = VK_F3;
    keymap["f4"] = VK_F4;
    keymap["f5"] = VK_F5;
    keymap["f6"] = VK_F6;
    keymap["f7"] = VK_F7;
    keymap["f8"] = VK_F8;
    keymap["f9"] = VK_F9;
    keymap["f10"] = VK_F10;
    keymap["f11"] = VK_F11;
    keymap["f12"] = VK_F12;

    keymap["escape"] = VK_ESCAPE;
    keymap["tab"] = VK_TAB;
    keymap["capslock"] = VK_CAPITAL;
    keymap["shiftleft"] = VK_LSHIFT;
    keymap["controlleft"] = VK_LCONTROL;
    keymap["meta"] = VK_LWIN;
    keymap["altleft"] = VK_MENU;
    keymap["space"] = VK_SPACE;
    keymap["altright"] = VK_MENU;
    keymap["controlright"] = VK_RCONTROL;
    keymap["shiftright"] = VK_RSHIFT;
    keymap["printscreen"] = VK_SNAPSHOT;
    keymap["pause"] = VK_PAUSE;
    keymap["insert"] = VK_INSERT;
    keymap["scrolllock"] = VK_SCROLL;
    keymap["numlock"] = VK_NUMLOCK;
    keymap["backspace"] = VK_BACK;
    keymap["delete"] = VK_DELETE;
    keymap["enter"] = VK_RETURN;
    keymap["contextmenu"] = 93;//VK_RMENU;

    keymap["`"] = 192;
    keymap["~"] = 192;
    keymap["!"] = 65535;
    keymap["@"] = 65535;
    keymap["#"] = 65535;
    keymap["$"] = 65535;
    keymap["%"] = 65535;
    keymap["^"] = 65535;
    keymap["&"] = 65535;
    keymap["*"] = 65535;
    keymap["("] = 65535;
    keymap[")"] = 65535;
    keymap["-"] = 189;
    keymap["_"] = 189;
    keymap["="] = 187;
    keymap["+"] = 187;
    keymap["["] = 219;
    keymap["]"] = 221;
    keymap["{"] = 219;
    keymap["}"] = 221;
    keymap["\\"] = 220;
    keymap["|"] = 220;
    keymap[";"] = 186;
    keymap[":"] = 186;
    keymap["'"] = 222;
    keymap["\""] = 222;
    keymap[","] = 188;
    keymap["."] = 190;
    keymap["/"] = 191;
    keymap["<"] = 188;
    keymap[">"] = 190;
    keymap["?"] = 191;


    keymap["up"] = VK_UP;
    keymap["down"] = VK_DOWN;
    keymap["left"] = VK_LEFT;
    keymap["right"] = VK_RIGHT;
    keymap["pageup"] = VK_PRIOR;
    keymap["pagedown"] = VK_NEXT;
    keymap["home"] = VK_HOME;
    keymap["end"] = VK_END;
#endif
  }
  Keycode::~Keycode() {}
  int Keycode::charToKeycode(string str) {
    try {
      return keymap.at(str);
      // return keymap[str]; 
    } catch(const std::exception& e) {
      // std::cerr << e.what() << '\n';
      return -1;
    }
  }
  string Keycode::keycodeToChar(int keycode) {
    for (auto &i : keymap) {
      if (i.second == keycode) {
         return i.first;
      }
    }
  }
}