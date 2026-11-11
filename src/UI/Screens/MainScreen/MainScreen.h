#pragma once
#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <TFT_eSPI.h>
#include <RTClib.h>
#include "../../../Sensors/SensorData.h"

void drawMainScreen(TFT_eSPI& tft); // нарисовать страницу целиком
void updateMainScreen(TFT_eSPI& tft, const DateTime& now, const SensorData& d); // обновить то, что меняется

#endif
