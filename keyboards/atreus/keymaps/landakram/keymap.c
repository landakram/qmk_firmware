// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define TEXT 0
#define SYMBOLS 1
#define CONTROLS 2

/*
  Layout that imitates my setup on a Kinesis Advantage.
  
  On the Advantage, I have the large thumb keys laid out like this: 

  space bksp   ||   esc enter
  
  To get something similar on the atreus, I've made the large thumb keys dual action.
  
  I have the PCB in backward so I run the following to get things working:

  export OPT_DEFS=-DPCBDOWN
  make atreus-landakram
  avrdude -p atmega32u4 -c avr109 -U flash:w:atreus_landakram.hex -P /dev/cu.usbmodem1411

 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[TEXT] = { 
  {KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,  KC_TRNS,          KC_Y,    KC_U,        KC_I,    KC_O,    KC_P    },
  {KC_A,          KC_S,    KC_D,    KC_F,    KC_G,  KC_TRNS,          KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN },
  {KC_Z,          KC_X,    KC_C,    KC_V,    KC_B,  ALT_T(KC_ESC),   KC_N,    KC_M,        KC_COMM, KC_DOT,  KC_SLSH },
  {KC_ESC,       KC_TAB, KC_LGUI,  KC_LSFT, KC_SPC, CTL_T(KC_BSPC),    KC_ENT,  MO(SYMBOLS), KC_MINS, KC_QUOT, KC_ENT  }
},

/*
 *  !       @     up     {    }              ||         pgup    7     8     9    *
 *  #     left   down  right  $              ||         pgdn    4     5     6    +
 *  [       ]      (     )    &              ||           `     1     2     3    \
 * lower  insert super shift space ctrl|bksp || alt|esc enter   fn    .     0    =
 */
[SYMBOLS] = { 
  {KC_EXLM,      KC_AT,   KC_UP,   KC_LCBR, KC_RCBR, KC_TRNS,          KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR},
  {KC_HASH,      KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,  KC_TRNS,          KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS},
  {KC_LBRC,      KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, ALT_T(KC_ESC),   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS},
  {TG(CONTROLS), KC_INS,  KC_LGUI, KC_LSFT, KC_SPC,  CTL_T(KC_BSPC),    KC_ENT,  KC_TRNS, KC_DOT, KC_0, KC_EQL}
},
/*
 * insert  home   up  end    pgup            ||          up   F7    F8    F9   F10
 *  del    left  down right  pgdn            ||         down  F4    F5    F6   F11
 *        volup              reset           ||               F1    F2    F3   F12
 *        voldn  super shift space ctrl|bksp || alt|esc enter L0  prtsc scroll pause
 */
[CONTROLS] = { 
  {KC_INS,       KC_HOME, KC_UP,   KC_END,  KC_PGUP,  KC_TRNS,         KC_UP,   KC_F7,    KC_F8,   KC_F9,   KC_F10},
  {KC_DELT,      KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN,  KC_TRNS,         KC_DOWN, KC_F4,    KC_F5,   KC_F6,   KC_F11},
  {KC_NO,        KC_VOLU, KC_NO,   KC_NO,   RESET,    ALT_T(KC_ESC),  KC_NO,   KC_F1,    KC_F2,   KC_F3,   KC_F12},
  {KC_NO,        KC_VOLD, KC_LGUI, KC_LSFT, KC_SPC,   CTL_T(KC_BSPC),   KC_ENT,  TO(TEXT), KC_PSCR, KC_SLCK, KC_PAUS}
}};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
