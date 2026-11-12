
#pragma once

#include <TFT_eSPI.h>
#include <cstdint>
//структура основных значений для значений датчика
struct CO2View{
    int x;int y;
    uint8_t font;
    uint16_t color;
    uint16_t bg;
    uint8_t datum;
    int lastkey;
};

void drawCO2(TFT_eSPI& tft, CO2View& view, float co2);

void updateCO2(TFT_eSPI& tft, CO2View& view, float co2);

void resetCO2(CO2View& view);
