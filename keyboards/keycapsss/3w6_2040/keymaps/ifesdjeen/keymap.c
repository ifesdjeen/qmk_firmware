// Copyright 2021 weteor | 2022 Conor Burns (@Conor-Burns)
// Copyright 2023 Ben Roe (@keycapsss)
// Copyright 2023 Tom Barnes (@keyboard-magpie)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layers {
    _QWERTY = 0,
    _SYM,
    _NAV,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off

    [_QWERTY] = LAYOUT_split_3x5_3(
       KC_Q,           KC_W,         KC_E,         KC_R,         KC_T,                                                  KC_Y,            KC_U,            KC_I,           KC_O,            KC_P,
       LCTL_T(KC_A),   LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,                                                  KC_H,            LSFT_T(KC_J),    LGUI_T(KC_K),   LALT_T(KC_L),    LCTL_T(KC_SCLN),
       KC_Z,           KC_X,         KC_C,         KC_V,         KC_B,                                                  KC_N,            KC_M,            KC_COMM,        KC_DOT,          KC_SLSH,
                                   LCTL_T(KC_ESC), MO(1),        KC_SPC,                                                KC_ENT,          MO(2),           LALT_T(KC_DEL)
    ),
    [_SYM] = LAYOUT_split_3x5_3(
       KC_ESC,         KC_1,         KC_2,         KC_3,         KC_PIPE,                                               KC_LPRN,         KC_RPRN,         KC_GRV,         KC_BSLS,         KC_UNDS,
       KC_TAB,         KC_4,         KC_5,         KC_6,         KC_MINS,                                               KC_LCBR,         KC_RCBR,         KC_TILD,        KC_SLSH,         KC_PIPE,
       KC_0,           KC_7,         KC_8,         KC_9,         KC_UNDS,                                               KC_LBRC,         KC_RBRC,         KC_COMM,        KC_DOT,          KC_DQUO,
                                     KC_NO,        KC_NO,        KC_NO,                                                 KC_BSPC,         KC_NO,           KC_NO
    ),
    [_NAV] = LAYOUT_split_3x5_3(
       KC_NO,          KC_EXLM,      KC_AT,        KC_HASH,      KC_NO,                                                 KC_PGUP,         KC_HOME,         KC_UP,          KC_END,          KC_VOLU,
       KC_NO,          KC_DLR,       KC_PERC,      KC_CIRC,      KC_NO,                                                 KC_PGDN,         KC_LEFT,         KC_DOWN,        KC_RGHT,         KC_VOLD,
       KC_NO,          KC_AMPR,      KC_ASTR,      KC_DQUO,      KC_NO,                                                 LCTL(KC_SLSH),   LSFT(KC_SLSH),   LCTL(KC_LEFT),  LCTL(KC_RGHT),   KC_NO,
                                     KC_NO,        KC_NO,        KC_NO,                                                 KC_DEL,          KC_NO,           KC_NO
    ),
    [_ADJUST] = LAYOUT_split_3x5_3(
       KC_F1,          KC_F2,        KC_F3,        KC_F4,        KC_NO,                                                 KC_NO,           KC_NO,           KC_NO,          KC_BRIU,         KC_VOLU,
       KC_F5,          KC_F6,        KC_F7,        KC_F8,        KC_NO,                                                 KC_NO,           KC_NO,           KC_NO,          KC_BRID,         KC_VOLD,
       KC_F9,          KC_F10,       KC_F11,       KC_F12,       KC_NO,                                                 KC_NO,           KC_NO,           KC_NO,          KC_LCAP,         KC_MUTE,
                                     KC_NO,        KC_NO,        KC_NO,                                                 KC_NO,           KC_NO,           KC_NO
    ),
};
