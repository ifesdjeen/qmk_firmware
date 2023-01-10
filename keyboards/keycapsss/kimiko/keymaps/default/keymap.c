/* Copyright 2019 Leo Batyuk 
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
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

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Home row modifiers
#define LCTL_A    LCTL_T(KC_A)
#define LOPT_S    LOPT_T(KC_S)
#define LCMD_D    LCMD_T(KC_D)
#define SHFT_F    LSFT_T(KC_F)
#define RSFT_J    RSFT_T(KC_J)
#define RCMD_K    RCMD_T(KC_K)
#define ROPT_L    LOPT_T(KC_L)
#define RCTL_SCLN RCTL_T(KC_SCLN)

#define SFT_SPC    LSFT_T(KC_SPC)
#define SFT_ENT    RSFT_T(KC_ENT)

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define LWR_DEL (LT(_LOWER, KC_DEL))
#define RSE_BS (LT(_RAISE, KC_BSPC))
#define LCS(kc) (QK_LCTL | QK_LSFT | kc)
#define LCSG(kc) (QK_LCTL | QK_LSFT | QK_LGUI | kc)
#define BTT(kc) (QK_LCTL | QK_LSFT | QK_LGUI | QK_LALT | kc)
#define LGS(kc) (QK_LGUI | QK_LSFT | kc)
#define LAS(kc) (QK_LALT | QK_LSFT | kc)
//#define KC_LT (LCS(KC_COMM))
//#define KC_GT (LCS(KC_DOT))
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `        |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [        |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  RShift   |
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LGUI  | LALT | DEL |LOWER| Space /       \Enter \ RAISE|BackSP| RGUI | RALT |
 *                 `----------------------------------'       '----------------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    //KC_LCTRL, LCTL_A, LOPT_S,  LCMD_D,  SHFT_F,  KC_G,                        KC_H,    RSFT_J,  RCMD_K,  ROPT_L,  RCTL_SCLN,KC_QUOT,
    KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   LGS(KC_T),LGUI(KC_W),KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      XXXXXXX, KC_LALT, KC_LGUI, LOWER,   KC_SPC,   SFT_ENT,   RAISE,   KC_BSPC, XXXXXXX, XXXXXXX
),
/* LOWER
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |    `   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   _  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |      |   1  |   2  |   3  |   |  |                    |   (  |   )  |   `  |   \  |   +  |      |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |      |   4  |   5  |   6  |   -  |-------.    ,-------|   {   |  }  |   ~  |   /  |   =  |   "  |
 * |--------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |        |      |      |   0  |      |   _  |-------|    |-------|   [  |   ]  |   <  |   >  |   ?  |      |
 * `-------------------------------------------|       /     \      \-----------------------------------------'
 *                 | LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '-------------------------------------'
 */

 [_LOWER] = LAYOUT(
    KC_GRAVE,KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
    XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PIPE,                   KC_LPRN, KC_RPRN, KC_GRAVE,KC_BSLS, KC_PLUS, KC_PIPE,
    XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_MINS,                   KC_LCBR, KC_RCBR, KC_TILD, KC_SLSH, KC_EQL,  KC_DQUO,
    _______, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_UNDS, XXXXXXX,LGS(KC_T),KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   KC_QUES, _______,
                      XXXXXXX, KC_0,    XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, LALT(KC_BSPC), XXXXXXX, XXXXXXX
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *               |      |      |      |     |       /       \      \     |      |      |      |      |
 *               `---------------------------------'         '---------------------------------------'
 */
// Copy and paste (mac os x style)
#define OP_COPY LGUI(KC_C)
#define OP_PASTE LGUI(KC_V)
// Beginning and end of the file (emacs style)
#define OP_TOP LAS(KC_LT)
#define OP_BOT LAS(KC_GT)
// Beginning and end of the line (emacs style)
#define OP_BEG LCTL(KC_A)
#define OP_END LCTL(KC_E)
[_RAISE] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_PGUP, OP_TOP,  OP_BEG,  _______, _______,                     _______, _______, KC_UP,   _______, _______, _______,
    _______, KC_PGDN, OP_BOT,  OP_END,  _______, _______,                     _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,
    _______, _______, _______, OP_COPY, OP_PASTE, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, 
                      _______, _______, _______, _______,  KC_DEL, _______,  _______, _______, _______, _______
),
/* ADJUST (Press LOWER and RAISE together)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RESET |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBON| HUE+ | SAT+ | VAL+ |      |      |                    | PREV | PLAY | NEXT |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MODE | HUE- | SAT- | VAL- |      |      |-------.    ,-------| VOL+ | MUTE | VOL- |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 |LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_ADJUST] = LAYOUT(
    _______,      _______,   _______,   _______, KC_MUTE,   _______,                     _______,   _______,       _______,       _______,        _______, _______,
    RGB_TOG,      BTT(KC_Q), _______,   KC_BRMU, BTT(KC_R), BTT(KC_T),                   _______,   _______,       LALT(KC_UP),   _______,        _______, _______,
    LCSG(KC_SPC), BTT(KC_A), BTT(KC_S), KC_BRMD, KC_VOLU,   BTT(KC_G),                   _______,   LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_RIGHT), _______, _______,
    _______,      _______,   _______,   _______, KC_VOLD,   BTT(KC_B), _______, _______, BTT(KC_N), BTT(KC_M),     _______,       _______,        _______, _______,
                             _______,   _______, _______,   _______,   _______, _______, _______,   _______,       _______,       _______
  )
};

/* EMPTY LAYOUT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *               |      |      |      |     |       /       \      \     |      |      |      |      |
 *               `---------------------------------'         '---------------------------------------'
 */

enum combos {
  SEB
};

const uint16_t PROGMEM seb_combo[] = {KC_SPC, KC_ENT, KC_1, KC_2, COMBO_END}; // disable this combo just for now

combo_t key_combos[COMBO_COUNT] = {
  [SEB] = COMBO(seb_combo, KC_BSPC)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(corne_logo, false);
    // oled_write_P(PSTR("Kimiko"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
}

#endif


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    // Encoder on slave side
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            // If the Default (QWERTY) layer is active
            case _QWERTY:
                // Undo and redo
                if (clockwise) {
                    tap_code16(LCTL(KC_SLSH));
                } else {
                    tap_code16(LCS(KC_SLSH));
                }
                break;
            // If the RAISE layer is active
            case _RAISE:
                // Cycle applications
                if (clockwise) {
                    tap_code16(LCTL(KC_LEFT));
                } else {
                    tap_code16(LCTL(KC_RIGHT));
                }
                break;
            // If the ADJUST layer is active
            case _ADJUST:
                if (clockwise) {
                    tap_code16(KC_VOLD);
                } else {
                    tap_code16(KC_VOLU);
                }
                break;
        }
    }
    // Encoder on master side
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            // If the Default (QWERTY) layer is active
            case _QWERTY:
                // Page up and page down
                if (clockwise) {
                    tap_code16(KC_PGDN);
                } else {
                    tap_code16(KC_PGUP);
                }
                break;
            // If the LOWER layer is active
            case _LOWER:
                // Browser tabs forward and backward
                if (clockwise) {
                    tap_code16(LCTL(KC_TAB));
                } else {
                    tap_code16(LCS(KC_TAB));
                }
                break;

            // If the ADJUST layer is active
            case _ADJUST:
                // RGB hue up/down
                if (clockwise) {
		  tap_code16(KC_BRMU);
                } else {
		  tap_code16(KC_BRMD);
                }
                break;
        }
    }
}
#endif // ENCODER_ENABLE
