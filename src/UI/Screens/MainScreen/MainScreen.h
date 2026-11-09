#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <TFT_eSPI.h>
#include <RTClib.h>

void drawMainScreen(TFT_eSPI& tft);                          // нарисовать страницу целиком
void updateMainScreen(TFT_eSPI& tft, const DateTime& now, float current_lux);  // обновить то, что меняется

#endif
