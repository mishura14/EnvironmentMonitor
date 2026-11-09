#ifndef CARD_H
#define CARD_H

#include <TFT_eSPI.h>
#include <cstdint>
//шаблон отрисовки карточки датчиков
void drawCardMain(
    TFT_eSPI& tft,
    int x,// положение х
    int y,// положение y
    int width,// ширина
    int height,// высота
    uint16_t color,// цвет карты
    const char* text,// надпись сверху
    const char* indicator,// значение датчка
    uint16_t color_text,// цвет значения датчика
    const char* meaning,// в чем измеряется
    const char* change// изменение данных
);
//карточка отрисовки датчика света
void drawLightCardMain(
    TFT_eSPI& tft,
    int x,// положение х
    int y,// положение y
    int width,// ширина
    int height,// высота
    uint16_t color,// цвет карты
    const char* text,// надпись сверху
    const char* meaning,// в чем измеряется
    int max_lux // максимальное количество lux
);



#endif
