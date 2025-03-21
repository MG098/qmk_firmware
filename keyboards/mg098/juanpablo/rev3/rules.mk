# This file intentionally left blank
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor
# SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
OLED_ENABLE = yes
OLED_DRIVER = ssd1306     # Enable Support for SSD1306 or SH1106 OLED Displays; Communicating over I2C
ENCODER_ENABLE = yes
# NKRO_ENABLE = no		# Needed for bluetooth to work
SRC += analog.c
RAW_ENABLE = yes


DIP_SWITCH_ENABLE = yes
BLUETOOTH_ENABLE = no
BLUETOOTH_DRIVER = bluefruit_le
SAMPLE_BATTERY = no
