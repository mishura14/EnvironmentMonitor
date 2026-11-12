#pragma once

#include <TFT_eSPI.h>
#include <cstdint>
//структура основных значений для значений датчика
struct HumView{
    int x;int y;
    uint8_t font;
    uint16_t color;
    uint16_t bg;
    uint8_t datum;
    int lastkey;
};

void drawHum(TFT_eSPI& tft, HumView& view, float hum);

void updateHum(TFT_eSPI& tft, HumView& view, float hum);

void resetHum(HumView& view);
