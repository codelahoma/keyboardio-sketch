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
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"
#include "Kaleidoscope-ShapeShifter.h"

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
#define Key_Plus LSHIFT(Key_Equals)

#define Key_PrevTrack Consumer_ScanPreviousTrack
#define Key_NextTrack Consumer_ScanNextTrack
#define Key_PlayPause Consumer_PlaySlashPause
#define Key_VolumeDown Consumer_VolumeDecrement
#define Key_VolumeUp Consumer_VolumeIncrement
#define Key_Mute Consumer_Mute

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
  QWERTY,
  FUN,
  UPPER
};

/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
      // Left
      Key_Q,           Key_W,                Key_E,                 Key_R,           Key_T,
      Key_A,           Key_S,                Key_D,                 Key_F,           Key_G,
      Key_Z,           Key_X,                Key_C,                 Key_V,           Key_B,            SFT_T(Tab),
      OSL(FUN),         Key_Backtick,         Key_LeftShift,         Key_Backspace,   Key_LeftGui,      CTL_T(Esc),

      // Right
                       Key_Y,                Key_U,                 Key_I,           Key_O,            Key_P,
                       Key_H,                Key_J,                 Key_K,           Key_L,            CTL_T(Semicolon),
      GUI_T(Enter),    Key_N,                Key_M,                 Key_Comma,       Key_Period,       Key_Slash,
      ALT_T(Home),       Key_Space,             Key_Minus,       Key_Backslash,    Key_Quote,     LT(UPPER, End)
  ),

  [FUN] = KEYMAP_STACKED
  (
      // Left
      Key_F1,          Key_F2,               Key_F3,                Key_F4,          Key_F5,
      XXX,             Key_mouseUp,          XXX,                   Key_mouseBtnR,   Key_mouseWarpEnd,
      Key_mouseL,      Key_mouseDn,          Key_mouseR,            Key_mouseBtnL,   Key_mouseWarpNW,  Key_mouseWarpNE,
      ___,             ___,                  ___,                   Key_mouseBtnM,   Key_mouseWarpSW,  Key_mouseWarpSE,

      // Right
                       Key_F6,               Key_F7,                Key_F8,          Key_F9,           Key_F10,
                       Key_PlayPause,        Key_PrevTrack,         Key_NextTrack,   Key_F11,          Key_F12,
      Key_PageUp,      Key_Mute,             Key_VolumeDown,        Key_VolumeUp,    ___,              ___,
      Key_PageDown,    ___,                  ___,                   ___,             ___,              ___
   ),

  [UPPER] = KEYMAP_STACKED
  (
      // Left
      Key_1,           Key_2,                Key_3,                 Key_4,           Key_5,
      ___,             ___,                  ___,                   ___,             ___,
      ___,             ___,                  ___,                   ___,             ___,              Key_LeftShift,
      Key_PrintScreen, ___,                  Key_LeftShift,         Key_Delete,      Key_LeftGui,      Key_LeftControl,

      // Right
                       Key_6,                Key_7,                 Key_8,           Key_9,            Key_0,
                       Key_LeftArrow,        Key_DownArrow,         Key_UpArrow,     Key_RightArrow,   Key_Equals,
      ___,             Key_LeftCurlyBracket, Key_RightCurlyBracket, Key_LeftBracket, Key_RightBracket, Key_Plus,
      ___,             ___,                  ___,                   ___,             ___,              ___
   )
)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Qukeys,
  OneShot,
  ShapeShifter,
  SpaceCadet,
  MouseKeys,
  Macros
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_QWERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(QWERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.disable();
  EEPROMKeymap.setup(10);
  /**
    * Qukeys configs
    * format Qukey(layer, row, col, alt_keycode)
    * (layers, rows and columns are all zero-indexed,
    * rows are top to bottom and columns are left to right)
    * For the Keyboardio Atreus 2, key coordinates refer to this header file:
    * https://github.com/keyboardio/Kaleidoscope/blob/d7e0f49fef92b6f516c991a927ddac79b44fbd5d/src/kaleidoscope/device/keyboardio/Atreus2.h
  */
  // Qukeys.setOverlapThreshold(50); // default is 80
  // Qukeys.setHoldTimeout(500); // default is 250
  // no longer need the following mappings because we're using QuKeys helper short-hand functions in KEYMAPS
  // QUKEYS(
    // kaleidoscope::plugin::Qukey(0, KeyAddr(2, 5), Key_LeftShift),    // Tab / Shift
    // kaleidoscope::plugin::Qukey(0, KeyAddr(3, 5), Key_LeftControl),  // Esc / Control
    // kaleidoscope::plugin::Qukey(0, KeyAddr(3, 6), Key_LeftAlt),      // Home / Alt
    // kaleidoscope::plugin::Qukey(0, KeyAddr(3, 7), MO(UPPER)),        // End / ShiftToLayer(Upper)
  // )
}

void loop() {
  Kaleidoscope.loop();
}
