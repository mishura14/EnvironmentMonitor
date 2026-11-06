#ifndef BUTTON_H
#define BUTTON_H

#include <TFT_eSPI.h>
#include <cstdint>

void drawButtonMain(
    TFT_eSPI& tft,
    int x,
    int y,
    int width,
    int height,
    uint16_t color,
    const char* text
);

#endif
