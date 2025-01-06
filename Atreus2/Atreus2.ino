/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-Escape-OneShot.h"

/* -*- mode: c++ -*-
 * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
 * defined as part of the USB HID Keyboard specification. You can find the names
 * (if not yet the explanations) for all the standard `Key_` defintions offered by
 * Kaleidoscope in these files:
 *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
 *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
 *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
 *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
 *
 * Additional things that should be documented here include:
 *   using ___ to let keypresses fall through to the previously active layer
 *   using XXX to mark a keyswitch as 'blocked' on this layer
 *   https://kaleidoscope.readthedocs.io/en/latest/customization/keycodes.html?highlight=LSHIFT#in-keymap-chorded-keys
 *     - In addition, the keys in key_defs_keyboard.h can be augmented with modifier macros:
 *     - LCTRL(), LSHIFT(), LALT(), LGUI() and RALT() to add chorded keys to your keymap.
 *     - For example LCTRL(LALT(Key_Delete))
*/



#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_LeftParen LSHIFT(Key_9)
#define Key_RightParen LSHIFT(Key_0)
#define Key_Plus LSHIFT(Key_Equals)
#define Key_Underscore LSHIFT(Key_Minus)
#define Key_Colon LSHIFT(Key_Semicolon)
#define Key_Tilde LSHIFT(Key_Backtick)

#define Key_PrevTrack Consumer_ScanPreviousTrack
#define Key_NextTrack Consumer_ScanNextTrack
#define Key_PlayPause Consumer_PlaySlashPause
#define Key_VolumeDown Consumer_VolumeDecrement
#define Key_VolumeUp Consumer_VolumeIncrement
#define Key_Mute Consumer_Mute
#define Key_RandomPlay Consumer_RandomPlay
#define Key_BSpc Key_Backspace
#define Key_VolUp Consumer_VolumeIncrement
#define Key_VolDn Consumer_VolumeDecrement
#define Key_LCBracket LSHIFT(Key_LeftBracket)
#define Key_RCBracket LSHIFT(Key_RightBracket)
#define Key_Star LSHIFT(Key_8)

#define Key_Up Key_UpArrow
#define Key_Down Key_DownArrow
#define Key_Left Key_LeftArrow
#define Key_Right Key_RightArrow

/* -*- mode: c++ -*-
 * QuKeys provides the following helpful shortcuts
 * CTL_T(key) - acts as left Control when held, or used in conjunction with other keys, but as key when tapped in isolation
 * ALT_T(key) - ... Alt ...
 * SFT_T(key) - ... Shift ...
 * GUI_T(key) - ... Super/Windows/Command ...
 * LT(layer, key) - ... [layer] ...
 * https://github.com/keyboardio/Kaleidoscope/blob/56fc62e8b3c88fb8cb2afbe9f9ac24d7d5902212/docs/plugins/Qukeys.md#dualuse-key-definitions
 */

enum {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOUSE,
  _FUNCTION,
  _PUNCNUMB,
  _NUMPAD,
  _BALANCED_SYMBOLS,
  _EMPTY
};

#define Key_MyHyper LCTRL(LALT(LSHIFT(Key_LeftGui)))
#define Key_Magic LCTRL(LALT(Key_LeftGui))
#define Key_CommandShift LSHIFT(Key_LeftGui)
#define Key_Meh LCTRL(LALT(Key_LeftShift))


/* *INDENT-OFF* */
KEYMAPS(
        [_QWERTY] = KEYMAP_STACKED
        (
         Key_Q,              Key_W,         Key_E,            Key_R,         Key_T,
         Key_A,              Key_S,         Key_D,            Key_F,         Key_G,
         Key_Z,              Key_X,         Key_C,            Key_V,         Key_B,         Key_Tab,
   OSL(_NUMPAD),        OSL(_MOUSE),  OSM(LeftGui),      Key_Esc,       Key_BSpc,     OSL(_PUNCNUMB),

                       Key_Y,         Key_U,            Key_I,         Key_O,         Key_P,
                       Key_H,         Key_J,            Key_K,         Key_L,         Key_Semicolon,
   Key_Enter,          Key_N,         Key_M,            Key_Comma,     Key_Period,    Key_Slash,
   OSL(_BALANCED_SYMBOLS),     Key_Space,     OSL(_PUNCNUMB),     Key_Minus,     Key_Quote,     OSL(_FUNCTION)
  ),

  [_LOWER] = KEYMAP_STACKED
  (
   // Left
   MoveToLayer(_QWERTY),              ___,           ___,                     ___,                  ___,
   ___,              ___,           ___,                     ___,                  ___,
   ___,              ___,           ___,                     ___,                  ___,              ___,
   ___,              ___,           ___,                     ___,                  ___,              OSM(LeftAlt),

   // right
   Key_Minus,      Key_LeftCurlyBracket,    Key_RightCurlyBracket,   Key_LeftBracket,  Key_RightBracket,
                    Key_LeftArrow,  Key_DownArrow,           Key_UpArrow,             Key_RightArrow,   Key_Backslash,
   ___,             Key_Plus,       Key_Tilde,               Key_RightParen,          Key_Backtick,     Key_Equals,
   ___,             Key_Space,      ___,                     ___,                     Key_Tilde,              ___
   ),

  [_RAISE] = KEYMAP_STACKED
  (
   // Left
   MoveToLayer(_QWERTY),           ___,       M(MACRO_VERSION_INFO),         /*Alfred hotkey*/ LGUI(LSHIFT(Key_Space)),              LGUI(Key_Backtick),
   Key_VolDn,        Key_VolUp,    Key_PrevTrack,       Key_PlayPause,       Key_NextTrack,
   ___,              ___,          ___,                 Key_Enter,                 Key_PageUp,        Key_RandomPlay,
   ___,              ___,          ___,                 Key_Esc,                 Key_Backspace,         Key_PageDown,

   // Right
                    ___,          ___,      ___,             ___,             ___,
                    ___,         ___,     ___,            Key_Tab,            ___,
   ___,             ___,         ___,                ___,                ___,              ___,
   ___,             ___,         ___,                ___,                ___,              ___
   ),

  [_MOUSE] = KEYMAP_STACKED
  (
   XXX,     Key_mouseScrollDn,            XXX,               XXX,               Key_mouseWarpEnd,
   XXX,     Key_mouseScrollUp,            XXX,               Key_mouseWarpNW,   Key_mouseWarpNE,
   XXX,     XXX,            XXX,               Key_mouseWarpSW,   Key_mouseWarpSE,  XXX,
   ___,     ___,            ___,               ___,               ___,              ___,

   XXX,            Key_mouseBtnL,     Key_mouseBtnM,     Key_mouseBtnR,     XXX,
   Key_mouseL,     Key_mouseDn,       Key_mouseUp,       Key_mouseR,        XXX,
   XXX,            XXX,               XXX,               XXX,               XXX,    XXX,
   ___,            ___,               ___,               ___,               ___,    ___
   ),

  [_FUNCTION] = KEYMAP_STACKED
  (
   // Left
   Key_F1,           Key_F2,       Key_F3,              Key_F4,              Key_F5,
   Key_F11,         Key_F12,     Key_F13,            Key_F14,            Key_F15,
   Key_F21,         Key_F22,     Key_F23,            Key_F24,                 ___,              ___,
   ___,              ___,           ___,                ___,                 ___,              ___,

   // right
                    Key_F6,          Key_F7,      Key_F8,             Key_F9,             Key_F10,
                    Key_F16,         Key_F17,     Key_F18,            Key_F19,            Key_F20,
   ___,             ___,         ___,                ___,                ___,              ___,
   ___,             ___,         ___,                ___,                ___,              ___
   ),

  [_PUNCNUMB] = KEYMAP_STACKED
  (
   // Left
   Key_1,              Key_2,           Key_3,                Key_4,                 Key_5,
   Key_Exclamation,    Key_At,          Key_Hash,             Key_Dollar,            Key_Percent,
   XXX,                XXX,             Key_Plus,             LSHIFT(Key_Quote),     Key_Quote,        Key_Backtick,
   Key_Equals,         XXX,             XXX,                  XXX,                   ___,              XXX,

   // right
                     Key_6,             Key_7,                Key_8,                Key_9,               Key_0,
                     Key_Caret,         Key_And,              Key_Star,             Key_LeftParen,       Key_RightParen,
   XXX,              Key_Minus,         Key_Underscore,       Key_Plus,             Key_Backtick,        Key_Backslash,
   XXX,              ___,               XXX,                  XXX,                  XXX,                 LSHIFT(Key_Backslash)
   ),

  [_NUMPAD] = KEYMAP_STACKED
  (
   // Left
   ___,              ___,           ___,                ___,                 ___,
   ___,              ___,           ___,                ___,                 ___,
   ___,              ___,           ___,                ___,                 ___,              ___,
   ___,              ___,           ___,                ___,                 ___,              ___,

   // right
   /*            */  ___,           Key_7,                Key_8,                Key_9,               Key_0,
   /*            */  ___,           Key_4,                Key_5,                Key_6,               Key_Colon,
   ___,              ___,           Key_1,                Key_2,                Key_3,               ___,
   ___,              ___,           ___,                  ___,                  Key_0,               ___
   ),

  [_BALANCED_SYMBOLS] = KEYMAP_STACKED
  (
   // Left
   ___,              ___,           ___,                ___,                 Key_Tilde,
   Key_And,              Key_Backtick,           Key_LeftBracket,                Key_LeftParen,                 Key_LeftCurlyBracket,
   ___,              ___,           ___,                ___,                 ___,              ___,
   ___,              ___,           ___,                ___,                 ___,              ___,

   // Right
   ___,           Key_Underscore,                Key_Tab,                ___,               LSHIFT(Key_Backslash),
   Key_RightCurlyBracket,           Key_RightParen,                Key_RightBracket,                Key_Equals,               Key_Backslash,
   ___,   ___,              Key_Plus,           Key_Minus,                Key_Star,                ___,               
   ___,              ___,           ___,                ___,                ___,               ___
   ),

  [_EMPTY] = KEYMAP_STACKED
  (
  // Left
    ___,              ___,           ___,                ___,                 ___,
    ___,              ___,           ___,                ___,                 ___,
    ___,              ___,           ___,                ___,                 ___,              ___,
    ___,              ___,           ___,                ___,                 ___,              ___,

  // Right
    /*            */  ___,           ___,                ___,                ___,               ___,
    /*            */  ___,           ___,                ___,                ___,               ___,
    ___,              ___,           ___,                ___,                ___,               ___,
    ___,              ___,           ___,                ___,                ___,               ___
  )
)
/* *INDENT-ON* */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_QWERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(_QWERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(_QWERTY);
    break;
  case MACRO_VERSION_INFO:
    Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

KALEIDOSCOPE_INIT_PLUGINS(
                          Qukeys,
                          EEPROMSettings,
                          Focus,
                          FocusEEPROMCommand,
                          FocusSettingsCommand,
                          OneShot,
                          EscapeOneShot,
                          MouseKeys,
                          Macros
                          );

void setup() {
  Kaleidoscope.setup();

  OneShot.enableAutoModifiers();

  // MouseWrapper.speedLimit = 128;
  MouseKeys.speed = 10;
  MouseKeys.accelDelay = 35;

  // KALEIDOSCOPE_INIT_PLUGINS(Macros);

  /**
    * Qukeys configs
    * format Qukey(layer, row, col, alt_keycode)
    * (layers, rows and columns are all zero-indexed,
    * rows are top to bottom and columns are left to right)
    * For the Keyboardio Atreus 2, key coordinates refer to this header file:
    * https://github.com/keyboardio/Kaleidoscope/blob/d7e0f49fef92b6f516c991a927ddac79b44fbd5d/src/kaleidoscope/device/keyboardio/Atreus2.h
  */
  Qukeys.setOverlapThreshold(100); // default is 80
  // Qukeys.setMinimumHoldTime(100); // default is 50
  // Qukeys.setHoldTimeout(500); // default is 250
  Qukeys.setMaxIntervalForTapRepeat(0);
  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 3), Key_Meh),      // R/ Meh 
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 8), Key_Meh),      // U / Meh
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 0), Key_MyHyper),      // A / Hyper
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 1), Key_LeftControl),      // S / Control
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 2), Key_LeftShift),      // D / Shift 
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 3), Key_LeftGui),      // F / Command
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 4), Key_LeftAlt),      // G / Option
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 7), Key_RightAlt),      // H / Option
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 8), Key_RightGui),      // J / Command
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 9), Key_RightShift),      // K / Shift
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 10), Key_RightControl),      // L / Control
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 11), Key_MyHyper),      // ; / Hyper
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 2), ShiftToLayer(_NUMPAD)),      // C / Numpad
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 3), Key_Magic),      // V / Magic
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 4), Key_CommandShift),      // B / CommandShift
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 7), Key_CommandShift),      // N / CommandShift
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 8), Key_Magic),      // M / Magic
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 3), Key_LeftControl),  // Esc / Control
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 4), ShiftToLayer(_LOWER)),  // Space / Punctuation
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 7), ShiftToLayer(_RAISE)),  // Space / Punctuation
         )
}

void loop() {
  Kaleidoscope.loop();
}
