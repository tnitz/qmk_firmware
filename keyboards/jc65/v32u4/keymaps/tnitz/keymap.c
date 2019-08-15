#include "v32u4.h"

#define MODS_CTRL_MASK (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))
#define ____ KC_TRNS
#define XXXX KC_NO
#define SPC_NAV LT(_NAV, KC_SPC)
#define ESC_MED LT(_MEDIA, KC_ESC)

enum layers {
  _BASE,
  _FN,
  _NAV,
  _MEDIA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] =
  LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_BSPC, KC_GRV,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
      KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, MO(_FN),
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE, KC_BTN1, KC_SPACE, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
      ),
  [_FN] =
  LAYOUT(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____, RESET,
      ____, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ____, ____, ____, ____, ____, ____,
      ____, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, ____,
      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, KC_PGUP, MO(_FN),
      ____, ____, ____, ____, ____, KC_BTN1, ____, ____, ____, KC_HOME, KC_PGDN, KC_END
      ),
};
