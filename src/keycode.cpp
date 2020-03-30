#include "keycode.h"

namespace Keycode {
  Keycode::Keycode() {
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
}