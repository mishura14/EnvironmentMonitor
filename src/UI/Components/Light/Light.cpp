

#include "Light.h"
#include <cstdio>
#include <cmath>

// Отрисовка освещённости
void drawLight(TFT_eSPI& tft, LightView& view, float lux) {

    char buf[16];

    snprintf(buf, sizeof(buf), "%.1f", lux);

    // Стили надписи
    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.drawString(buf, view.x, view.y, view.font);

    view.lastkey = lux;
}


// Обновление освещённости
void updateLight(TFT_eSPI& tft, LightView& view, float lux) {

    // Проверяем, изменилось ли значение
    if (fabs(lux - view.lastkey) < 1.0f) return;

    drawLight(tft, view, lux);
}


// Повторная отрисовка
void resetLight(LightView& view) {
    view.lastkey = -1;
}
