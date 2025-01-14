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
   KC_ESC, KC_1,  KC_2,    KC_3,  KC_4,  KC_5,                    KC_6,  KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
   KC_TAB, KC_Q,  KC_W,    KC_E,  KC_R,  KC_T,                    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  KC_LGUI, KC_A,  KC_S,    KC_D,  KC_F,  KC_G,                    KC_H,  KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,  KC_X,    KC_C,  KC_V,  KC_B, KC_LNG1, KC_LNG1,  KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
               KC_LCTL, KC_LALT, MO(1), MO(2),  KC_SPC,  KC_ENT, MO(2), MO(1), KC_RALT, KC_RCTL
),
/*
 * LOWER - NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | BRT  |  vDn |  vUp |  $   |  %   |                    |   /  |   7  |   8  |   9  |  )(  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | SAT  | Home |  Up  | End  | PgUp |                    |   *  |   4  |   5  |   6  |   &  |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | WIN  | HUE  | Left | Down | Right| PgDn |-------.    ,-------|   -  |   1  |   2  |   3  |   ;  |  '   |
 * |------+------+------+------+------+------|  RGB  |    | CtrlA |------+------+------+------+------+------|
 * |LShift| Caps |  m1  | m3   |  m2  | Power|-------|    |-------|   +  |   0  |   ,  |  ><  |   \  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt |LOWER |RAISE | /Space  /       \Enter \  |RAISE |LOWER | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
   KC_GRV, RGB_VAI, KC_VOLD, KC_VOLU,  KC_DLR, KC_PERC,                    KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_RPRN,  KC_EQL,
   KC_TAB, RGB_SAI, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                    KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_AMPR, KC_RBRC,
  KC_LGUI, RGB_HUI, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                    KC_PMNS,   KC_P1,   KC_P2,   KC_P3, KC_COLN,  KC_DQT,
  KC_LSFT, KC_CAPS, KC_BTN1, KC_BTN3, KC_BTN2,  KC_PWR, RGB_TOG,  C(KC_A), KC_PPLS,   KC_P0, KC_PDOT,   KC_GT, KC_BSLS, KC_RSFT,
                    KC_TRNS, KC_TRNS, KC_TRNS,   TG(2), KC_TRNS,  KC_TRNS,   TG(2), KC_TRNS, KC_TRNS, KC_TRNS
),
/* RAISE - Fn
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | Ins  |  wL  | mUp  |  wR  | wUp  |                    | PgUp | Home |  Up  | End  | F11  |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | WIN  | Pscr |  mLt |  mDn |  mRt | wDn  |-------.    ,-------| PgDn | Left | Down | Right| F12  | WIN  |
 * |------+------+------+------+------+------|  MUTE |    | shftA |------+------+------+------+------+------|
 * | Shift|Pause |  m1  | m3   |  m2  | Menu |-------|    |-------| Menu |  m2  | m3   |  m1  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt |LOWER |RAISE | /Space  /       \Enter \  |RAISE |LOWER | RAlt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
   KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_MINS,
   KC_TAB,  KC_INS, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                    KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_F11, KC_RBRC,
  KC_LGUI, KC_PSCR, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_F12, KC_RGUI,
  KC_LSFT, KC_PAUS, KC_BTN1, KC_BTN3, KC_BTN2, KC_APP, KC_MUTE,  S(KC_A),  KC_APP, KC_BTN2, KC_BTN3, KC_BTN1, KC_BSLS, KC_RSFT,
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

#define colorFn        RGB_GREEN
#define colorNum       RGB_RED
#define colorCaps      RGB_RED
#define colorMods      RGB_CYAN
#define colorEn        RGB_ORANGE
#define colorRu        RGB_PURPLE

bool lang;//, change = false;
uint8_t mod_state;
RGB rgb, rgbLast;
// bool isRGBon = false;//, isRGBindicatorsOn = true;

// layer_state_t layer_state_set_user(layer_state_t state) {
    // change = true;
    // return state;
// }

bool rgb_matrix_indicators_user(void) {
    // led_t led_usb_state = host_keyboard_led_state();
    // RGB rgbCurrent;

    // if(change) {
        // change = false;
    
    // if(isRGBon) {
    //     // rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
    //     rgbCurrent.r = rgb.r;
    //     rgbCurrent.g = rgb.g;
    //     rgbCurrent.b = rgb.b;
    // } else {
    //     // rgb_matrix_sethsv_noeeprom(HSV_OFF);
    //     // rgbCurrent.r = 0;
    //     // rgbCurrent.g = 0;
    //     // rgbCurrent.b = 0;
    // }

    // if(isRGBindicatorsOn) {
    // if(isRGBon) {
	if(rgb_matrix_is_enabled()) {
        led_t led_usb_state = host_keyboard_led_state();
        mod_state = get_mods();
        switch (get_highest_layer(layer_state)) {
        case 0:
            // if (rgbCurrent.r != rgbLast.r || rgbCurrent.g != rgbLast.g || rgbCurrent.b != rgbLast.b) {
            if (rgb.r != rgbLast.r || rgb.g != rgbLast.g || rgb.b != rgbLast.b) {
                rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
                rgbLast.r = rgb.r;
                rgbLast.g = rgb.g;
                rgbLast.b = rgb.b;
            }
            break;
        case 1:
                rgb_matrix_set_color(12, colorNum);
                rgb_matrix_set_color(16, colorNum);
                rgb_matrix_set_color(17, colorNum);
                rgb_matrix_set_color(22, colorNum);
                rgb_matrix_set_color(41, colorNum);
                rgb_matrix_set_color(42, colorNum);
                rgb_matrix_set_color(43, colorNum);
                rgb_matrix_set_color(44, colorNum);
                rgb_matrix_set_color(45, colorNum);
                rgb_matrix_set_color(46, colorNum);
                rgb_matrix_set_color(50, colorNum);
                rgb_matrix_set_color(51, colorNum);
                rgb_matrix_set_color(52, colorNum);
                rgb_matrix_set_color(53, colorNum);
            break;
        case 2:
                rgb_matrix_set_color(12, colorFn);
                rgb_matrix_set_color(16, colorFn);
                rgb_matrix_set_color(17, colorFn);
                rgb_matrix_set_color(22, colorFn);
                rgb_matrix_set_color(41, colorFn);
                rgb_matrix_set_color(45, colorFn);
                rgb_matrix_set_color(46, colorFn);
                rgb_matrix_set_color(51, colorFn);
            break;
        // case 3:
            // oled_write_ln_P(PSTR("Adj"), false);
            // break;
        // default:
            // oled_write_ln_P(PSTR("Undef\n"), false);
    }
    if(led_usb_state.caps_lock) {
        rgb_matrix_set_color(8, colorMods);
        rgb_matrix_set_color(8, colorMods);
    } else {
        rgb_matrix_set_color(8, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(8, rgb.r, rgb.g, rgb.b);
    }
    if(mod_state & MOD_MASK_CTRL) {
        rgb_matrix_set_color(0, colorMods);
        rgb_matrix_set_color(29, colorMods);
    } else {
        rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b);
    }
    if(mod_state & MOD_MASK_SHIFT) {
        rgb_matrix_set_color(1, colorMods);
        rgb_matrix_set_color(30, colorMods);
    } else {
        rgb_matrix_set_color(1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
    }
    if(mod_state & MOD_MASK_ALT) {
        rgb_matrix_set_color(9, colorMods);
        rgb_matrix_set_color(38, colorMods);
    } else {
        rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(38, rgb.r, rgb.g, rgb.b);
    }
    if(mod_state & MOD_MASK_GUI) {
        rgb_matrix_set_color(2, colorMods);
    } else {
        rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
    }
    // if(lang || led_usb_state.kana) {
    // if(lang || led_usb_state.scroll_lock) {
    if(lang) {
		rgb_matrix_set_color(25, colorRu);
		// rgb_matrix_set_color(54, colorRu);
    } else {
        rgb_matrix_set_color(25, colorEn);
        // rgb_matrix_set_color(54, colorEn);
    }
    // } else {
        // if (rgbCurrent.r != rgbLast.r || rgbCurrent.g != rgbLast.g || rgbCurrent.b != rgbLast.b) {
        //     rgb_matrix_set_color_all(rgbCurrent.r, rgbCurrent.g, rgbCurrent.b);
        //     rgbLast.r = rgbCurrent.r;
        //     rgbLast.g = rgbCurrent.g;
        //     rgbLast.b = rgbCurrent.b;
        // }
    }
    // }
    return false;
}

void print_status_narrow(void) {
    led_t led_usb_state = host_keyboard_led_state();
    
    oled_set_cursor(0, 1);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR(""), false);
            break;
        case 1:
            if(!led_usb_state.num_lock)
                tap_code(KC_NUM);
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Fn"), false);
            break;
        // case 3:
            // oled_write_ln_P(PSTR("Adj"), false);
            // break;
        // default:
            // oled_write_ln_P(PSTR("Undef\n"), false);
    }
    oled_set_cursor(0, 3);
    if(led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR("Caps"), false);
    } else {
        oled_write_ln_P(PSTR(""), false);
    }
    oled_set_cursor(0, 13);
    // if(lang || led_usb_state.kana) {
    if(lang) {
		    oled_write_ln_P(PSTR("  Ru"), false);
    } else {
		    oled_write_ln_P(PSTR("En"), false);
    }
}

void switchLanguage(void) {
    clear_mods();
	register_code(KC_LSFT);
	register_code(KC_LALT);
    if(lang) {
		tap_code(KC_2);
    } else {
		tap_code(KC_1);
    }
    unregister_code(KC_LSFT);
	unregister_code(KC_LALT);
	set_mods(mod_state);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    // } else {
        // render_logo();
        // print_status_narrow2();
    }
    return true;
}

// void printLanguage(bool print) {
//     oled_set_cursor(0, 13);
//     if(print) {
//         if(lang) {
// 		    oled_write_ln_P(PSTR("  Ru"), false);
//         } else {
// 		    oled_write_ln_P(PSTR("En"), false);
//         }
//     } else {
//         oled_write_ln_P(PSTR(""), false);
//     }
// }

void keyboard_post_init_user(void) {
    lang = false;
    switchLanguage();
	// if (is_keyboard_master())
	// 	printLanguage();
    rgb_matrix_disable();
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // rgb.r = 50;
    // rgb.g = 50;
    // rgb.b = 50;
    rgb_matrix_set_color_all(0, 0, 0);
	// rgb_matrix_sethsv_noeeprom(HSV_OFF);
	// rgb_matrix_set_color_all(100, 100, 100);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Initialize variable holding the binary
    // representation of active modifiers.
    // uint8_t mod_state;
    
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
        
        case KC_COLN:
		{
			if (record->event.pressed) {
                if(lang) {
					if (mod_state & MOD_MASK_SHIFT) {//MOD_MASK_CTRL) {
						// set_mods(MOD_MASK_SHIFT);
						tap_code(KC_6);
					} else {
						set_mods(MOD_MASK_SHIFT);
						tap_code(KC_4);
					}
                } else {
					if (mod_state & MOD_MASK_SHIFT) {//MOD_MASK_CTRL) {
						// set_mods(MOD_MASK_SHIFT);
						tap_code(KC_SCLN);
					} else {
						tap_code(KC_SCLN);
					}
				}
				set_mods(mod_state);
				return false;
				}
			return true;
        }
        
        case KC_RPRN:
		{
			if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {//MOD_MASK_CTRL) {
					// set_mods(MOD_MASK_SHIFT);
					tap_code(KC_9);
				} else {
					set_mods(MOD_MASK_SHIFT);
					tap_code(KC_0);
				}
				set_mods(mod_state);
				return false;
				}
			return true;
        }
        
        case KC_DLR:
		{
			bool l;
			if (record->event.pressed) {
				l = lang;
                if(l) {
                    lang = false;
                    switchLanguage();
                }
                set_mods(MOD_MASK_SHIFT);
				tap_code(KC_4);
                if(l) {
                    lang = true;
                    switchLanguage();
                }
				set_mods(mod_state);
				return false;
				}
			return true;
        }
        
        case KC_AMPR:
		{
			bool l;
			if (record->event.pressed) {
				l = lang;
                if(l) {
                    lang = false;
                    switchLanguage();
                }
                set_mods(MOD_MASK_SHIFT);
				tap_code(KC_7);
                if(l) {
                    lang = true;
                    switchLanguage();
                }
				set_mods(mod_state);
				return false;
				}
			return true;
        }
        
        case KC_DQT:
		{
			bool l;
			if (record->event.pressed) {
				l = lang;
                if(l) {
                    // lang = 1;
                    // switchLanguage();
                // }
                // if (mod_state & MOD_MASK_CTRL) {
					set_mods(MOD_MASK_SHIFT);
					tap_code(KC_2);
				}  else {
                    set_mods(MOD_MASK_SHIFT);
					tap_code(KC_QUOT);
				}
                // if(l == 2) {
                //     lang = 2;
                //     switchLanguage();
                // }
				// set_mods(mod_state);
				return false;
				}
			return true;
        }
                
        case KC_GT:
		{
			bool l;
			if (record->event.pressed) {
				l = lang;
                if(l) {
                    lang = false;
                    switchLanguage();
                }
                if (mod_state & MOD_MASK_SHIFT) {//MOD_MASK_CTRL) {
					// set_mods(MOD_MASK_SHIFT);
					tap_code(KC_COMMA);
				} else {
					set_mods(MOD_MASK_SHIFT);
					tap_code(KC_DOT);
				}
                if(l) {
                    lang = true;
                    switchLanguage();
                }
				set_mods(mod_state);
				return false;
				}
			return true;
        }
        
        case KC_LNG1:
        {
            if (record->event.pressed) {
				lang = !lang;
                switchLanguage();
                // printLanguage(true);
                // change = true;
            } else {
                // printLanguage(false);
            }
            return false;
        }
        
    //     case KC_SCRL:
    //     {
    //         if (record->event.pressed) {
				// lang = !lang;
    //             switchLanguage();
    //             // printLanguage(true);
    //             // change = true;
    //         } else {
    //             // printLanguage(false);
    //         }
    //         return false;
    //     }
        
        // case KC_INT2:
        // {
            // if (record->event.pressed) {
				// lang = !lang;
                // switchLanguage();
                // // printLanguage(true);
                // // change = true;
            // } else {
                // // printLanguage(false);
            // }
            // return true;
        // }
        
    //     case KC_LNG2:
    //     {
    //         if (record->event.pressed) {
				// lang = !lang;
    //             switchLanguage();
    //             // printLanguage(true);
    //         } else {
    //             // printLanguage(false);
    //         }
    //         return false;
    //     }
        
        case KC_1:
        {
            if(mod_state == (MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT))) {
				if (record->event.pressed) {
					lang = false;
					// printLanguage(true);
                    // change = true;
				} else {
					// printLanguage(false);
                }
			}
            return true;
        }
        
        case KC_2:
        {
			if(mod_state == (MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT))) {
				if (record->event.pressed) {
					lang = true;
					// printLanguage(true);
                    // change = true;
				} else {
                    // printLanguage(false);
                }
			}
            return true;
        }
/*
        case KC_WH_D:
		{
            if (mod_state & MOD_MASK_SHIFT) {
                clear_mods();
                if (record->event.pressed) {
					register_code(KC_WH_R);
				} else {
                    unregister_code(KC_WH_R);
                }
				set_mods(mod_state);
                return false;
			}
			return true;
        }
        
        case KC_WH_U:
		{
            if (mod_state & MOD_MASK_SHIFT) {
                clear_mods();
                if (record->event.pressed) {
					register_code(KC_WH_L);
				} else {
                    unregister_code(KC_WH_L);
                }
				set_mods(mod_state);
                return false;
			}
			return true;
        }
*/
        case KC_MS_D:
		{
            if (mod_state & MOD_MASK_SHIFT) {
                clear_mods();
                if (record->event.pressed) {
					register_code(KC_MS_R);
				} else {
                    unregister_code(KC_MS_R);
                }
				set_mods(mod_state);
                return false;
			}
			return true;
        }
        
        case KC_MS_U:
		{
            if (mod_state & MOD_MASK_SHIFT) {
                clear_mods();
                if (record->event.pressed) {
					register_code(KC_MS_L);
				} else {
                    unregister_code(KC_MS_L);
                }
				set_mods(mod_state);
                return false;
			}
			return true;
        }
        
        case RGB_TOG:
        {
            if (record->event.pressed) {
                // if (mod_state & MOD_MASK_SHIFT) {
                //     if(isRGBindicatorsOn) {
                //         isRGBindicatorsOn = false;
                //     } else {
                //         isRGBindicatorsOn = true;
                //     }
                // } else {
				    // if(isRGBon) {
				    if(rgb_matrix_is_enabled()) {
                        // isRGBon = false;
                        // rgb.r = rgbLast.r;
                        // rgb.g = rgbLast.g;
                        // rgb.b = rgbLast.b;
                        // rgb = hsv_to_rgb(rgb_matrix_get_hsv());
                        // rgb_matrix_sethsv_noeeprom(HSV_OFF);
                        rgb_matrix_disable_noeeprom();
                    } else {
                        // isRGBon = true;
                        // rgb_matrix_set_color_all(100, 100, 100);
                        rgb_matrix_enable_noeeprom();
                    }
                // }
                // change = true;
			} else {
                 
            }
            //return true;
            return false;
        }

        // case KC_CAPS:
            // {
                // change = true;
                // return true;
            // }

        case RGB_HUI:
        case RGB_SAI:
        case RGB_VAI:
            {
                // change = true;
                rgb = hsv_to_rgb(rgb_matrix_get_hsv());
                return true;
            }
    }
    return true;
};
