#include "Light.h"
#include <Wire.h>
#include <BH1750.h>

static BH1750 meter;
//функция подключение к датчику
bool lightBegin() {
    return meter.begin();
}
//функция получение данных
bool lightRead(float& lux) {
    float value = meter.readLightLevel();//получение данных с датчика

    if (value < 0) return false;

    lux = value;
    return true;
}
