// disconnect keyboard
// make dz60:joey:dfu
// reconnect keyboard while holding space + b
//
// OR
//
// make dz60:joey:dfu
// issue RESET command

#include QMK_KEYBOARD_H

#define _______ KC_TRNS

enum custom_keycodes {
  ESCFN = SAFE_RANGE,
  LANG_TG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0
* ,-----------------------------------------------------------------------------------------.
* |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |     | Bck |
* |-----------------------------------------------------------------------------------------+
* | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    |
* |-----------------------------------------------------------------------------------------+
* | ESCFN   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  | / |  | Shift |Lang Tog|
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  Alt |  GUI |     Space    | Space |   Space    | Alt  | Fn1 |      |App | Ctrl |
* `-----------------------------------------------------------------------------------------'
*/

	LAYOUT_all(
		KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   _______, KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,   KC_E,   KC_R,    KC_T,    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,
		ESCFN,            KC_A,    KC_S,   KC_D,   KC_F,    KC_G,    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,
		KC_LSFT, _______, KC_Z,    KC_X,   KC_C,   KC_V,    KC_B,    KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  _______,  KC_RSFT, LANG_TG,
		KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC,  KC_RALT, MO(1), _______, KC_APP, KC_RCTL),



 /* Layer 1
* ,-----------------------------------------------------------------------------------------.
* | ESC | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     | Del |
* |-----------------------------------------------------------------------------------------+
* |       |Prev |Play |Next |     |     |     |     |     |     |     |     |     |  RESET  |
* |-----------------------------------------------------------------------------------------+
* |         |RGBTG|Vol- |Vol+ |Mute |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |           |     |     |     |     |     |     |     |     |     |           |     |     |
* |-----------------------------------------------------------------------------------------+
* |      |      |      |                |      |             |      |     |     |     |     |
* `-----------------------------------------------------------------------------------------'
*/


  LAYOUT_all(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL,
		_______,          KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______,  RESET,
		_______,          _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

int escfn_down = 0;
int escfn_mod_pressed = 0;
int modded_h_pressed = 0;
int modded_j_pressed = 0;
int modded_k_pressed = 0;
int modded_l_pressed = 0;
int modded_o_pressed = 0;
int modded_sc_pressed = 0;

void modded_key_press(keyrecord_t *record, uint16_t orig, uint16_t modded, int *mod_pressed) {
  if (record->event.pressed) {
    if (escfn_down == 1) {
      escfn_mod_pressed = 1;
      *mod_pressed = 1;
      register_code(modded);
    } else {
      register_code(orig);
    }
  } else {
    if (*mod_pressed == 1) {
      unregister_code(modded);
    } else {
      unregister_code(orig);
    }
    *mod_pressed = 0;
  }
}

void modded_macro_press(keyrecord_t *record, uint16_t orig, char* macro, int *mod_pressed) {
  if (record->event.pressed) {
    if (escfn_down == 1) {
      escfn_mod_pressed = 1;
      *mod_pressed = 1;
      send_string(macro);
    } else {
      register_code(orig);
    }
  } else {
    if (*mod_pressed == 0) {
      unregister_code(orig);
    }
    *mod_pressed = 0;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case ESCFN:
      if (record->event.pressed) {
        escfn_down = 1;
      } else {
        if (escfn_mod_pressed == 0) {
          SEND_STRING(SS_TAP(X_ESCAPE));
        }
        escfn_down = 0;
      }
      escfn_mod_pressed = 0;
      return false;

    case KC_H:
      modded_key_press(record, KC_H, KC_LEFT, &modded_h_pressed);
      return false;

    case KC_J:
      modded_key_press(record, KC_J, KC_DOWN, &modded_j_pressed);
      return false;

    case KC_K:
      modded_key_press(record, KC_K, KC_UP, &modded_k_pressed);
      return false;

    case KC_L:
      modded_key_press(record, KC_L, KC_RIGHT, &modded_l_pressed);
      return false;

    case KC_O:
      modded_macro_press(record, KC_O, SS_LCTRL("a")"o", &modded_o_pressed);
      return false;

    case KC_SCLN:
      modded_macro_press(record, KC_SCLN, SS_LCTRL("a")";", &modded_sc_pressed);
      return false;

    case LANG_TG:
      if (record->event.pressed) {
        send_string(SS_LGUI(SS_LALT(" ")));
      } else {
        // key released
      }
      return false;
  }

  return true;
};
