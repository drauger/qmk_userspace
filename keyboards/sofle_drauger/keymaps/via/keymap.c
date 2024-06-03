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
    [0] = { ENCODER_CCW_CW(KC_WH_R, KC_WH_L),           ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [1] = { ENCODER_CCW_CW(KC_MS_R, KC_MS_L),           ENCODER_CCW_CW(KC_MS_D, KC_MS_U) },
    [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) }
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
 * |------+------+------+------+------+------|  En   |    |  Ru   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt |LOWER |RAISE | /Space  /       \Enter \  |RAISE |LOWER | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *             `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
   KC_ESC, KC_1,  KC_2,    KC_3,  KC_4,  KC_5,                        KC_6,  KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
   KC_TAB, KC_Q,  KC_W,    KC_E,  KC_R,  KC_T,                        KC_Y,  KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  KC_LGUI, KC_A,  KC_S,    KC_D,  KC_F,  KC_G,                        KC_H,  KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,  KC_X,    KC_C,  KC_V,  KC_B, LSA(KC_1), LSA(KC_2),  KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
               KC_LCTL, KC_LALT, MO(1), MO(2),    KC_SPC,    KC_ENT, MO(2), MO(1), KC_RALT, KC_RCTL
),
/*
 * LOWER - NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | Mute |  @   |  #   |  $   |  %   |                    |   /  |   7  |   8  |   9  |   )  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | vUp  | Home |  Up  | End  | PgUp |                    |   *  |   4  |   5  |   6  |   (  |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | WIN  | vDn  | Left | Down | Right| PgDn |-------.    ,-------|   -  |   1  |   2  |   3  |   ;  |  "   |
 * |------+------+------+------+------+------|  RGB  |    | CtrlA |------+------+------+------+------+------|
 * |LShift| Caps |  m1  | m3   |  m2  | Power|-------|    |-------|   +  |   0  |   ,  |   >  |   \  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt |LOWER |RAISE | /Space  /       \Enter \  |RAISE |LOWER | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
   KC_GRV, KC_MUTE,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                    KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_RPRN,  KC_EQL,
   KC_TAB, KC_VOLU, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                    KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_LPRN, KC_RBRC,
  KC_LGUI, KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                    KC_PMNS,   KC_P1,   KC_P2,   KC_P3, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_CAPS, KC_BTN1, KC_BTN3, KC_BTN2,  KC_PWR, RGB_TOG,  C(KC_A), KC_PPLS,   KC_P0, KC_PDOT,   KC_GT, KC_BSLS, KC_RSFT,
                    KC_TRNS, KC_TRNS, KC_TRNS,   TG(2), KC_TRNS,  KC_TRNS,   TG(2), KC_TRNS, KC_TRNS, KC_TRNS
),
/* RAISE - Fn
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | Ins  |  m1  | mUp  |  m2  | wUp  |                    | PgUp | Home |  Up  | End  | F11  |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | WIN  | Pscr |  mLt |  mDn |  mRt | wDn  |-------.    ,-------| PgDn | Left | Down | Right| F12  | WIN  |
 * |------+------+------+------+------+------|  MUTE |    | shftA |------+------+------+------+------+------|
 * | Shift|Pause |  wL  |  m3  |  wR  | Menu |-------|    |-------| Menu |  m2  | m3   |  m1  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt |LOWER |RAISE | /Space  /       \Enter \  |RAISE |LOWER | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
   KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_MINS,
   KC_TAB,  KC_INS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,                    KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_F11, KC_RBRC,
  KC_LGUI, KC_PSCR, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_F12, KC_RGUI,
  KC_LSFT, KC_PAUS, KC_WH_L, KC_BTN3, KC_WH_R,  KC_APP, KC_MUTE,  S(KC_A),  KC_APP, KC_BTN2, KC_BTN3, KC_BTN1, KC_BSLS, KC_RSFT,
                    KC_TRNS, KC_TRNS,   TG(1), KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,   TG(1), KC_TRNS, KC_TRNS
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
 *            | LCTR | LAlt |LOWER |RAISE | /Space  /       \Enter \  |RAISE |LOWER | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
 /*
[3] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  _______,  _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                      TT(1),   TT(2), KC_LALT, KC_LCTL,   KC_SPC,   KC_ENT, KC_RCTL, KC_RALT,   TT(2),   TT(1)
)
*/
};

static uint8_t language;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Initialize variable holding the binary
    // representation of active modifiers.
    uint8_t mod_state;
    
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
	
    switch (keycode) {
    
        case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
                }
            } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
                }
            }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
        }
        
        case KC_LGUI:
        case KC_RGUI:
        {
            oled_set_cursor(0, 11);
		    if (record->event.pressed) {
                oled_write_ln_P(PSTR("GUI"), false);
            } else {
                oled_write_ln_P(PSTR(""), false);
            }
        return true;
        }
		
        case KC_LALT:
        case KC_RALT:
        {
		    oled_set_cursor(0, 9);
		    if (record->event.pressed) {
                oled_write_ln_P(PSTR("Alt"), false);
            } else {
            oled_write_ln_P(PSTR(""), false);
            }
        return true;
        }
		
        case KC_LSFT:
        case KC_RSFT:
        {
		    oled_set_cursor(0, 7);
            if (record->event.pressed) {
                oled_write_ln_P(PSTR("Shft"), false);
            } else {
                oled_write_ln_P(PSTR(""), false);
            }
        return true;
        }
		
        case KC_LCTL:
        case KC_RCTL:
        {
            oled_set_cursor(0, 5);
		    if (record->event.pressed) {
                oled_write_ln_P(PSTR("Ctrl"), false);
            } else {
                oled_write_ln_P(PSTR(""), false);
            }
        return true;
        }
        // case KC_COLN:
        // case KC_RPRN:
        // case KC_DQT:
                
        case KC_GT:
        if(get_highest_layer(layer_state) == 1) {
        // Initialize a boolean variable that keeps track
        // of the key status: registered or not?
        static bool key_registered;
        if (record->event.pressed) {
            // Detect the activation of either alt keys
            if (mod_state & MOD_MASK_ALT) {
                uint8_t lang = language;
                add_mods(MOD_MASK_SHIFT);
				register_code(KC_1);
				del_mods(MOD_MASK_ALT);
                register_code(KC_COMMA);
                // Update the boolean variable to reflect the status of KC_GT
                key_registered = true;
                // Reapplying modifier state so that the held alt key(s)
                // still work even after having tapped the KC_GT key.
                if(lang == 2) {
					add_mods(MOD_MASK_ALT);
					register_code(KC_2);
				}
				set_mods(mod_state);
                return false;
                }
            } else { // on release of KC_DOT
            // In case KC_COMM is still being sent even after the release of KC_GT
            if (key_registered) {
                unregister_code(KC_COMMA);
                key_registered = false;
                return false;
                }
            }
        // Let QMK process the KC_DOT keycode as usual outside of shift
        return true;
        }
        
        case KC_1:
        {
            if (mod_state & MOD_MASK_SA) {
                language = 1;
				oled_set_cursor(0, 13);
                if (record->event.pressed) {
                    oled_write_ln_P(PSTR("En"), false);
                // } else {
                //     oled_write_ln_P(PSTR(""), false);
                }
            }
        return true;
        }
        case KC_2:
        {
            if (mod_state & MOD_MASK_SA) {
                language = 1;
                oled_set_cursor(0, 13);
                if (record->event.pressed) {
                    oled_write_ln_P(PSTR("  Ru"), false);
                // } else {
                //     oled_write_ln_P(PSTR(""), false);
                }
            }
        return true;
        }
    }
    return true;
};
