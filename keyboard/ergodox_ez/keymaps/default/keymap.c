#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_dvorak.h"


#define BASE 0      // qwerty layer
#define LY1 1       // qwerty symbols

#define LY2_NA 2    // dvorak layer
#define LY3_NA 3    // dvorak symbols

#define LY4_NA 4
#define LY5_NA 5
#define LY6_NA 6
#define LY7_NA 7
#define LY8_NA 8

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE: QWERTY
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | ESC  |           | MUTE |   6  |   7  |   8  |   9  |   0  |   ]    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Tab  |           | BkSp |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           | Enter|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | ESC@S|                                       | RGui |      |   -  |   =  |   \  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Mute | PScrn|       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       | [L1] |        |      |
 *                                 | Space| LCtrl|------|       |------|  Tab   |Enter |
 *                                 |      |      | LAlt |       | [L0] |        |      |
 *                                 `--------------------'       `----------------------'
 */
 
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        _dv_GRV,         _dv_1,     _dv_2,     _dv_3,   _dv_4,   _dv_5,   KC_ESC,
        KC_TAB,         _dv_QUOT,  _dv_COMM,  _dv_DOT, _dv_P,   _dv_Y,   KC_TAB,
        KC_LCTL,        _dv_A,     _dv_O,     _dv_E,   _dv_U,   _dv_I,
        KC_LSFT,        _dv_SCLN,  _dv_Q,     _dv_J,   _dv_K,   _dv_X,   0,
        0,              0,        0,        0,      LT(LY1, KC_ESC),
                                                    KC_MUTE,  KC_PSCR,
                                                                    0,
                                             KC_SPC, KC_LCTL, KC_LALT,
        // right hand
             KC_MUTE,   _dv_6,   _dv_7,   _dv_8,   _dv_9,   _dv_0,    _dv_EQL,
             KC_BSPC,   _dv_F,   _dv_G,   _dv_C,   _dv_R,   _dv_L,    _dv_SLSH,
                        _dv_D,   _dv_H,   _dv_T,   _dv_N,   _dv_S,    _dv_MINS,
             KC_ENT,    _dv_B,   _dv_M,   _dv_W,   _dv_V,   _dv_Z,    KC_RSFT,
                                         KC_RGUI, 0, _dv_LBRC, _dv_RBRC, 0,
             HID_KEYBOARD_SC_LANG1,   0x04,
             TG(LY1),
             TG(BASE), KC_TAB, KC_ENT
    ),
    
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Mute |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | Vol  |      | PgUp |  Up  | PgDn |      |   F12  |
 * |--------+------+------+------+------+------|      |           | Up   |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           | Vol  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | Down |      |      | MsUp |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET|      |      |      |      |                                       |MsLeft|MsDown|MsRght|      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Lclk | Rclk |
 *                                 |      |      |      |       |[BASE]|      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[LY1] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RESET,   DEBUG,   KC_TRNS, KC_TRNS, KC_TRNS, 
                                        KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_MUTE, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_VOLU, KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS, KC_F12,
                KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_VOLD, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       TG(LY2_NA),
       DF(BASE), KC_BTN1, KC_BTN2
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[LY2_NA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       TG(BASE), KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(LY1)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case BASE:
            ergodox_right_led_1_on();
            break;
        case LY1:
            ergodox_right_led_2_on();
            break;
        case LY2_NA:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
