#include QMK_KEYBOARD_H

// Home row mods
#define A_LCTL LCTL_T(KC_A)
#define S_LOPT LOPT_T(KC_S)
#define D_LCMD LCMD_T(KC_D)
#define F_LSFT LSFT_T(KC_F)
#define V_HYPR HYPR_T(KC_V)
#define M_HYPR HYPR_T(KC_M)
#define J_RSFT RSFT_T(KC_J)
#define K_RCMD RCMD_T(KC_K)
#define L_ROPT ROPT_T(KC_L)
#define SCLN_RCTL RCTL_T(KC_SCLN)

// To prevent skipping steps
#define ENCODER_RESOLUTION 2

// Configure the global tapping term (default: 200ms)
//#define TAPPING_TERM 120

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD
