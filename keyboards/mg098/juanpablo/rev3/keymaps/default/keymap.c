// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "analog.h"
#include "quantum.h"

#include <string.h>
#include <stdio.h>
#include <transactions.h>
#include <math.h>
#ifdef BLUETOOTH_ENABLE
    #include "outputselect.h"
    #include "bluefruit_le.h"
#endif

enum layers {
    _MAIN,
    _FN
};
enum my_keycodes {
  NEXT = SAFE_RANGE,
  PREV,
  CHINA,
  };

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

char BatteryVoltage[26] = {0};

typedef struct _master_to_slave_t {
    float ADC_Readout;
} master_to_slave_t;





/* LAYER = MAIN
    ╔════╤════╤════╤════╤════╤════╤════╗    ╔════╤════╤════╤════╤════╤════╤════════╤════╗
    ║ `  │ 1  │ 2  │ 3  │ 4  │ 5  │ 6  ║    ║ 7  │ 8  │ 9  │ 0  │ -  │ =  │ BCKSPC │DEL ║
    ╟────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─╦══╝ ╔══╩─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──────┼────╢
    ║ TAB  │ Q  │ W  │ E  │ R  │ T  ║    ║ Y  │ U  │ I  │ O  │ P  │ [  │ ]  │  \   │PGUP║
    ╟──────┴┬───┴┬───┴┬───┴┬───┴┬───╩╗   ╚╦───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴──────┼────╢
    ║ CAPS  │ A  │ S  │ D  │ F  │ G  ║    ║ H  │ J  │ K  │ L  │ ;  │ '  │  ENTER   │PGDN║
    ╟───────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──╩═╗  ╚═╦──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─────┬────┼────╢
    ║ SHIFT   │ Z  │ X  │ C  │ V  │ B  ║    ║ N  │ M  │ ,  │ .  │ /  │  SHIFT │ UP │END ║
    ╟─────┬───┴─┬──┴──┬─┴────┴────┴──╦═╝  ╔═╩────┴────┴──┬─┴───┬┴───┬┴───┬────┼────┼────╢
    ║ CTRL│ WIN │ ALT │    SPACE     ║    ║     SPACE    │ ALT │ FN │CTRL│LEFT│DOWN│RGHT║
    ╚═════╧═════╧═════╧══════════════╝    ╚══════════════╧═════╧════╧════╧════╧════╧════╝
  */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_MAIN] = LAYOUT_split_69(

     QK_GESC, KC_1,    KC_2,    KC_3,   KC_4,  KC_5,   KC_6,          KC_7,  KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
     KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,           KC_Y,  KC_U,  KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
     KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,  KC_G,                  KC_H,  KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN,
     KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,                  KC_N,  KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
     KC_LCTL, KC_LWIN, KC_LALT, KC_SPC,                                      KC_SPC, KC_RALT, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

/* LAYER = FUNCTION
    ╔════╤════╤════╤════╤════╤════╤════╗    ╔════╤════╤════╤════╤════╤════╤════════╤════╗
    ║BOOT│ F1 │ F2 │ F3 │ F4 │ F5 │ F6 ║    ║ F7 │ F8 │ F9 │F10 │F11 │F12 │        │    ║
    ╟────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─╦══╝ ╔══╩─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──────┼────╢
    ║      │    │    │    │    │TOGG║    ║    │    │    │    │    │    │    │      │NEXT║
    ╟──────┴┬───┴┬───┴┬───┴┬───┴┬───╩╗   ╚╦───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴──────┼────╢
    ║       │    │SATU│    │    │    ║    ║    │    │    │    │    │    │          │PREV║
    ╟───────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──╩═╗  ╚═╦──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─────┬────┼────╢
    ║         │    │    │    │    │    ║    ║    │MOD │    │    │    │        │BRUP│    ║
    ╟─────┬───┴─┬──┴──┬─┴────┴────┴──╦═╝  ╔═╩────┴────┴──┬─┴───┬┴───┬┴───┬────┼────┼────╢
    ║     │     │     │              ║    ║              │     │ FN │    │SPDN│BRDN│SPUP║
    ╚═════╧═════╧═════╧══════════════╝    ╚══════════════╧═════╧════╧════╧════╧════╧════╝
  */



  [_FN] = LAYOUT_split_69(
     QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, CHINA,
     _______, _______, _______, _______, _______, RGB_TOG,       _______, _______, _______, _______, _______, _______, _______, _______, NEXT,
     _______, _______, RGB_SAI, _______, _______, _______,                RGB_HUI, _______, _______, _______, _______, _______, _______, PREV,
     _______, _______, _______, _______, _______, _______,                _______, RGB_MOD, _______, _______, _______, _______, RGB_VAI, _______,
     _______, _______, _______, _______,                                           _______, _______, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
  )
};

#ifdef SPLIT_KEYBOARD
void housekeeping_task_user(void){
    if (is_keyboard_master()) {
        // Interact with slave every 500ms
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 500) {
            float temp = analogReadPin(GP29);
            master_to_slave_t ADC_Readout = {temp};
            if(transaction_rpc_send(BATTERY_SYNC, sizeof(ADC_Readout), &ADC_Readout)) {
                last_sync = timer_read32();
                //dprintf("Slave value: %d\n", s2m.s2m_data); // this will now be 11, as the slave adds 5
            } else {
                dprint("Slave sync failed!\n");
            }
        }
    }
}

void Battery_sync_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *Readout = (const master_to_slave_t*)in_data;
    float tmpVal = 0;
    tmpVal = Readout->ADC_Readout;
    int tmpInt1 = tmpVal;                  // Get the integer
    float tmpFrac = tmpVal - tmpInt1;      // Get fraction
    int tmpInt2 = trunc(tmpFrac * 100);
    static char BatteryVoltage[26] = {0};
    snprintf(BatteryVoltage, sizeof(BatteryVoltage), "%d.%02d V", tmpInt1, tmpInt2);
}

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    transaction_register_rpc(BATTERY_SYNC, Battery_sync_slave_handler);
}
#endif
/*
void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
}
*/

#ifdef BLUETOOTH_ENABLE
    #ifdef DIP_SWITCH_ENABLE
    bool dip_switch_update_user(uint8_t index, bool active) {
        switch (index) {
            case 0:
                if(active) { set_output(OUTPUT_BLUETOOTH); } else {  }
                break;
            case 1:
                if(active) { set_output(OUTPUT_USB); } else {  }
                break;
        }
        return true;
    }
    #endif
#endif

// #ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {       //add more options based on FN layer
     if (get_highest_layer(layer_state|default_layer_state) == 0) {  //main layer
        if (index == 0) { /* First encoder */
            if (clockwise) {
                tap_code_delay(KC_VOLU, 10);
            } else {
                tap_code_delay(KC_VOLD, 10);
            }
        } else if (index == 1) { /* Second encoder */
            #ifdef RGB_MATRIX_ENABLE
            if (clockwise) {
                rgb_matrix_increase_hue();
            } else {
                rgb_matrix_decrease_hue();
            }
            #endif
        }
    } else {    //second layer
        if (index == 0) { /* First encoder */
            if (clockwise) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(KC_TAB);
            } else {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
            alt_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
            }
        } else if (index == 1) { /* Second encoder */
            if (clockwise) {
                tap_code16(C(KC_TAB));
            } else {
                tap_code16(S(C(KC_TAB)));
            }
        }
    }
        return false;
}
// #endif

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

#ifdef OLED_ENABLE
    #ifdef RAW_ENABLE

    // HID input, using node-hid, following example from BlankSourceCode:
    // https://github.com/BlankSourceCode/qmk-hid-display
    bool is_hid_connected = false;
    uint8_t screen_max_count = 0;
    uint8_t screen_show_index = 0;
    uint8_t screen_data_buffer[OLED_MATRIX_SIZE] = {0};
    int screen_data_index = 0;

    void raw_hid_send_screen_index(void) {
        // Send the current info screen index to the connected node script so that it can pass back the new data
        uint8_t send_data[32] = {0};
        send_data[0] = screen_show_index + 1; // Add one so that we can distinguish it from a null byte
        raw_hid_send(send_data, sizeof(send_data));
    }

    void raw_hid_receive(uint8_t *data, uint8_t length) {
        // PC connected, so set the flag to show a message on the master display
        is_hid_connected = true;

        // Initial connections use '1' in the first byte to indicate this
        if (length > 1 && data[0] == 1) {
            // New connection so restart screen_data_buffer
            screen_data_index = 0;

            // The second byte is the number of info screens the connected node script allows us to scroll through
            screen_max_count = data[1];
            if (screen_show_index >= screen_max_count) {
                screen_show_index = 0;
            }

            // Tell the connection which info screen we want to look at initially
            raw_hid_send_screen_index();
            return;
        }

        // Otherwise the data we receive is one line of the screen to show on the display
        if (length >= 21) {
            // Copy the data into our buffer and increment the number of lines we have got so far
            memcpy((char*)&screen_data_buffer[screen_data_index * 21], data, 21);
            screen_data_index++;

            // Once we reach 4 lines, we have a full screen
            if (screen_data_index == 4) {
                // Reset the buffer back to receive the next full screen data
                screen_data_index = 0;
            }
        }
    }

    void next_screen(void)
    {
        if (screen_show_index + 1 < screen_max_count)
        {
            screen_show_index++;
            if (is_hid_connected){raw_hid_send_screen_index();}

        }
    }
    void prev_screen(void)
    {
        if (screen_show_index > 0)
        {
            screen_show_index--;
            if (is_hid_connected){raw_hid_send_screen_index();}
        }
    }
    #else
    void next_screen(void)
    {
    }
    void prev_screen(void)
    {
    }
    #endif

const char *read_logo(void) {
  static char logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  return logo;
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user(void) { //to include different make options

    if (is_keyboard_master()) {
        //add different screens to no-HID mode too
        #ifdef RAW_ENABLE
        if (is_hid_connected){
            oled_write((char*)screen_data_buffer, false);
        } else {
            //static char sraka[26] = {0};
            //snprintf(sraka, sizeof(sraka), "guwno: %d", guwno);
            //oled_write_ln(sraka, false);
            oled_write(read_logo(), false);
        }
        #endif
    } else {
        oled_write_P(PSTR("Active layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _MAIN:
                oled_write_ln_P(PSTR("Main"), false);
                break;
            case _FN:
                oled_write_ln_P(PSTR("Fn"), false);
                #ifdef BLUETOOTH_ENABLE                     //ot move to the housekeeping tast every 1s
                    //float tmpVal = bluefruit_le_read_battery_voltage()/204.8;
                    /*
                    float tmpVal = analogReadPin(F3)/205;
                    int tmpInt1 = tmpVal;                  // Get the integer
                    float tmpFrac = tmpVal - tmpInt1;      // Get fraction
                    int tmpInt2 = trunc(tmpFrac * 100);
                    static char ADC_Readout[26] = {0};
                    snprintf(ADC_Readout, sizeof(ADC_Readout), "%d.%02d V", tmpInt1, tmpInt2);
                    */
                    oled_write_P(PSTR("BLE: "), false);
                    oled_write_ln(BatteryVoltage, false);

                #endif
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("N/A"), false);
            }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        if(led_state.num_lock){
            oled_write_P(PSTR("NUM"), true);
        }else{
            oled_write_P(PSTR("NUM"), false);
        }
        oled_write_P(PSTR("   "), false);
        if(led_state.caps_lock){
            oled_write_P(PSTR("CAPS"), true);
        }else{
            oled_write_P(PSTR("CAPS"), false);
        }
        oled_write_P(PSTR("   "), false);
        if(led_state.scroll_lock){
            oled_write_P(PSTR("SCRL"), true);
        }else{
            oled_write_ln_P(PSTR("SCRL"), false);
        }
        #ifdef RGB_MATRIX_ENABLE
            oled_write_P(PSTR("RGB: "), false);
            oled_write_ln_P(rgb_matrix_is_enabled() ? PSTR("On") : PSTR("Off"), false);
        #endif
    }
return false;
}


/*
    oled_write_P(PSTR("Num Lock: "), false);
    oled_write_ln_P(led_state.num_lock ? PSTR("On") : PSTR("Off"), false);
    oled_write_P(PSTR("Caps Lock: "), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("On") : PSTR("Off"), false);
    oled_write_P(PSTR("Scroll Lock: "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("On") : PSTR("Off"), false);
    oled_write_P(PSTR("RGB: "), false);
    oled_write_ln_P(rgb_matrix_is_enabled() ? PSTR("On") : PSTR("Off"), false);

    }
    return false;
}
*/

#else
    void next_screen(void)
    {
    }
    void prev_screen(void)
    {
    }
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CHINA:
        if (record->event.pressed) {
            for(int i=0; i<100; i++)
            {
                // SEND_STRING("China best\n");
            }
        } else { }
        break;

    case NEXT:
        if (record->event.pressed) {
            next_screen();
        } else { }
        break;

    case PREV:
        if (record->event.pressed) {
            prev_screen();
        } else { }
        break;
    }
    return true;
};
