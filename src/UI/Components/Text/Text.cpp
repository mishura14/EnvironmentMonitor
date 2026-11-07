#include <cstdint>
#include "../../Theme.h"
#include "Text.h"



#include <cstdint>
//функция текста для карточек датчика
void drawText(
    TFT_eSPI& tft,
    const char* text,// текст
    int x,int y,// положение текста
    uint8_t font,// размер текста
    uint16_t color,// цвет текста
    uint16_t bg// цвет заднего фона текста
){
    tft.setTextColor(color,bg);
    tft.drawString(text,x,y,font);
};
