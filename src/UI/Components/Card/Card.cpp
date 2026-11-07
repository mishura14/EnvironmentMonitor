#include "Card.h"
#include <cstdint>
#include <cstdio>
#include "../../Theme.h"
#include "../Text/Text.h"


// шаблон стандартных карточек
void drawCardMain(
    TFT_eSPI& tft,
    int x,// положение x
    int y,// положение y
    int width,// ширина карты
    int height,// высота карты
    uint16_t color,// цвет карты
    const char* text,// надпись над картой
    const char* indicator,// значение данчика
    uint16_t color_text,// текс цвета значения датчика
    const char* meaning,// в чем измеряется значение
    const char* change// изменение датчика
){
    tft.fillRoundRect(
        x,
        y,
        width,
        height,
        8,
        color
    );
    drawText(tft,text,x+10,y+10,1,COLOR_MUTED,COLOR_CARD);
    drawText(tft,indicator,x+10,y+30,4,color_text,COLOR_CARD);
    drawText(tft,meaning,x+10,y+55,1,COLOR_MUTED,COLOR_CARD);
    drawText(tft,change,x+10,y+70,1,COLOR_MUTED,COLOR_CARD);


}
// функция отрисовки карточки для датчика света
void drawLightCardMain(
    TFT_eSPI& tft,
    int x,// положение x
    int y,// положение y
    int width,// ширина карты
    int height,// высота карты
    uint16_t color,// цвет карты
    const char* text,// надпись над картой
    const char* indicator,// значение данчика
    uint16_t color_text,// текс цвета значения датчика
    const char* meaning,// в чем измеряется значение
    int max_lux // максимальное значение люксов

){
    tft.fillRoundRect(
        x,
        y,
        width,
        height,
        8,
        color
    );
    drawText(tft,text,x+10,y+10,1,COLOR_MUTED,COLOR_CARD);
    drawText(tft,indicator,x+10,y+30,4,color_text,COLOR_CARD);
    drawText(tft,meaning,x+10,y+55,1,COLOR_MUTED,COLOR_CARD);
    drawText(tft,"TODAY",x+10,y+95,1,COLOR_MUTED,COLOR_CARD);
    char line[20];
    snprintf(line,sizeof(line),"PEAK %d lux", max_lux);
    drawText(tft,line,x+10,y+165,1,COLOR_MUTED,COLOR_CARD);


}
