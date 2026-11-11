#include "Date.h"
#include <cstdio>

// названия: индекс массива = номер из DateTime
static const char* DAYS[]   = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
static const char* MONTHS[] = {"JAN","FEB","MAR","APR","MAY","JUN",
                               "JUL","AUG","SEP","OCT","NOV","DEC"};
//один и тот же ключ для сравнения
static int dateKey(const DateTime& t){
    return t.year() *100000 + t.month() * 100 + t.day();
}

//рисуем дату
void drawDate(TFT_eSPI& tft, DateView& view, const DateTime& time){
    char buf[20];
    snprintf(buf, sizeof(buf), "%s %d %s",
             DAYS[time.dayOfTheWeek()], time.day(), MONTHS[time.month() - 1]);

    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.setTextPadding(tft.textWidth("WED 30 DEC", view.font));   // самая длинная возможная строка
    tft.drawString(buf, view.x, view.y, view.font);
    tft.setTextPadding(0);

    view.lastkey = dateKey(time);
}
//функция обновление даты
void updateDate(TFT_eSPI& tft, DateView& view, const DateTime& time){
    if(dateKey(time) == view.lastkey) return; // день не сменился
    drawDate(tft,view,time);
}
// рисуте заново
void resetDate(DateView& view){
    view.lastkey = -1;
}
