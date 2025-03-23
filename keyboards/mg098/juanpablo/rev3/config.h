// Copyright 2023 Michał Gołąb (@MG098)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef BLUETOOTH_ENABLE

    #define SPI_DRIVER SPID0
    #define SPI_SCK_PIN GP18
    #define SPI_MOSI_PIN GP19
    #define SPI_MISO_PIN GP16

    #define BLUEFRUIT_LE_SCK_DIVISOR 128
    #define BLUEFRUIT_LE_RST_PIN GP12    //has to be declared something, unused pin (GP12 on LEFT)
    #define BLUEFRUIT_LE_CS_PIN  GP17
    #define BLUEFRUIT_LE_IRQ_PIN GP23
    #define BATTERY_LEVEL_PIN    GP29    //has to be declared something, unused pin
#endif

#ifdef DIP_SWITCH_ENABLE
    #define DIP_SWITCH_PINS { GP14, GP15 }
#endif

#ifdef OLED_ENABLE

    #define I2C_DRIVER I2CD1
    #define I2C1_SCL_PIN GP27
    #define I2C1_SDA_PIN GP26

    #define OLED_DISPLAY_128X32
    #define OLED_TIMEOUT 20000
    #define OLED_FONT_H "keyboards/mg098/juanpablo/rev3/glcdfont.c"    //TODO change to global path?
#endif

#ifdef SPLIT_KEYBOARD
    #define SERIAL_DEBUG
    #define MASTER_LEFT
    // #define SPLIT_HAND_PIN GP24         //not needed?
    // #define USB_VBUS_PIN GP24        //deprecated?
    // #define SOFT_SERIAL_PIN GP28
    // #define SERIAL_USART_TX_PIN GP28 //redefinition?
    #define SERIAL_PIO_USE_PIO1
    #define FORCED_SYNC_THROTTLE_MS 100
    #define SPLIT_MAX_CONNECTION_ERRORS 10
    #define SPLIT_CONNECTION_CHECK_TIMEOUT 500
    // #define SPLIT_LAYER_STATE_ENABLE
    // #define SPLIT_LED_STATE_ENABLE
    // #define SPLIT_WPM_ENABLE

    //#define RGBLIGHT_SPLIT    //redefinition, to be removed
    // #define SPLIT_TRANSPORT_MIRROR
    #define SPLIT_TRANSACTION_IDS_USER BATTERY_SYNC
#endif

#ifdef RGB_MATRIX_ENABLE    //to be fine tuned in FINAL
    #define WS2812_DI_PIN GP20
    // #define RGB_DISABLE_WHEN_USB_SUSPENDED true //untested
    #define RGB_MATRIX_LED_COUNT 71
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    // #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 127
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS

    #ifdef SPLIT_KEYBOARD
        #define RGB_MATRIX_SPLIT { 30, 41 }
    #endif
#endif


#ifdef RGB_MATRIX_ENABLE    //RGB EFFECTS ENABLE
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_SAT
    #define ENABLE_RGB_MATRIX_BAND_VAL
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL	Enables
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define ENABLE_RGB_MATRIX_HUE_BREATHING
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    #define ENABLE_RGB_MATRIX_HUE_WAVE
    #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN

    #ifdef RGB_MATRIX_KEYPRESSES
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
        #define ENABLE_RGB_MATRIX_SPLASH
        #define ENABLE_RGB_MATRIX_MULTISPLASH
        #define ENABLE_RGB_MATRIX_SOLID_SPLASH
        #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
    #endif
    #ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
        #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
        #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #endif

#endif


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
