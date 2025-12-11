#include QMK_KEYBOARD_H
#include "../../../lib/rdr_lib/rdr_common.h"

enum User_Layers {
    LDEF, // DEFault layer
    LDEV, // DEVelopment layer
    LNUM, // NUMber layer
    LFUN, // FUNction layer
    LNAV, // NAVigation layer
};

enum User_Keycodes {
    U_MAC  /* switch to mac */ = CHOSFOX_USER_DEFINE_KEY + 1,
    U_WIN, // switch to win
    U_DIAR,// Diaresis
    U_MU   // Greek Mu
};

enum HomeRowModKeyCodes {
    HMKC_A = LGUI_T(KC_A),
    HMKC_S = LALT_T(KC_S),
    HMKC_D = LCTL_T(KC_D),
    HMKC_F = LSFT_T(KC_F),
    HMKC_J = RSFT_T(KC_J),
    HMKC_K = RCTL_T(KC_K),
    HMKC_L = LALT_T(KC_L),
    HMKC_SCLN = RGUI_T(KC_SCLN)
};

enum Unicode_Characters {
    UC_AE = 0xC4,
    UC_ae = 0xE4,
    UC_UE = 0xDC,
    UC_ue = 0xFC,
    UC_OE = 0xD6,
    UC_oe = 0xF6,

    UC_MU = 0x39C,
    UC_mu = 0x3BC,
};

/*
                              Layout Helper

┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ BS  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ ESC │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ ;:  │ ENT │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ SHI │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │ ,<  │ .>  │ /?  │ '"  │
├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
│ CTR │ WIN │ FN  │ ALT │ -v  │           │ -v  │ <l> │ <d> │ <u> │ <r> │
└─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LDEF] = LAYOUT_tkl_ansi(
        LT(LNUM, KC_TAB),
                 KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Z,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSPC,
        KC_ESC,  HMKC_A,  HMKC_S,    HMKC_D,   HMKC_F,     KC_G,      KC_H,     HMKC_J,   HMKC_K,   HMKC_L,   HMKC_SCLN, KC_ENT,
        KC_LSFT, KC_Y,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_QUOT,
        KC_LCTL, KC_LGUI, MO(LFUN),  KC_LALT,  MO(LDEV),   LT(LNAV, KC_SPC),    MO(LDEV), KC_LEFT,  KC_DOWN,  KC_UP,     KC_RGHT
    ),
    [LDEV] = LAYOUT_tkl_ansi(
        KC_GRAVE,KC_TILD, KC_AT,     KC_PERC,  KC_CIRC,    KC_AMPR,   KC_PAST,  U_DIAR,   KC_LCBR,  KC_RCBR,  _______,   _______,
        _______, KC_EXLM, KC_UNDS,   KC_DLR,   KC_MINUS,   KC_PLUS,   KC_PIPE,  KC_EQUAL, KC_LPRN,  KC_RPRN,  _______,   _______,
        _______, KC_BSLS, KC_SLASH,  KC_HASH,  _______,    _______,   _______,  U_MU,     KC_LBRC,  KC_RBRC,  _______,   _______,
        _______, _______, _______,   _______,  _______,          _______,       _______,  _______,  _______,  _______,   _______
    ),
    [LNUM] = LAYOUT_tkl_ansi(
        _______, KC_1,    KC_2,      KC_3,     KC_4,       KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      _______,
        _______, KC_F1,   KC_F2,     KC_F3,    KC_F4,      KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    _______,
        _______, KC_F11,  KC_F12,    _______,  _______,    _______,   _______,  _______,  _______,  _______,  _______,   _______,
        _______, _______, MO(LFUN),  _______,  _______,          _______,       _______,  _______,  _______,  _______,   _______
    ),
    [LNAV] = LAYOUT_tkl_ansi(
        _______, KC_NO,   KC_NO,     KC_BSPC,  KC_DEL,     KC_NO,     KC_NO,    KC_HOME,  KC_NO,    KC_END,   KC_NO,     _______,
        _______, KC_LGUI, KC_LALT,   KC_LCTL,  KC_LSFT,    KC_NO,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,     KC_NO,
        _______, KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_PGUP,  KC_NO,    KC_PGDN,  KC_NO,     KC_NO,
        _______, _______, _______,   _______,  _______,           KC_NO,        _______,  _______,  _______,  _______,   _______
    ),
    [LFUN] = LAYOUT_tkl_ansi(
        MD_USB,  MD_BLE1, MD_BLE2,   MD_BLE3,  MD_24G,     KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     QK_BOOT,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     U_WIN,    U_MAC,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,           U_EE_CLR,       KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO
    ),
};

// ===============================
// Mac - Windows Switching
// ===============================

static bool is_mac = false;

bool process_mac_win_switch(uint16_t keycode, keyrecord_t *record) {

    if (keycode == U_MAC) {
        is_mac = true;
        return false;
    } else if (keycode == U_WIN) {
        is_mac = false;
        return false;
    }

    return true;
}

// ===============================
// Diaeresis
// ===============================

// MacOS US-Keyboard Style diaeresis on MacOS _and_ Windows
bool process_diaeresis(uint16_t keycode, bool shift) {
    static bool diaeresis = false;

    if (keycode == U_DIAR) {
        diaeresis = !diaeresis;
        if (diaeresis && is_mac) {
            register_mods(MOD_MASK_ALT);
            tap_code(KC_U);
            unregister_mods(MOD_MASK_ALT);
        }
        return false;
    }

    if (!diaeresis) return true;

    if (is_mac) {
        diaeresis = false;
        return true;
    }

    keycode = keycode & 0xFF; // remove modifiers from keycode
    if (keycode == KC_A || keycode == KC_O || keycode == KC_U) {
        if (keycode == KC_A && shift) register_unicode(UC_AE);
        if (keycode == KC_A && !shift) register_unicode(UC_ae);
        if (keycode == KC_U && shift) register_unicode(UC_UE);
        if (keycode == KC_U && !shift) register_unicode(UC_ue);
        if (keycode == KC_O && shift) register_unicode(UC_OE);
        if (keycode == KC_O && !shift) register_unicode(UC_oe);
        diaeresis = false;
        return false;
    } else if (!IS_MODIFIER_KEYCODE(keycode)) {
        diaeresis = true;
    }

    return true;
}

// ===============================
// Custom Letters
// ===============================

// Custom Letters, such as Greek ones, which upper and lower casing
bool process_custom_letters(uint16_t keycode, bool shift) {
    if (keycode == U_MU) {
        if (is_mac) {
            register_mods(MOD_MASK_ALT);
            tap_code(KC_M);
            unregister_mods(MOD_MASK_ALT);
        } else {
            if (shift) register_unicode(UC_MU);
            else register_unicode(UC_mu);
        }
        return false;
    }

    return true;
}

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

            if (!shift_during_delete) unregister_mods(MOD_MASK_SHIFT);
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
    const bool shift = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

    if (!process_shift_backspace(keycode, record)) return false;
    if (!record->event.pressed) return true; // the following processors assume keydown
    if (!process_mac_win_switch(keycode, record)) return false;
    if (!process_custom_letters(keycode, shift)) return false;
    if (!process_diaeresis(keycode, shift)) return false;

    return true;
}

bool rgb_matrix_indicators_user(void) {
    // light m or n, depending on Mac or Windows mode
    if (is_mac) { rgb_matrix_set_color(31, 255, 255, 255); }
    else { rgb_matrix_set_color(30, 255, 255, 255); }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

void keyboard_post_init_user() { }

