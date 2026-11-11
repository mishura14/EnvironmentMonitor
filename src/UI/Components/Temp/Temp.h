#pragma once

#include <TFT_eSPI.h>
#include <cstdint>
//структура основных значений для значений датчика
struct TempView{
    int x;int y;
    uint8_t font;
    uint16_t color;
    uint16_t bg;
    uint8_t datum;
    int lastkey;
};

void drawTemp(TFT_eSPI& tft, TempView& view, float temp);

void updateTemp(TFT_eSPI& tft, TempView& view, float temp);

void resetTemp(TempView& view);
