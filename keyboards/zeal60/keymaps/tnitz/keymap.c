// Default layout for Zeal60

#include "zeal60.h"

#define _______ KC_TRNS
#define XXXXX KC_NO
#define SPC_NAV LT(_NAV, KC_SPC)
#define MODIFY TO(_ADJUST)

// [0,13] is either left key of split backspace (e.g. HHKB \| key) or 2U backspace
// [1,13] is either backslash or ISO Enter
// [2,12] is either ANSI Enter or key left of ISO Enter
// [2,13] is right key of split backspace (e.g. HHKB `~ key)
// [3,1] is right key of split left-shift (e.g ISO key)
// [3,13] is right key of split right-shift (e.g. HHKB Fn key)

enum layers {
  _BASE,
  _FN,
  _NAV,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Default layer
[_BASE] = {
        {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC},
        {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS},
        {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  XXXXX  },
        {KC_LSFT, XXXXX,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXX  },
        {KC_LCTL, KC_LGUI, KC_LALT, XXXXX,   XXXXX,   XXXXX,   XXXXX,   SPC_NAV, XXXXX,   XXXXX,   KC_RALT, KC_RGUI, MO(_FN), KC_RCTL}
},

// Fn1 Layer
[_FN] = {
        {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL },
        {KC_CAPS, _______, KC_UP,   _______, _______, _______, _______, _______, KC_INS,  _______, KC_PSCR, KC_SLCK, KC_PAUS, _______},
        {_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_END,  KC_PGDN, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, MODIFY,  _______, _______, _______, _______, _______, _______}
},

// Fn2 Layer
[_NAV] = {
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MODIFY,  _______}
},

// Fn3 Layer (zeal60 Configuration)
[_ADJUST] = {
        {RESET,   EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  _______, _______, _______, _______, BR_DEC,  BR_INC,  TO(_BASE)},
        {_______, _______, _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______, ES_DEC,  ES_INC,  _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};
