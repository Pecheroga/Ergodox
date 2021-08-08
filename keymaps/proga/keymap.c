#include QMK_KEYBOARD_H

enum layers {
    BASE, // default layer
    RU,  // russian
    SYMB, // symbols
    WASD
};

enum custom_keycodes  {
	MACRO_1 = SAFE_RANGE,
	MACRO_2
};

// #define SHFCAP MT(MOD_LSFT, KC_CAPS)
uint16_t shift_timer = 0;
uint16_t ctrl_timer = 0;

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
  *
  * ,--------------------------------------------------.             ,--------------------------------------------------.
  * |   Esc    | VOL+ | VOL- |  F3  |  F4  |  F5  |   [  |           |   ]  |  F8  |  F9  |  F10 |  F11 |  F12 |   !    |
  * |----------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |   Tab    |   Q  |   W  |   E  |   R  |   T  |   (  |           |   )  |   Y  |   U  |   I  |   O  |   P  |   &    |
  * |----------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |    =     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   "    |
  * |----------+------+------+------+------+------|   {  |           |   }  |------+------+------+------+------+--------|
  * |   LSft   |Ctl(Z)|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |Ctl(?)|RShft(_)|
  * `----------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |  Win   | Lang | LAlt | Up   | Down |                                       | Left | Right|   /  |   \  | ~L1  |
  *   `----------------------------------'                                         `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        | Home |CA Brk|       | CA P |  End   |
  *                                 ,------|------|------|       |------+--------+------.
  *                                 |      |      | PrtSr|       |Cancel|        |      |
  *                                 | Space|L1 Tap|------|       |------| Backsp |Enter |
  *                                 |      |      | Ins  |       | Del  |        |      |
  *                                 `--------------------'       `----------------------'
  */
  [BASE] = LAYOUT_ergodox_pretty(
    // left hand
    KC_ESC,       KC_VOLU,      KC_VOLD,    KC_F3,       KC_F4,   KC_F5,   KC_LBRC,          KC_RBRC,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,         KC_EXLM,
    KC_TAB,       KC_Q,         KC_W,       KC_E,        KC_R,    KC_T,    KC_LPRN,          KC_RPRN,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,           KC_AMPR,
    KC_EQL,       KC_A,         KC_S,       KC_D,        KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,        KC_DQUO,
    KC_LSFT,      CTL_T(KC_Z),  KC_X,       KC_C,        KC_V,    KC_B,    KC_LCBR,          KC_RCBR,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   MACRO_2,        MACRO_1,
    KC_LGUI,      TG(RU),       KC_LALT,    KC_UP,       KC_DOWN,                                                 KC_LEFT, KC_RIGHT, KC_SLSH,  KC_BSLS,        TG(WASD),
                                                                  KC_HOME, LCA(KC_BRK),      LSA(KC_P),  KC_END,
                                                                           KC_PSCR,          LCTL(KC_Z),
                                                          KC_SPC, TT(SYMB),KC_INS,           KC_DEL,     KC_BSPC, KC_ENT
  ),
  /* Keymap 1: Russian
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        |   Щ  |  Ъ   |   Ё  |   Ш  |   Ь  |      |           |      |   Й  |   Э  |      |      |      |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |   Я  |   Ы  |   Е  |   Р  |   Т  |      |           |      |   У  |   Ю  |   И  |   О  |   П  |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |   А  |   С  |   Д  |   Ф  |   Г  |------|           |------|   Х  |   Ж  |   К  |   Л  |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |   З  |   Ч  |   Ц  |   В  |   Б  |      |           |      |   Н  |   М  |      |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [RU] = LAYOUT_ergodox_pretty(
    // left hand
    KC_TRNS,    KC_O,        KC_RBRC,   KC_GRV,   KC_I,     KC_M,     KC_NO,       KC_NO,    KC_Q,     KC_QUOT,   KC_TRNS,       KC_TRNS,       KC_TRNS,           KC_TRNS,
    KC_TRNS,    KC_Z,        KC_S,      KC_T,     KC_H,     KC_N,     KC_TRNS,     KC_TRNS,  KC_E,     KC_DOT,    KC_B,          KC_J,          KC_G,              KC_TRNS,
    KC_TRNS,    KC_F,        KC_C,      KC_L,     KC_A,     KC_U,                            KC_LBRC,  KC_SCLN,   KC_R,          KC_K,          RSFT(KC_4),        RSFT(KC_2),
    KC_TRNS,    KC_P,        KC_X,      KC_W,     KC_D,     KC_COMM,  KC_TRNS,     KC_TRNS,  KC_Y,     KC_V,      RSFT(KC_SLSH), KC_SLSH,       RSFT(KC_7),        KC_TRNS,
    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS,                                             KC_TRNS,   KC_TRNS,       RSFT(KC_BSLS), KC_TRNS,           KC_TRNS,

                                                             KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                                      KC_TRNS,     KC_TRNS,
                                                    KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
  ),
  /* Keymap 2: Symbol Layer
  *
  * ,---------------------------------------------------.           ,--------------------------------------------------.
  * |  RESET  |  F1  |  F2  | MUTE |      |      |  F6  |           |  F7  |      |      |      |      |      |    @   |
  * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
  * |         |      |      |      |  ~   |  $   |      |           |      |   -  |   7  |   8  |   9  |   /  |    |   |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |         |      |      |      |  `   |  %   |------|           |------|   +  |   4  |   5  |   6  |   *  |    '   |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |         |      |      |      |  ^   |  #   |      |           |      |   =  |   1  |   2  |   3  |      |        |
  * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |       |      |      |      |      |                                       |   0  |    . |   ,  |      |      |
  *   `-----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [SYMB] = LAYOUT_ergodox_pretty(
    // left hand
    RESET,   KC_F1,   KC_F2,   KC_MUTE, KC_TRNS, KC_TRNS, KC_F6,       KC_F7,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_AT,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TILD, KC_DLR,  KC_TRNS,     KC_TRNS, KC_MINS, KC_7,    KC_8,    KC_9,     KC_SLSH, KC_PIPE,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_GRV,  KC_PERC,                       KC_PLUS, KC_4,    KC_5,    KC_6,     KC_ASTR, KC_QUOT,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_CIRC, KC_HASH, KC_TRNS,     KC_TRNS, KC_EQL,  KC_1,    KC_2,    KC_3,     KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_0,    KC_DOT,  KC_COMMA, KC_NO,   KC_TRNS,
                                                KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,
                                                          KC_TRNS,     KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
  ),
  /* Keymap 3: Game Layer
  *
  * ,---------------------------------------------------.           ,--------------------------------------------------.
  * |  Esc    |  1   |  2   |  3   |  4   |  5   |      |           |      |      |      |      |      |      |        |
  * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
  * |  TAB    |   Q  |  W   |  E   |  R   |      |      |           |      |      |      |      |      |      |        |   
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |         |   A  |  S   |  D   |  F   |      |------|           |------|      |      |      |      |      |        |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |  Shift  |   Z  |  X   |  C   |  B   |      |      |           |      |      |      |      |      |      |        |
  * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   | Ctrl  |      |   I  |   M  | Alt  |                                       |      |      |      |      |  WASD  |
  *   `-----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |Space |Enter |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [WASD] = LAYOUT_ergodox_pretty(
    // left hand
    KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,   KC_NO,  KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_NO,   KC_A,  KC_S,  KC_D,  KC_F,   KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_TRNS, KC_Z,  KC_X,  KC_C,  KC_B,   KC_NO,  KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_LCTL, KC_NO, KC_I,  KC_M,  KC_LALT,                                        KC_NO, KC_NO,  KC_NO, KC_NO,  KC_TRNS,
                                           KC_NO, KC_NO,     KC_NO, KC_NO,
                                                  KC_NO,     KC_NO,
                                  KC_TRNS, KC_ENT,KC_NO,     KC_NO, KC_NO, KC_NO
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TG(RU):
      if (record->event.pressed) {
        tap_code16(LALT(KC_LSFT));
      }
      return true;
    case MACRO_1:
      if (record->event.pressed) {
        shift_timer = timer_read();
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
        if (timer_elapsed(shift_timer) < TAPPING_TERM) {
          tap_code16(RSFT(KC_UNDS));
        } 
      } 
      return true;
    case MACRO_2:
      if (record->event.pressed) {
        ctrl_timer = timer_read();
        register_code(KC_RCTL);
      } else {
        unregister_code(KC_RCTL);
        if (timer_elapsed(ctrl_timer) < TAPPING_TERM) {
          tap_code16(KC_QUES);
        } 
      } 
      return true;
    default:
      return true;
  }
}

void keyboard_pre_init_user(void) {
  setPinOutput(D4);  // initialize D4 for LED
  setPinOutput(D1);  // initialize D1 for LED
  setPinOutput(D2);  // initialize D2 for LED
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case BASE:
        writePinHigh(D4);
        writePinLow(D1);
        writePinLow(D2);
        break;
    case RU:
        writePinLow(D4);
        writePinLow(D1);
        writePinHigh(D2);
        break;
    case SYMB:
        writePinLow(D4);
        writePinHigh(D1);
        writePinLow(D2);
        break;
    case WASD:
        writePinHigh(D4);
        writePinHigh(D1);
        writePinHigh(D2);
        break;
    default:
        writePinLow(D4);
        writePinLow(D1);
        writePinLow(D2);
        break;
  }
  return state;
}
