/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_F     , KC_P     , KC_B     ,                            KC_J     , KC_L     , KC_O     , KC_Y     , KC_:     ,
    KC_A     , KC_R     , KC_S     , KC_T     , KC_G     ,                            KC_M     , KC_N     , KC_E     , KC_I     , KC_U  ,
    KC_Z     , KC_X     , KC_C     , KC_C     , KC_V     ,                            KC_K     , KC_H     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC   , AML_TO   , KC_DEL  ,LT(1, KC_BSPC),LT(2,KC_ENTER),TG(4),KC_TAB,LT(2,KC_SPACE),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, SCRL_MO
  ),

  [1] = LAYOUT_universal(
    XXXXXXX  , KC_LSFT  , KC_RCTL  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , LALT(KC_LEFT), KC_UP, LALT(KC_RIGHT) , XXXXXXX  ,
    XXXXXXX  , MS_BTN2  , MS_BTN3  , MS_BTN2  , XXXXXXX  ,                            KC_HOME  , KC_LEFT  , KC_DOWN  , KC_RIGHT , KC_END   ,
    XXXXXXX  ,LALT(KC_F4),LCTL(W)   ,LCTL(KC_T), _______ ,                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  , _______  , XXXXXXX  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
  ),

  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

const uint16_t PROGMEM test_combo1[] = {KC_E, KC_H, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_F, KC_T, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_BSPC),
    COMBO(test_combo2, KC_ENTER), // keycodes with modifiers are possible too!
};

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
