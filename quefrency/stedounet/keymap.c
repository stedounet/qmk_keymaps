#include QMK_KEYBOARD_H
#include "keymap_french.h"


#define _BASE 0
#define _AZERTY 1
#define _AZERTY2 2
#define _FN1 10
#define _FN2 11
/*
enum layer_names {
    _BASE,
    _FN1,
    _AZERTY,
    _AZERTY2
};*/

enum custom_keycodes {
  BASE = SAFE_RANGE,
  AZERTY,
  AZERTY2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
   * │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │     │  7  │  8  │  9  │  0  │  -  │  =  │BSPC       │Del  │
   * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘  ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
   * │TAB     │  Q  │  W  │  E  │  R  │  T  │     │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSLS    │End  │
   * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐    └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
   * │CAPS     │  A  │  S  │  D  │  F  │  G  │     │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │PgUp │
   * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐  └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
   * │LSHFT       │  Z  │  X  │  C  │  V  │  B  │     │  N  │  M  │  ,  │  .  │  /  │RSHFT     │ UP  │PgDw │
   * ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┤     ├─────┴┬────┴────┬┴────┬┴────┬┴────┬─────┼─────┼─────┤
   * │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │     │SPC   │BSPC     │FN2  │R_ALT│R_CTR│LEFT │DOWN │RIGHT│
   * └──────┴───────┴──────┴─────────────┴──────┘     └──────┴─────────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [_BASE] = LAYOUT_65(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,        KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_UP,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DOWN,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_FN1),                               KC_SPC,  KC_BSPC,  MO(_FN2), KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_FN1] = LAYOUT_65(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_DEL,  KC_DEL, _______,
    _______, _______, KC_HOME, KC_UP,   KC_END,  DF(_BASE),                 _______, _______, KC_P7,    KC_P8,    KC_P9,   _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, DF(_AZERTY),                        _______, KC_P4,    KC_P5,    KC_P6,   _______, _______, _______, _______,
    _______, _______, _______, _______, _______, DF(_AZERTY2),                       _______, KC_P1,    KC_P2,    KC_P3,   _______, _______, _______, _______,
    RESET,   _______, _______, _______, _______,                                _______, KC_P0,    KC_DOT,   _______, _______, _______, _______, _______

  ),

  [_FN2] = LAYOUT_65(
    KC_GRV,  FR_EACU, _______,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     FR_EGRV, _______, FR_CCED, FR_AGRV,  KC_F11,  KC_F12,  KC_DEL, KC_BSPC, _______,
    _______, _______, KC_HOME, KC_UP,   KC_END,  _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                       _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, _______, _______,
    RESET,   _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______, _______, _______

  ),
  
  /* 
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
   * │ESC  │  &  │  é  │  "  │  '  │  (  │  -  │     │  è  │  _  │  ç  │  à  │  )  │  =  │BSPC       │Del  │
   * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘  ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
   * │TAB     │  A  │  Z  │  E  │  R  │  T  │     │  Y  │  U  │  I  │  O  │  P  │  ^  │  $  │   *    │End  │
   * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐    └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
   * │CAPS     │  Q  │  S  │  D  │  F  │  G  │     │  H  │  J  │  K  │  L  │  M  │  ù  │ENTER        │PgUp │
   * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐  └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
   * │LSHFT       │  W  │  X  │  C  │  V  │  B  │     │  N  │  ,  │  ;  │  :  │  !  │RSHFT     │ UP  │PgDw │
   * ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┤     ├─────┴┬────┴────┬┴────┬┴────┬┴────┬─────┼─────┼─────┤
   * │LCTRL │L_GUI  │L_ALT │FN1          │SPC   │     │BSPC  │SPC      │ALGR │ < > │R_CTR│LEFT │DOWN │RIGHT│
   * └──────┴───────┴──────┴─────────────┴──────┘     └──────┴─────────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  [_AZERTY] = LAYOUT_65(
    KC_ESC,  FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN, FR_MINS,     FR_EGRV, FR_UNDS, FR_CCED,  FR_AGRV,  FR_RPRN, FR_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
    KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    FR_CIRC, FR_DLR,  FR_ASTR, KC_END,
    KC_CAPS, FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,     KC_K,     KC_L,    FR_M,    FR_UGRV, KC_ENT,  KC_UP,
    KC_LSFT, KC_W,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    FR_COMM,  FR_SCLN,  FR_COLN, FR_EXLM, KC_RSFT, KC_UP,   KC_DOWN,
    KC_LCTL, KC_LGUI, KC_LALT, MO(_FN1),KC_SPC,                                 KC_BSPC, KC_SPC,   KC_ALGR, FR_LESS, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  

 /* 
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
   * │  @  │ à § │ é " │ è " │ ê & │ ( [ │ ) ] │     │ ' - │ ' _ │  "  │  "  │  '  │ ^ v │BSPC       │Del  │
   * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘  ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
   * │TAB     │  A  │  Z  │  E  │  R  │ T { │     │ Y } │  U  │  I  │  O  │ P % │  -  │  +  │BSLS    │End  │
   * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐    └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
   * │ESC      │  Q  │  S  │  D  │  F  │  G  │     │  H  │  J  │  K  │  L  │  M  │ / \ │ENTER        │PgUp │
   * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐  └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
   * │LSHFT       │  W  │  X  │  C  │  V  │  B  │     │ N ~ │  .  │ , ! │: ...│ ; = │RSHFT     │ UP  │PgDw │
   * ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┤     ├─────┴┬────┴────┬┴────┬┴────┬┴────┬─────┼─────┼─────┤
   * │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │     │SPC   │BSPC     │FN2  │ALGR │R_CTR│LEFT │DOWN │RIGHT│
   * └──────┴───────┴──────┴─────────────┴──────┘     └──────┴─────────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [_AZERTY2] = LAYOUT_65(
    KC_ESC,  FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN, FR_MINS,     FR_EGRV, FR_UNDS, FR_CCED,  FR_AGRV,  FR_RPRN, FR_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
    KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    FR_CIRC, FR_DLR,  FR_ASTR, KC_END,
    KC_CAPS, FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,     KC_K,     KC_L,    FR_M,    FR_UGRV, KC_ENT,  KC_UP,
    KC_LSFT, KC_W,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    FR_COMM,  FR_SCLN,  FR_COLN, FR_EXLM, KC_RSFT, KC_UP,   KC_DOWN,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_FN1),                               KC_SPC,  KC_BSPC,  KC_ALGR, FR_LESS, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
  )
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
      break;
    case AZERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_AZERTY);
      }
      return false;
      break;
    case AZERTY2:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_AZERTY2);
      }
      return false;
      break;
  }
  return true;
}

