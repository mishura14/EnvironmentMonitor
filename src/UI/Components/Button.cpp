#include "Button.h"
#include <cstdint>
#include "../Theme.h"

void drawButtonMain(
    TFT_eSPI& tft,
    int x,
    int y,
    int width,
    int height,
    uint16_t color,
    const char* text
){
    tft.fillRoundRect(
        x,
        y,
        width,
        height,
        8,
        color
    );
    tft.setTextColor(COLOR_TEXT);
    tft.drawString(text,x+10,y+10,1);
}
