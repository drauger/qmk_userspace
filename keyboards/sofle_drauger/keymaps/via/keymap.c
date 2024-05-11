 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),           ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) }
    // [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)}
    // [1] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | WIN  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |LOWER |RAISE | LAlt | LCTR | /Space  /       \Enter \  | RCTR | RAlt |RAISE |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
   KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
   KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  KC_LGUI,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,  XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                   TT(1),   TT(2), KC_LALT, KC_LCTL,  KC_SPC,   KC_ENT, KC_RCTL, KC_RALT,   TT(2),   TT(1)
),
/*
 * LOWER - NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |   /  |   7  |   8  |   9  |   =  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | PgUp | Home |  Up  | End  |      |                    |   *  |   4  |   5  |   6  |   (  |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | WIN  | PgDn | Left | Down | Right|      |-------.    ,-------|   -  |   1  |   2  |   3  |   )  | WIN  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|      |  m1  | m3   |  m2  |      |-------|    |-------|   +  |   0  |   ,  |   .  |   \  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |LOWER |RAISE | LAlt | LCTR | /Space  /       \Enter \  | RCTR | RAlt |RAISE |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
   KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_PSLS,   KC_P7,   KC_P8,   KC_P9,  KC_EQL,  KC_DEL,
   KC_TAB, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,                    KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_LPRN, KC_RBRC,
  KC_LGUI, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                    KC_PMNS,   KC_P1,   KC_P2,   KC_P3, KC_RPRN, KC_RGUI,
  KC_LSFT, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, KC_MUTE,  XXXXXXX, KC_PPLS,   KC_P0, KC_PDOT, KC_PCMM, KC_BSLS, KC_RSFT,
                      TT(1),   TT(2), KC_LALT, KC_LCTL,  KC_SPC,   KC_ENT, KC_RCTL, KC_RALT,   TT(2),   TT(1)
),
/* RAISE - Fn
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | Ins  |  m1  | mUp  |  m2  | wUp  |                    | PgUp | Home |  Up  | End  | F11  |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | WIN  | Pscr |  mLt |  mDn |  mRt | wDn  |-------.    ,-------| PgDn | Left | Down | Right| F12  | WIN  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|      |  wL  |  m3  |  wR  |      |-------|    |-------|      |  m1  | m3   |  m2  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |LOWER |RAISE | LAlt | LCTR | /Space  /       \Enter \  | RCTR | RAlt |RAISE |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
   KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_MINS,
   KC_TAB,  KC_INS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,                    KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_F11, KC_RBRC,
  KC_LGUI, KC_PSCR, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_F12, KC_RGUI,
  KC_LSFT, XXXXXXX, KC_WH_L, KC_BTN3, KC_WH_R, XXXXXXX, _______,  _______, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, KC_BSLS, KC_RSFT,
                      TT(1),   TT(2), KC_LALT, KC_LCTL, KC_SPC,    KC_ENT, KC_RCTL, KC_RALT,   TT(2),   TT(1)
),
/* ADJUST
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      | MUTE |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      | VOL+ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      | VOL- |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|   |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |LOWER |RAISE | LAlt | LCTR | /Space  /       \Enter \  | RCTR | RAlt |RAISE |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
 /*
[3] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      TT(1),   TT(2), KC_LALT, KC_LCTL,   KC_SPC,   KC_ENT, KC_RCTL, KC_RALT,   TT(2),   TT(1)
)
*/
};
