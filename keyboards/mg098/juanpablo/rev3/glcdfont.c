#include "progmem.h"

// Corne 8x6 font with QMK Firmware Logo
// Online editor: https://helixfonteditor.netlify.com/

// clang-format off
static const unsigned char PROGMEM font[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3E, 0x5B, 0x4F, 0x5B, 0x3E, 0x00,
    0x3E, 0x6B, 0x4F, 0x6B, 0x3E, 0x00,
    0x1C, 0x3E, 0x7C, 0x3E, 0x1C, 0x00,
    0x18, 0x3C, 0x7E, 0x3C, 0x18, 0x00,
    0x1C, 0x57, 0x7D, 0x57, 0x1C, 0x00,
    0x1C, 0x5E, 0x7F, 0x5E, 0x1C, 0x00,
    0x00, 0x18, 0x3C, 0x18, 0x00, 0x00,
    0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 0x00,
    0x00, 0x18, 0x24, 0x18, 0x00, 0x00,
    0xFF, 0xE7, 0xDB, 0xE7, 0xFF, 0x00,
    0x30, 0x48, 0x3A, 0x06, 0x0E, 0x00,
    0x26, 0x29, 0x79, 0x29, 0x26, 0x00,
    0x40, 0x7F, 0x05, 0x05, 0x07, 0x00,
    0x40, 0x7F, 0x05, 0x25, 0x3F, 0x00,
    0x5A, 0x3C, 0xE7, 0x3C, 0x5A, 0x00,
    0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x00,
    0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x00,
    0x14, 0x22, 0x7F, 0x22, 0x14, 0x00,
    0x5F, 0x5F, 0x00, 0x5F, 0x5F, 0x00,
    0x06, 0x09, 0x7F, 0x01, 0x7F, 0x00,
    0x00, 0x66, 0x89, 0x95, 0x6A, 0x00,
    0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
    0x94, 0xA2, 0xFF, 0xA2, 0x94, 0x00,
    0x08, 0x04, 0x7E, 0x04, 0x08, 0x00,
    0x10, 0x20, 0x7E, 0x20, 0x10, 0x00,
    0x08, 0x08, 0x2A, 0x1C, 0x08, 0x00,
    0x08, 0x1C, 0x2A, 0x08, 0x08, 0x00,
    0x1E, 0x10, 0x10, 0x10, 0x10, 0x00,
    0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 0x00,
    0x30, 0x38, 0x3E, 0x38, 0x30, 0x00,
    0x06, 0x0E, 0x3E, 0x0E, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x5F, 0x00, 0x00, 0x00,
    0x00, 0x07, 0x00, 0x07, 0x00, 0x00,
    0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00,
    0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00,
    0x23, 0x13, 0x08, 0x64, 0x62, 0x00,
    0x36, 0x49, 0x56, 0x20, 0x50, 0x00,
    0x00, 0x08, 0x07, 0x03, 0x00, 0x00,
    0x00, 0x1C, 0x22, 0x41, 0x00, 0x00,
    0x00, 0x41, 0x22, 0x1C, 0x00, 0x00,
    0x2A, 0x1C, 0x7F, 0x1C, 0x2A, 0x00,
    0x08, 0x08, 0x3E, 0x08, 0x08, 0x00,
    0x00, 0x80, 0x70, 0x30, 0x00, 0x00,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
    0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
    0x20, 0x10, 0x08, 0x04, 0x02, 0x00,
    0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00,
    0x00, 0x42, 0x7F, 0x40, 0x00, 0x00,
    0x72, 0x49, 0x49, 0x49, 0x46, 0x00,
    0x21, 0x41, 0x49, 0x4D, 0x33, 0x00,
    0x18, 0x14, 0x12, 0x7F, 0x10, 0x00,
    0x27, 0x45, 0x45, 0x45, 0x39, 0x00,
    0x3C, 0x4A, 0x49, 0x49, 0x31, 0x00,
    0x41, 0x21, 0x11, 0x09, 0x07, 0x00,
    0x36, 0x49, 0x49, 0x49, 0x36, 0x00,
    0x46, 0x49, 0x49, 0x29, 0x1E, 0x00,
    0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
    0x00, 0x40, 0x34, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x14, 0x22, 0x41, 0x00,
    0x14, 0x14, 0x14, 0x14, 0x14, 0x00,
    0x00, 0x41, 0x22, 0x14, 0x08, 0x00,
    0x02, 0x01, 0x59, 0x09, 0x06, 0x00,
    0x3E, 0x41, 0x5D, 0x59, 0x4E, 0x00,
    0x7C, 0x12, 0x11, 0x12, 0x7C, 0x00,
    0x7F, 0x49, 0x49, 0x49, 0x36, 0x00,
    0x3E, 0x41, 0x41, 0x41, 0x22, 0x00,
    0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00,
    0x7F, 0x49, 0x49, 0x49, 0x41, 0x00,
    0x7F, 0x09, 0x09, 0x09, 0x01, 0x00,
    0x3E, 0x41, 0x41, 0x51, 0x73, 0x00,
    0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00,
    0x00, 0x41, 0x7F, 0x41, 0x00, 0x00,
    0x20, 0x40, 0x41, 0x3F, 0x01, 0x00,
    0x7F, 0x08, 0x14, 0x22, 0x41, 0x00,
    0x7F, 0x40, 0x40, 0x40, 0x40, 0x00,
    0x7F, 0x02, 0x1C, 0x02, 0x7F, 0x00,
    0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00,
    0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00,
    0x7F, 0x09, 0x09, 0x09, 0x06, 0x00,
    0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00,
    0x7F, 0x09, 0x19, 0x29, 0x46, 0x00,
    0x26, 0x49, 0x49, 0x49, 0x32, 0x00,
    0x03, 0x01, 0x7F, 0x01, 0x03, 0x00,
    0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00,
    0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00,
    0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00,
    0x63, 0x14, 0x08, 0x14, 0x63, 0x00,
    0x03, 0x04, 0x78, 0x04, 0x03, 0x00,
    0x61, 0x59, 0x49, 0x4D, 0x43, 0x00,
    0x00, 0x7F, 0x41, 0x41, 0x41, 0x00,
    0x02, 0x04, 0x08, 0x10, 0x20, 0x00,
    0x00, 0x41, 0x41, 0x41, 0x7F, 0x00,
    0x04, 0x02, 0x01, 0x02, 0x04, 0x00,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
    0x00, 0x03, 0x07, 0x08, 0x00, 0x00,
    0x20, 0x54, 0x54, 0x78, 0x40, 0x00,
    0x7F, 0x28, 0x44, 0x44, 0x38, 0x00,
    0x38, 0x44, 0x44, 0x44, 0x28, 0x00,
    0x38, 0x44, 0x44, 0x28, 0x7F, 0x00,
    0x38, 0x54, 0x54, 0x54, 0x18, 0x00,
    0x00, 0x08, 0x7E, 0x09, 0x02, 0x00,
    0x18, 0xA4, 0xA4, 0x9C, 0x78, 0x00,
    0x7F, 0x08, 0x04, 0x04, 0x78, 0x00,
    0x00, 0x44, 0x7D, 0x40, 0x00, 0x00,
    0x20, 0x40, 0x40, 0x3D, 0x00, 0x00,
    0x7F, 0x10, 0x28, 0x44, 0x00, 0x00,
    0x00, 0x41, 0x7F, 0x40, 0x00, 0x00,
    0x7C, 0x04, 0x78, 0x04, 0x78, 0x00,
    0x7C, 0x08, 0x04, 0x04, 0x78, 0x00,
    0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
    0xFC, 0x18, 0x24, 0x24, 0x18, 0x00,
    0x18, 0x24, 0x24, 0x18, 0xFC, 0x00,
    0x7C, 0x08, 0x04, 0x04, 0x08, 0x00,
    0x48, 0x54, 0x54, 0x54, 0x24, 0x00,
    0x04, 0x04, 0x3F, 0x44, 0x24, 0x00,
    0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00,
    0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00,
    0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00,
    0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
    0x4C, 0x90, 0x90, 0x90, 0x7C, 0x00,
    0x44, 0x64, 0x54, 0x4C, 0x44, 0x00,
    0x00, 0x08, 0x36, 0x41, 0x00, 0x00,
    0x00, 0x00, 0x77, 0x00, 0x00, 0x00,
    0x00, 0x41, 0x36, 0x08, 0x00, 0x00,
    0x02, 0x01, 0x02, 0x04, 0x02, 0x00,
    0x3C, 0x26, 0x23, 0x26, 0x3C, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8,
    0x08, 0xF8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0x30, 0x98, 0xC8, 0x48, 0xC8,
    0x98, 0x30, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xF8, 0xF8, 0x08, 0xC8,
    0x48, 0x48, 0x48, 0x48, 0xC8, 0x98,
    0x10, 0xE0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xF8, 0x08,
    0x08, 0xF8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xF8, 0x08,
    0x08, 0xF8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x3C, 0x3C, 0x00, 0x00, 0x00,
    0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00,
    0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x00,
    0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0x81,
    0x00, 0x81, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0x00, 0xFF, 0x00, 0x00, 0xFF, 0x01,
    0x01, 0xFF, 0x00, 0x00, 0xFF, 0x01,
    0x01, 0xFF, 0x00, 0x00, 0x3C, 0x26,
    0xA3, 0xB9, 0x49, 0x49, 0x79, 0x03,
    0x06, 0xFC, 0x00, 0x00, 0xFF, 0x01,
    0x01, 0xF7, 0x0A, 0x09, 0xF9, 0x01,
    0x03, 0xFE, 0x00, 0x00, 0x80, 0x60,
    0x30, 0xDF, 0x6C, 0x23, 0x46, 0x8B,
    0x3C, 0xC3, 0xF1, 0x30, 0x90, 0x70,
    0x00, 0x00, 0xFF, 0xFF, 0x00, 0xE7,
    0x24, 0x24, 0x24, 0x24, 0x27, 0x33,
    0x18, 0x0F, 0x00, 0x00, 0x3C, 0x26,
    0xA3, 0xB9, 0x49, 0x49, 0x39, 0x03,
    0x06, 0xFC, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0xF7, 0x1A, 0x09, 0x39, 0xE1,
    0x03, 0x1E, 0xF0, 0x00, 0xFF, 0x00,
    0x00, 0xFF, 0x00, 0x00, 0xFC, 0x06,
    0x03, 0xF9, 0x09, 0x09, 0xF9, 0x03,
    0x06, 0xFC, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC3, 0x81, 0x81, 0x81, 0x81, 0xC3,
    0xC3, 0xA1, 0x81, 0x81, 0x81, 0xC3,
    0xC3, 0xA1, 0xA1, 0x81, 0x81, 0xC3,
    0xC3, 0xA1, 0xA1, 0xA1, 0x81, 0xC3,
    0xC3, 0xA1, 0xA1, 0xA1, 0xA1, 0xC3,
    0xC3, 0xB1, 0xA1, 0xA1, 0xA1, 0xC3,
    0xC3, 0xB1, 0xB1, 0xA1, 0xA1, 0xC3,
    0xC3, 0xB1, 0xB1, 0xB1, 0xA1, 0xC3,
    0xC3, 0xB1, 0xB1, 0xB1, 0xB1, 0xC3,
    0xC3, 0xB9, 0xB1, 0xB1, 0xB1, 0xC3,
    0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F,
    0x31, 0x27, 0x24, 0x24, 0x27, 0x33,
    0x1C, 0x07, 0x00, 0x00, 0x0F, 0x18,
    0x20, 0x27, 0x24, 0x24, 0x37, 0x20,
    0x20, 0x3F, 0x00, 0x00, 0x1E, 0x31,
    0x20, 0x26, 0x25, 0x15, 0x3B, 0x20,
    0x20, 0x3F, 0x20, 0x00, 0x3F, 0x20,
    0x20, 0x3F, 0x00, 0x00, 0x3F, 0x20,
    0x20, 0x3F, 0x00, 0x00, 0x07, 0x0C,
    0x10, 0x33, 0x26, 0x24, 0x24, 0x35,
    0x13, 0x18, 0x38, 0x22, 0x2F, 0x30,
    0x20, 0x00, 0x3F, 0x3F, 0x20, 0x3F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1E, 0x31,
    0x20, 0x26, 0x25, 0x15, 0x3B, 0x20,
    0x20, 0x3F, 0x20, 0x00, 0x3F, 0x20,
    0x20, 0x3B, 0x14, 0x24, 0x27, 0x21,
    0x30, 0x1E, 0x03, 0x00, 0x3F, 0x20,
    0x20, 0x3F, 0x00, 0x00, 0x0F, 0x18,
    0x30, 0x27, 0x24, 0x24, 0x27, 0x30,
    0x18, 0x0F, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC3, 0xB9, 0xB9, 0xB1, 0xB1, 0xC3,
    0xC3, 0xB9, 0xB9, 0xB9, 0xB1, 0xC3,
    0xC3, 0xB9, 0xB9, 0xB9, 0xB9, 0xC3,
    0xC3, 0xBD, 0xB9, 0xB9, 0xB9, 0xC3,
    0xC3, 0xBD, 0xBD, 0xB9, 0xB9, 0xC3,
    0xC3, 0xBD, 0xBD, 0xBD, 0xB9, 0xC3,
    0xC3, 0xBD, 0xBD, 0xBD, 0xBD, 0xC3,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

