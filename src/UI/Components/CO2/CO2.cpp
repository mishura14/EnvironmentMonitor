
#include "CO2.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>

static const int NO_DATA = -2;
//значение в токен
static int toKey(float co2){
    return isnan(co2)? NO_DATA : (int)roundf(co2);
}

// Отрисовка температуры
void drawCO2(TFT_eSPI& tft, CO2View& view, float co2) {

    char buf[12];
    if (isnan(co2)) snprintf(buf, sizeof(buf), "--");
    else            snprintf(buf, sizeof(buf), "%d", toKey(co2));

    // Стили надписи
    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.setTextPadding(tft.textWidth("0000", view.font));
    tft.drawString(buf, view.x, view.y, view.font);
    tft.setTextPadding(0);

    view.lastkey = co2;
}


// Обновление значение температуры
void updateCO2(TFT_eSPI& tft, CO2View& view, float co2) {
    int key = toKey(co2);
    if (key == view.lastkey)return;
    // Проверяем, изменилось ли значение
    if (key >= 0 && view.lastkey >= 0 && abs(key - view.lastkey) < 2) return;

    drawCO2(tft, view, co2);
}


// Повторная отрисовка
void resetCO2(CO2View& view) {
    view.lastkey = -1;
}
