#include <TFT_eSPI.h>
#include <RTClib.h>
#include <cstdint>

//описание строки с даой на экране: где и как рисовать
struct DateView{
    int x;int y;
    uint8_t font;
    uint16_t color;
    uint16_t bg;
    uint8_t datum;
    int lastkey;
};

void drawDate(TFT_eSPI& tft, DateView& view, const DateTime& time);
void updateDate(TFT_eSPI& tft, DateView& view, const DateTime& time);
void resetDate(DateView& view);
