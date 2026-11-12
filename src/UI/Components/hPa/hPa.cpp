
#include "hPa.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>

static const int NO_DATA = -2;
//значение в токен
static int toKey(float hpa){
    return isnan(hpa)? NO_DATA : (int)roundf(hpa);
}

// Отрисовка температуры
void drawhPa(TFT_eSPI& tft, hPaView& view, float hpa) {

    char buf[12];
    if (isnan(hpa)) snprintf(buf, sizeof(buf), "--");
    else            snprintf(buf, sizeof(buf), "%d", toKey(hpa));

    // Стили надписи
    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.setTextPadding(tft.textWidth("0000", view.font));
    tft.drawString(buf, view.x, view.y, view.font);
    tft.setTextPadding(0);

    view.lastkey = hpa;
}


// Обновление значение температуры
void updatehPa(TFT_eSPI& tft, hPaView& view, float hpa) {
    int key = toKey(hpa);
    if (key == view.lastkey)return;
    // Проверяем, изменилось ли значение
    if (key >= 0 && view.lastkey >= 0 && abs(key - view.lastkey) < 2) return;

    drawhPa(tft, view, hpa);
}


// Повторная отрисовка
void resethPa(hPaView& view) {
    view.lastkey = -1;
}
