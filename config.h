#pragma once

// ================== PREDEFINED SETTINGS

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR  1151
#define EEPROM_SIZE 1152

#define FEE_PAGE_SIZE (0x200)
#define FEE_PAGE_COUNT (8)

#define FEE_PAGE_BASE_ADDRESS (0x1F000)
#define FEE_MCU_FLASH_SIZE (0x1000)

#define EECONFIG_USER_DATA_SIZE 4

#define EECONFIG_KB_DATA_SIZE 1

#define TRANSIENT_EEPROM_SIZE 4096

// ================== CUSTOM SETTINGS

// HOME ROW MODS
// tapping term in ms (how long until a tap becomes a hold)
#define TAPPING_TERM 200
// Prevent rollover (n down, o down, n up, o up) to trigger mods, if duration lower than tapping term
// #define IGNORE_MOD_TAP_INTERRUPT -> no longer supported, should be default
// Undercut tapping term (n down, o down, o up, n up)
#define TAPPING_FORCE_HOLD
// SEE: https://precondition.github.io/home-row-mods#using-home-row-mods-with-qmk

#define RGB_MATRIX_DEFAULT_ON true
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 0

// UNICODE
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
#define UNICODE_KEY_WINC KC_F13
#define TAP_CODE_DELAY 10 // too fast tap sequences can bring OS / KB key up / down out of sync

