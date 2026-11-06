#ifndef TEXT_H
#define TEXT_H

#include <TFT_eSPI.h>
#include <cstdint>



#include <cstdint>
// шаблон для отрисовки текста для датчиков
void drawText(
    TFT_eSPI& tft,
    const char* text,// текст
    int x,int y,// положение текста
    uint8_t font,// размер текста
    uint16_t color,// цвет текста
    uint16_t bg// цвет фона текста
);

#endif
