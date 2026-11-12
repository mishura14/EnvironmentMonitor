
#include "Hum.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>

static const int NO_DATA = -2;
//значение в токен
static int toKey(float hum){
    return isnan(hum)? NO_DATA : (int)roundf(hum*10);
}

// Отрисовка температуры
void drawHum(TFT_eSPI& tft, HumView& view, float hum) {

    char buf[12];
    if (isnan(hum)) snprintf(buf, sizeof(buf), "--");
    else            snprintf(buf, sizeof(buf), "%.1f", hum);

    // Стили надписи
    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.setTextPadding(tft.textWidth("00.0", view.font));
    tft.drawString(buf, view.x, view.y, view.font);
    tft.setTextPadding(0);

    view.lastkey = hum;
}


// Обновление значение температуры
void updateHum(TFT_eSPI& tft, HumView& view, float hum) {
    int key = toKey(hum);
    if (key == view.lastkey)return;
    // Проверяем, изменилось ли значение
    if (key >= 0 && view.lastkey >= 0 && abs(key - view.lastkey) < 2) return;

    drawHum(tft, view, hum);
}


// Повторная отрисовка
void resetHum(HumView& view) {
    view.lastkey = -1;
}
