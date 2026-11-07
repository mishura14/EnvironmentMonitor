#include "Clock.h"
#include <cstdio>
//фукнция отрисовки часов
void drawClock(TFT_eSPI& tft, ClockView& view, const DateTime& time){
    char buf[6];
    snprintf(buf, sizeof(buf), "%02d:%02d", time.hour(), time.minute());
    //стили надписи
    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.drawString(buf,view.x,view.y,view.font);

    view.lastMinute = time.minute();
}
//фукнция обновление отрисовки часов
void updateClock(TFT_eSPI& tft, ClockView& view, const DateTime& time){
    if(time.minute() == view.lastMinute) return;
    drawClock(tft, view,time);
}

void resetClock(ClockView& view) {
    view.lastMinute = -1;
}
