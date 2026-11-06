#ifndef THEME_H
#define THEME_H

#include <stdint.h>

constexpr uint16_t rgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

constexpr uint16_t COLOR_BG    = rgb565(11, 14, 19);     // фон
constexpr uint16_t COLOR_CARD  = rgb565(21, 26, 34);     // карточки
constexpr uint16_t COLOR_TEXT  = rgb565(232, 236, 241);  // основной текст
constexpr uint16_t COLOR_MUTED = rgb565(138, 148, 163);  // подписи

constexpr uint16_t COLOR_TEMP     = rgb565(251, 146, 60);
constexpr uint16_t COLOR_HUM      = rgb565(56, 189, 248);
constexpr uint16_t COLOR_CO2      = rgb565(167, 139, 250);
constexpr uint16_t COLOR_PRESSURE = rgb565(74, 222, 128);
constexpr uint16_t COLOR_LIGHT    = rgb565(250, 204, 21);

#endif
