#include QMK_KEYBOARD_H
#include "../../../lib/rdr_lib/rdr_common.h"

/*
                              Layout Helper

┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ BS  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ ESC │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ ;:  │ '"  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ SHI │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │ ,<  │ .>  │ <u> │ ENT │
├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
│ FN  │ DEL │ CTR │ ALT │ WIN │           │ WIN │ /?  │ <l> │ <d> │ <r> │
└─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // normal layer
    [0] = LAYOUT_tkl_ansi(
        LT(2, KC_TAB),
                 KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPC,
        KC_ESC,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_QUOT,
        MO(3),   KC_LCTL, KC_LGUI,   KC_LALT,  MO(1),           KC_SPC,         MO(1),   KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT
    ),
    // programming layer
    [1] = LAYOUT_tkl_ansi(
        _______, KC_TILD, KC_AT,     KC_PERC,  KC_CIRC,    KC_AMPR,   KC_PAST,  _______, KC_LCBR, KC_RCBR,  _______,  _______,
        _______, KC_EXLM, KC_UNDS,   KC_DLR,   KC_MINUS,   KC_PLUS,   KC_PIPE,  KC_EQUAL,KC_LPRN, KC_RPRN,  _______,  _______,
        _______, _______, _______,   _______,  _______,    _______,   _______,  _______, KC_LBRC, KC_RBRC,  _______,  _______,
        _______, _______, _______,   _______,  _______,           KC_SPC,       _______,   _______, _______,  _______,  _______
    ),
    // number layer
    [2] = LAYOUT_tkl_ansi(
        _______, KC_1,    KC_2,      KC_3,     KC_4,       KC_5,      KC_6,     KC_7,    KC_8,    KC_9,     KC_0,     _______,
        _______, _______, _______,   _______,  _______,    _______,   _______,  _______, _______, _______,  _______,  _______,
        _______, _______, _______,   _______,  _______,    _______,   _______,  _______, _______, _______,  _______,  _______,
        MO(3),   _______, _______,   _______,  _______,           KC_SPC,       _______,   _______, _______,  _______,  _______
    ),
    // system layer
    [3] = LAYOUT_tkl_ansi(
        MD_USB,  MD_BLE1, MD_BLE2,   MD_BLE3,  MD_24G,     KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    RGB_RTOG,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,           U_EE_CLR,       KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
    )
};


// ===============================
// shift backspace to delete
// ===============================

bool process_shift_backspace(uint16_t keycode, keyrecord_t *record) {
    if (keycode != KC_BSPC) return true;

    static bool shift_del_active = false;
    uint8_t mod_state = get_mods();

    if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            bool shift_during_delete = mod_state & MOD_BIT(KC_RSFT);

            if (!shift_during_delete) del_mods(MOD_MASK_SHIFT);
            register_code(KC_DEL);
            shift_del_active = true;
            if (!shift_during_delete) set_mods(mod_state); // reaply mod to keep shifts working after tap
            return false;
        }
    } else {
        if (shift_del_active) {
            unregister_code(KC_DEL);
            shift_del_active = false;
            return false;
        }
    }

    return true;
}

// ===============================
// QMK HOOKS
// ===============================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // const bool shift = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

    if (!process_shift_backspace(keycode, record)) return false;
    if (!record->event.pressed) return true; // the following processors assume keydown

    return true;
}

void keyboard_post_init_user(void) {
    rgblight_disable();
}

