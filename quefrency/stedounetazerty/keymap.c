#include QMK_KEYBOARD_H
#include "keymap_french.h"


#define _BASE 0
#define _UNSPLIT 1
#define _FN1 10


enum custom_keycodes {
	VIMEXIT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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

  [_BASE] = LAYOUT_65(
    KC_ESC,  FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN, FR_MINS,     FR_EGRV, FR_UNDS, FR_CCED,  FR_AGRV,  FR_RPRN, FR_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
    KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    FR_CIRC, FR_DLR,  FR_ASTR, KC_END,
    KC_CAPS, FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,     KC_K,     KC_L,    FR_M,    FR_UGRV, KC_ENT,  KC_PGUP,
    KC_LSFT, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    FR_COMM,  FR_SCLN,  FR_COLN, FR_EXLM, KC_RSFT, KC_UP,   KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT, MO(_FN1),KC_SPC,                                 KC_BSPC, KC_ALGR,  KC_ALGR,  FR_LESS, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_FN1] = LAYOUT_65(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_DEL,  KC_DEL, KC_NLCK,
    _______, KC_BRIU, KC_VOLU, LWIN(KC_L),   KC_END,  DF(_BASE),                _______, KC_P7,    KC_P8,    KC_P9,   _______, _______, _______, _______, _______,
    _______, KC_BRID, KC_VOLD, KC_DOWN, KC_RGHT, DF(_UNSPLIT),                  _______, KC_P4,    KC_P5,    KC_P6,   _______, _______, _______, _______,
    _______, _______, KC_MUTE, _______, _______, _______,                       _______, KC_P1,    KC_P2,    KC_P3,   _______, _______, A(KC_UP), _______,
    RESET,   _______, _______, _______, _______,                                _______, KC_P0,    KC_PDOT,   _______, _______, A(KC_LEFT), A(KC_DOWN), A(KC_RIGHT)

  ),

  [_UNSPLIT] = LAYOUT_65(
    _______, FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN, FR_MINS,     FR_EGRV, FR_UNDS, FR_CCED,  FR_AGRV,  FR_RPRN, FR_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
    KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    FR_CIRC, FR_DLR,  FR_ASTR, KC_END,
    KC_CAPS, FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,     KC_K,     KC_L,    FR_M,    FR_UGRV, KC_ENT,  KC_PGUP,
    KC_LSFT, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    FR_COMM,  FR_SCLN,  FR_COLN, FR_EXLM, KC_RSFT, KC_UP,   KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_FN1),                               KC_BSPC, KC_ALGR,  KC_ALGR,  FR_LESS, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case VIMEXIT:
			if (record->event.pressed) {
				SEND_STRING(SS_TAP(X_ESCAPE) ":wqa");
			}
			break;
	}
	return true;
};
