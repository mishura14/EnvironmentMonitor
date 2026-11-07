#ifndef CLOCK_H
#define CLOCK_H

#include <TFT_eSPI.h>
#include <RTClib.h>
// структууура данных для времени
struct ClockView {
    int x; int y;//положение
    uint8_t font;//размер
    uint16_t color;//цвет
    uint16_t bg;//цвет заднего фона
    uint8_t datum;//привзяка
    int lastMinute;      // -1 = ещё не рисовали
};

void drawClock(TFT_eSPI& tft, ClockView& view, const DateTime& time);
void updateClock(TFT_eSPI& tft, ClockView& view, const DateTime& time);
void resetClock(ClockView& view);

#endif
