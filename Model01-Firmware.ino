// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for storing the keymap in EEPROM
// #include "Kaleidoscope-EEPROM-Settings.h"
// #include "Kaleidoscope-EEPROM-Keymap.h"

// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"

#include <Kaleidoscope-OneShot.h>
// #include <Kaleidoscope-Escape-OneShot.h>

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

#include <Kaleidoscope-IdleLEDs.h>

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that prints the keys you press in letters 4px high
// #include "Kaleidoscope-LED-AlphaSquare.h"

// // Support for shared palettes for other plugins, like Colormap below
// #include "Kaleidoscope-LED-Palette-Theme.h"

// // Support for an LED mode that lets one configure per-layer color maps
// #include "Kaleidoscope-Colormap.h"

#include <Kaleidoscope-Qukeys.h>


#include <Kaleidoscope-LED-ActiveModColor.h>
#include <Kaleidoscope-TapDance.h>
#include <Kaleidoscope-LED-Wavepool.h>
#include <Kaleidoscope-LEDEffect-BootAnimation.h>
#include <Kaleidoscope-Heatmap.h>
// #include <Kaleidoscope-MacrosOnTheFly.h>


enum { MACRO_VERSION_INFO,
       MACRO_ANY
     };

// TapDance enums
enum { LPBC,
       RPBC,
       COLON,
       PROGESC,
       ENTER
     };

/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   keeping NUM and FN consistent and accessible on all layers
  *
  * The PROG key is special, since it is how you indicate to the board that you
  * want to flash the firmware. However, it can be remapped to a regular key.
  * When the keyboard boots, it first looks to see whether the PROG key is held
  * down; if it is, it simply awaits further flashing instructions. If it is
  * not, it continues loading the rest of the firmware and the keyboard
  * functions normally, with whatever binding you have set to PROG. More detail
  * here: https://community.keyboard.io/t/how-the-prog-key-gets-you-into-the-bootloader/506/8
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum { PRIMARY,  FUNCTION, _EMPTY }; // layers


/**
  * To change your keyboard's layout from QWERTY to DVORAK or COLEMAK, comment out the line
  *
  * #define PRIMARY_KEYMAP_QWERTY
  *
  * by changing it to
  *
  * // #define PRIMARY_KEYMAP_QWERTY
  *
  * Then uncomment the line corresponding to the layout you want to use.
  *
  */

static const cRGB heat_colors[] PROGMEM = {
                                           {0,0,0},
                                           {145,0,63},
                                           {206,18,86},
                                           {231,41,138},
                                           {223,101,176},
                                           {201,148,199},
                                           {212,185,218},
                                           {231,225,239}
};

#define PRIMARY_KEYMAP_QWERTY
// #define PRIMARY_KEYMAP_COLEMAK
// #define PRIMARY_KEYMAP_DVORAK
// #define PRIMARY_KEYMAP_CUSTOM



/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*
#define Key_MyHyper LCTRL(LALT(LSHIFT(Key_LeftGui)))
#define Key_Magic LCTRL(LALT(Key_LeftGui))
#define Key_CommandShift LSHIFT(Key_LeftGui)
#define Key_AmethystMainWindow LSHIFT(LALT(Key_Enter))
#define Key_AmethystRotateClockwise LCTRL(LSHIFT(LALT(Key_J)))
#define Key_AmethystRotateCounterClockwise LCTRL(LSHIFT(LALT(Key_J)))

KEYMAPS(

#if defined (PRIMARY_KEYMAP_QWERTY)
  [PRIMARY] = KEYMAP_STACKED
  (TD(PROGESC),          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_Escape, Key_Backspace, OSM(LeftGui), OSM(LeftShift),
   OSL(FUNCTION),

   LGUI(Key_H),  Key_6, Key_7, Key_8, Key_9, Key_0, LGUI(Key_Backtick),
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   LALT(Key_Enter),  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   OSM(LeftShift), OSM(LeftAlt), Key_Spacebar, OSM(LeftControl),
   OSL(FUNCTION)),

#else

#error "No default keymap defined. You should make sure that you have a line like '#define PRIMARY_KEYMAP_QWERTY' in your sketch"

#endif

  [FUNCTION] =  KEYMAP_STACKED
  (Key_mouseScrollUp,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           Key_PageUp,
   Key_mouseScrollDn,  ___,              Key_mouseUp, ___,        Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home, Key_mouseL,       Key_mouseDn, Key_mouseR, Key_mouseBtnL, Key_mouseWarpNW,
   Key_End,  Key_PrintScreen,  Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
   ___, Key_Delete, Key_PageUp, Key_PageDown,
   ___,

   Key_PageDown, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  ___,              ___,
   Key_PcApplication,          Key_PageDown,           Key_PageUp, Consumer_VolumeDecrement, Consumer_VolumeIncrement,             Key_Backslash,    Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___),
  [_EMPTY] = KEYMAP_STACKED
  (
   ___ ,___ ,___ ,___ ,___ ,___ ,___
   ,___ ,___ ,___ ,___ ,___ ,___ ,___
   ,___ ,___ ,___ ,___ ,___ ,___
   ,___ ,___ ,___ ,___ ,___ ,___ ,___
   ,___ ,___ ,___ ,___
   ,___

   ,___ ,___ ,___ ,___ ,___ ,___ ,___
   ,___ ,___ ,___ ,___ ,___ ,___ ,___
   ,___ ,___ ,___ ,___ ,___ ,___
   ,___ ,___ ,___ ,___ ,___ ,___ ,___

   ,___ ,___ ,___ ,___
   ,___
   ),
) // KEYMAPS(

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

// static void anyKeyMacro(uint8_t keyState) {
//   static Key lastKey;
//   bool toggledOn = false;
//   if (keyToggledOn(keyState)) {
//     lastKey.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36));
//     toggledOn = true;
//   }

//   if (keyIsPressed(keyState))
//     kaleidoscope::hid::pressKey(lastKey, toggledOn);
// }


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  // case MACRO_ANY:
  //   anyKeyMacro(keyState);
  //   break;
  }
  return MACRO_NONE;
}

void tapDanceAction(uint8_t tap_dance_index, byte row, byte col, uint8_t tap_count,
                    kaleidoscope::plugin::TapDance::ActionType tapDanceAction) {
  switch (tap_dance_index) {
  case LPBC:
    return tapDanceActionKeys(tap_count, tapDanceAction,
                              Key_9, Key_LeftBracket);
  case RPBC:
    return tapDanceActionKeys(tap_count, tapDanceAction,
                              Key_0, Key_RightBracket);
  case COLON:
    return tapDanceActionKeys(tap_count, tapDanceAction,
                          LSHIFT(Key_Semicolon), Key_Semicolon);
  case PROGESC:
    return tapDanceActionKeys(tap_count, tapDanceAction,
                              Key_Escape, Key_NoKey);
  case ENTER:
    return tapDanceActionKeys(tap_count, tapDanceAction,
                              Key_NoKey, Key_Enter);
  }
}

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,
  Focus,
  // FocusSettingsCommand,
  // FocusEEPROMCommand,
  LEDControl,
  BootAnimationEffect,
  LEDOff,
  WavepoolEffect,
  HeatmapEffect,
  // AlphaSquareEffect,
  LEDBreatheEffect,
  // LEDEffect-Chase,
  LEDRainbowEffect,
  LEDRainbowWaveEffect,
  // EEPROMSettings,
  // EEPROMKeymap,
  OneShot,
  TapDance,
  // EscapeOneShot,
  Macros,
  // MacrosOnTheFly,
  MouseKeys,
  ActiveModColorEffect
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  Kaleidoscope.setup();
  QUKEYS(
/* #define PER_KEY_DATA(dflt,
//   r0c0, r0c1, r0c2, r0c3, r0c4, r0c5, r0c6,        r0c9,  r0c10, r0c11, r0c12, r0c13, r0c14, r0c15,
//   r1c0, r1c1, r1c2, r1c3, r1c4, r1c5, r1c6,        r1c9,  r1c10, r1c11, r1c12, r1c13, r1c14, r1c15,
//   r2c0, r2c1, r2c2, r2c3, r2c4, r2c5,                     r2c10, r2c11, r2c12, r2c13, r2c14, r2c15,
//   r3c0, r3c1, r3c2, r3c3, r3c4, r3c5, r2c6,        r2c9,  r3c10, r3c11, r3c12, r3c13, r3c14, r3c15,
//               r0c7, r1c7, r2c7, r3c7,                             r3c8,  r2c8,  r1c8, r0c8,
//                           r3c6,                                          r3c9, ...)                      */

         kaleidoscope::plugin::Qukey(0, KeyAddr(0, 7), Key_LeftControl),
         kaleidoscope::plugin::Qukey(0, KeyAddr(1, 0), Key_CommandShift),
         kaleidoscope::plugin::Qukey(0, KeyAddr(2, 0), Key_Magic),
         kaleidoscope::plugin::Qukey(0, KeyAddr(2, 6), Key_CommandShift),
         kaleidoscope::plugin::Qukey(0, KeyAddr(2, 9), Key_CommandShift),
         kaleidoscope::plugin::Qukey(0, KeyAddr(3, 0), Key_MyHyper),
         kaleidoscope::plugin::Qukey(0, KeyAddr(3, 9), Key_LeftGui)
         );
  Qukeys.setHoldTimeout(200);
  Qukeys.setOverlapThreshold(25);
  // First, call Kaleidoscope's internal setup function

  // AlphaSquare.color = {0xcb, 0xc0, 0xff};
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);
  LEDRainbowWaveEffect.update_delay(50);

  HeatmapEffect.heat_colors = heat_colors;
  HeatmapEffect.heat_colors_length = 8;

  WavepoolEffect.idle_timeout = 5000;  // 5 seconds
  WavepoolEffect.activate();

  MouseWrapper.speedLimit = 64;
  MouseKeys.speed = 10;
  MouseKeys.accelDelay = 35;


  LEDOff.activate();
  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for five layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  // EEPROMKeymap.setup(1);

  // // We need to tell the Colormap plugin how many layers we want to have custom
  // // maps for. To make things simple, we set it to five layers, which is how
  // // many editable layers we have (see above).
  // ColormapEffect.max_layers(5);
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
