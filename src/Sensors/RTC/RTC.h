#pragma once
#include "RTClib.h"

bool rtcBegin();// подключаем датчик DS3231, true если часы ответили
DateTime rtcGetTime();// текущие дата и время
