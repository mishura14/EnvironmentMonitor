#include "Date.h"
#include <cstdio>

// названия: индекс массива = номер из DateTime
static const char* DAYS[]   = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
static const char* MONTHS[] = {"JAN","FEB","MAR","APR","MAY","JUN",
                               "JUL","AUG","SEP","OCT","NOV","DEC"};


//рисуем дату
void drawDate(TFT_eSPI& tft, DateView& view, const DateTime& time){
    char buf[20];
    int weekday = time.dayOfTheWeek();
    snprintf(buf, sizeof(buf), "%s %d %0s",DAYS[weekday],time.day(),MONTHS[time.month() -1] );
    //стили надписи
    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.drawString(buf,view.x,view.y,view.font);

    view.lastkey =
            time.year() * 10000 +
            time.month() * 100 +
            time.day();
}


//функция обновление даты
void updateDate(TFT_eSPI& tft, DateView& view, const DateTime& time){
    int key = time.month() * 100 + time.day();
    if(key == view.lastkey) return; // день не сменится
    drawDate(tft,view,time);
}
// рисуте заново
void resetDate(DateView& view){
    view.lastkey = -1;
}
