#pragma once
#include <TFT_eSPI.h>
#include <cstdint>
//структура основных значений для значений датчика
struct LightView{
    int x;int y;
    uint8_t font;
    uint16_t color;
    uint16_t bg;
    uint8_t datum;
    int lastkey;
};


void drawLight(TFT_eSPI& tft, LightView& view, float lux);

void updateLight(TFT_eSPI& tft, LightView& view, float lux);

void resetLight(LightView& view);

void drawLightPeak(TFT_eSPI& tft, int x, int y, int peak, uint16_t color, uint16_t bg);
