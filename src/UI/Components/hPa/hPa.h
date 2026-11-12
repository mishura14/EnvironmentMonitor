
#pragma once

#include <TFT_eSPI.h>
#include <cstdint>
//структура основных значений для значений датчика
struct hPaView{
    int x;int y;
    uint8_t font;
    uint16_t color;
    uint16_t bg;
    uint8_t datum;
    int lastkey;
};

void drawhPa(TFT_eSPI& tft, hPaView& view, float hpa);

void updatehPa(TFT_eSPI& tft, hPaView& view, float hpa);

void resethPa(hPaView& view);
