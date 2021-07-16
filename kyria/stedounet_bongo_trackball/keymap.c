/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include <stdio.h>
#ifdef PIMORONI_TRACKBALL_ENABLE
#include "pimoroni_trackball.h"
#endif

#ifdef POINTING_DEVICE_ENABLE
#include "pointing_device.h"
#endif

enum layers {
    _AZERTY = 0,
    _LOWER,
    _RAISE,
    _ALGR,
    _ADJUST
};

char wpm_str[10];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: AZERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  TAB   |   A  |   Z  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   ^    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Lshift |   Q  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |   M  |   ù    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCtrl  |   W  |   X  |   C  |   V  |   B  | esc  |ADJUST|  | TAB  |LShift|   N  |   ,  |   ;  |   :  |   !  |   *    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | ALT  |Lower | Space| Raise|  | bkspc|enter | altgr|   <  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_AZERTY] = LAYOUT(
      KC_TAB,	FR_A,   FR_Z, KC_E,   KC_R,   KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, FR_CIRC,
      KC_LSFT, 	FR_Q,   KC_S, KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    FR_M, FR_UGRV,
      KC_LCTL,  KC_Z,   KC_X, KC_C,   KC_V,   KC_B, KC_ESC,MO(_ADJUST),KC_TAB, KC_LSFT, KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, FR_ASTR,
          KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, MO(_RAISE),              KC_BSPC,  KC_ENT, MO(_ALGR), FR_LABK,  KC_RALT
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   esc  |  &   |  é   |   "  |  '   |  (   |                              |   -  |   è  |  _   |  ç   |  à   |    )   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  ^   |  $   |  (   |  [   |  {   |                              |      | pgdn |  up  | pgup |  %   |    =   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  #   |  )   |  ]   |  }   |      |      |  |      |      |      | left | down | right|  / ? |    <   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_LOWER] = LAYOUT(
      KC_ESC,  FR_AMPR,  FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN,                                         			FR_MINS, FR_EGRV, FR_UNDS, FR_CCED,  FR_AGRV, FR_RPRN,
      _______, ALGR(FR_CCED), FR_DLR,  FR_LPRN, ALGR(FR_LPRN), ALGR(FR_QUOT),                                   	_______, KC_PGUP, KC_UP,   KC_PGDN,  KC_PERC, FR_EQL,
      _______, LSFT(FR_UGRV), ALGR(FR_QUOT), FR_RPRN, ALGR(FR_RPRN), ALGR(FR_EQL), _______, _______,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, FR_LABK, FR_LABK,
                                             _______, _______,       _______,      KC_SCLN, KC_EQL,   _______, _______, _______,_______, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |  €   |      |VolUp |                              |brgtUp|  7   |  8   |  9   |numlk |impr sys|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  caps  |      |Mouse1|Mouse2|Mouse3|VolDn |                              |brgtDn|  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      | Mute |      |      |  |      |      |      |  1   |  2   |  3   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |  0   |  .   |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_RAISE] = LAYOUT(
      _______, _______, _______, ALGR(KC_E), _______, KC_VOLU,                                     KC_BRIU, KC_P7,   KC_P8,   KC_P9,  KC_NLCK, _______, 
      KC_CAPS, _______, KC_BTN1, KC_BTN2,    KC_BTN3, KC_VOLD,                                     KC_BRID, KC_P4,   KC_P5,   KC_P6,  _______, _______, 
      _______, _______, _______, _______,    _______, KC_MUTE, _______, _______, _______, _______, _______, KC_P1,	 KC_P2,   KC_P3,  _______, _______, 
                                 _______,    _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, _______
    ),

 /*
  * Algr layer: lower, but algred version
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |    ¬   |  ¹   |   ~  |  #   |  {   |  [   |                              |  |   |  `   |  \   |  ^   |  @   |   ]    |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      | pgup |  up  | pgdn |      |   }    |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      | left | down |right |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_ALGR] = LAYOUT(
       _______, ALGR(FR_AMPR),  ALGR(FR_EACU), ALGR(FR_DQUO), ALGR(FR_QUOT), ALGR(FR_LPRN), ALGR(FR_MINS), ALGR(FR_EGRV), ALGR(FR_UNDS), ALGR(FR_CCED),  ALGR(FR_AGRV), ALGR(FR_RPRN),
       _______, _______, _______, _______, _______, _______,                                     _______, KC_PGUP, KC_UP,   KC_PGDN, _______, ALGR(KC_EQL),
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};


#ifdef OLED_DRIVER_ENABLE
static void render_status(void) {
    uint8_t led_usb_state = host_keyboard_leds();
    if (!IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)) {
	// this will print just right to fill the rest of the line
    	oled_write_P(PSTR(" NUMPAD OFF!"), false);
    } else {
    	oled_write_P(PSTR("\n"), false);
    }
    // Host Keyboard Layer Status
    
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _AZERTY:
            oled_write_P(PSTR("Stedounet"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower    "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise    "), false);
            break;
        case _ALGR:
            oled_write_P(PSTR("Algr     "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust   "), false);
            break;
        default:
            oled_write_P(PSTR("Meh ?    "), false);
    }
    if (IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)) {
	// this will print just right to fill the rest of the line
    	oled_write_P(PSTR(" CAPS"), false);
    } else {
    	oled_write_P(PSTR("\n"), false);
    }
}

void oled_task_user(void) {
    if (!is_keyboard_master()) {
        oled_set_cursor(0,6);
        sprintf(wpm_str, "WPM: %03d ", get_current_wpm());
        oled_write(wpm_str, false);
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } 
}
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
void pointing_device_task() {
    report_mouse_t mouse_report = pointing_device_get_report();
    /*if (is_keyboard_master()) {
	bool fast_scroll = (get_highest_layer(layer_state) == _SYM);

	process_mouse(&mouse_report, fast_scroll);
    }
*/	

    if (layer_state_is(_ADJUST)) {
        trackball_set_scrolling(true);
    } else {
        trackball_set_scrolling(false);
    }

    pointing_device_set_report(mouse_report);
    pointing_device_send();
}
#endif

#ifdef COMBO_ENABLE
enum combo_events {
    ZC_CTALTSUPPR,
};

const uint16_t PROGMEM ctrlaltsuppr_combo[] = {KC_LCTL, KC_LALT, FR_CIRC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [ZC_CTALTSUPPR] = COMBO_ACTION(ctrlaltsuppr_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case ZC_CTALTSUPPR:
            if (pressed) {
                tap_code16(LCTL(LALT(KC_DEL)));
                                  
            }
            break;
    }

}
#endif



