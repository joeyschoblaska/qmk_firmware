#include QMK_KEYBOARD_H

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0
* ,-----------------------------------------------------------------------------------------.
* |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
* |-----------------------------------------------------------------------------------------+
* | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  RShift   | RGB |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  Alt |  GUI |    Space    |  Space  |   Space   |  Alt |  Fn1  |  App  |  Ctrl  |
* `-----------------------------------------------------------------------------------------'
*/

	LAYOUT_all(
		KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,   KC_E,   KC_R,    KC_T,    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,
		KC_CAPS,          KC_A,    KC_S,   KC_D,   KC_F,    KC_G,    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,
		KC_LSFT, _______, KC_Z,    KC_X,   KC_C,   KC_V,    KC_B,    KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  RGB_TOG,
		KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC,  KC_RALT, MO(1), KC_APP,  KC_RCTL),



 /* Layer 1
* ,-----------------------------------------------------------------------------------------.
* | Esc | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     Del   |
* |-----------------------------------------------------------------------------------------+
* |       |Prev |Play |Next |     |     |     |     |     |     |     |     |     |         |
* |-----------------------------------------------------------------------------------------+
* |         |     |Vol- |Vol+ |Mute |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |           |     |     |     |     |     |     |     |     |     |           |           |
* |-----------------------------------------------------------------------------------------+
* |      |      |      |                |      |             |      |     |        |        |
* `-----------------------------------------------------------------------------------------'
*/


  LAYOUT_all(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
		_______,          KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};
