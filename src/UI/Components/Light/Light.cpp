
#include "Light.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>

static const int NO_DATA = -2;
//превращаем занчение в токен
static int toKey(float lux){
    return isnan(lux)? NO_DATA : (int)roundf(lux);
}
// Отрисовка освещённости
void drawLight(TFT_eSPI& tft, LightView& view, float lux) {

    char buf[12];
    if (isnan(lux)) snprintf(buf, sizeof(buf), "--");
    else            snprintf(buf, sizeof(buf), "%d", (int)lroundf(lux));

    // Стили надписи
    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.setTextPadding(tft.textWidth("00000", view.font));
    tft.drawString(buf, view.x, view.y, view.font);
    tft.setTextPadding(0);

    view.lastkey = lux;
}


// Обновление освещённости
void updateLight(TFT_eSPI& tft, LightView& view, float lux) {
    int key = toKey(lux);
    if (key == view.lastkey)return;
    // Проверяем, изменилось ли значение
    if (key >= 0 && view.lastkey >= 0 && abs(key - view.lastkey) < 2) return;

    drawLight(tft, view, lux);
}


// Повторная отрисовка
void resetLight(LightView& view) {
    view.lastkey = -1;
}
//отрисовка максимальной яркости
void drawLightPeak(TFT_eSPI& tft, int x, int y, int peak, uint16_t color, uint16_t bg){
    char buf[20];
    snprintf(buf, sizeof(buf), "PEAK %d lux", peak);
    tft.setTextColor(color, bg);
    tft.setTextDatum(TL_DATUM);
    tft.setTextPadding(tft.textWidth("PEAK 65535 lux", 1));
    tft.drawString(buf, x, y, 1);
    tft.setTextPadding(0);
}
