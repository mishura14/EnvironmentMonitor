
#include "Temp.h""
#include <cmath>
#include <cstdio>
#include <cstdlib>

static const int NO_DATA = -2;
//значение в токен
static int toKey(float temp){
    return isnan(temp)? NO_DATA : (int)roundf(temp*10);
}

// Отрисовка температуры
void drawTemp(TFT_eSPI& tft, TempView& view, float temp) {

    char buf[12];
    if (isnan(temp)) snprintf(buf, sizeof(buf), "--");
    else            snprintf(buf, sizeof(buf), "%.1f", temp);

    // Стили надписи
    tft.setTextColor(view.color, view.bg);
    tft.setTextDatum(view.datum);
    tft.setTextPadding(tft.textWidth("00.0", view.font));
    tft.drawString(buf, view.x, view.y, view.font);
    tft.setTextPadding(0);

    view.lastkey = temp;
}


// Обновление значение температуры
void updateTemp(TFT_eSPI& tft, TempView& view, float temp) {
    int key = toKey(temp);
    if (key == view.lastkey)return;
    // Проверяем, изменилось ли значение
    if (key >= 0 && view.lastkey >= 0 && abs(key - view.lastkey) < 2) return;

    drawTemp(tft, view, temp);
}


// Повторная отрисовка
void resetTemp(TempView& view) {
    view.lastkey = -1;
}
