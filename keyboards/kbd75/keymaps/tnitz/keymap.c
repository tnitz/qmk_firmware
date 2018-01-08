#include "kbd75.h"
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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer */
  [_BASE] =
  KEYMAP(
    ESC_MED, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END,  KC_INSERT,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXX,    KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,  KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
    KC_LSFT, XXXX,    KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   MO(_FN),
    KC_LCTL, KC_LGUI, KC_LALT, XXXX,                   SPC_NAV,             XXXX,    KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Fn Layer */
  [_FN] =
  KEYMAP(
    RESET,   ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,  KC_PSCR, KC_SLCK, KC_PAUS,
    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,  ____,    RESET,   ____,
    ____,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ____, ____, ____, ____,  ____,             ____,
    KC_CAPS, ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,                    ____,
    ____,    ____,    ____,    ____,    BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, ____,    ____, ____, ____, MO(_MEDIA),     ____,    ____,
    ____,    ____,    ____,    ____,                      ____,                      ____, ____, ____, ____,  ____,    ____,    ____),

  /* Nav Layer */
  [_NAV] =
  KEYMAP(
    ____, ____, ____, ____, ____, ____, ____, ____,    ____,    ____,    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____,    ____,    ____,    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____,    KC_UP,   ____,    ____, ____, ____, ____,       ____,
    ____, ____, ____, ____, ____, ____, ____, KC_LEFT, KC_DOWN, KC_RGHT, ____, ____, ____,             ____,
    ____, ____, ____, ____, ____, ____, ____, ____,    ____,    ____,    ____, ____, ____,       ____, ____,
    ____, ____, ____, ____,             ____,                   ____,    ____, ____, ____, ____, ____, ____),

  /* Media Layer */
  [_MEDIA] =
  KEYMAP(
    ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____,    ____,    ____,
    ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____,    ____,    ____,
    ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____,             ____,
    ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,                   ____,
    ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,          KC_VOLU, ____,
    ____, ____, ____, ____,             KC_MSTP,             ____, ____, ____, ____, KC_MRWD, KC_VOLD, KC_MFFD)
};
// clang-format on

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  switch (id) {}
  return MACRO_NONE;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {

  } else {
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 2);
    PORTB &= ~(1 << 2);
  } else {
    DDRB &= ~(1 << 2);
    PORTB &= ~(1 << 2);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {
  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {
  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {
  }
}

enum function_id {
  SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
  case SHIFT_ESC:
    shift_esc_shift_mask = get_mods() & MODS_CTRL_MASK;
    if (record->event.pressed) {
      if (shift_esc_shift_mask) {
        add_key(KC_GRV);
        send_keyboard_report();
      } else {
        add_key(KC_ESC);
        send_keyboard_report();
      }
    } else {
      if (shift_esc_shift_mask) {
        del_key(KC_GRV);
        send_keyboard_report();
      } else {
        del_key(KC_ESC);
        send_keyboard_report();
      }
    }
    break;
  }
}
