#include "Scd41.h"
#include <Arduino.h>
#include <Wire.h>
#include <SensirionI2cScd4x.h>

static SensirionI2cScd4x scd;
//функция подключение датчика
bool scd41Begin() {
    scd.begin(Wire, SCD41_I2C_ADDR_62);
    scd.stopPeriodicMeasurement();         // на случай, если датчик уже измерял
    delay(500);
    return scd.startPeriodicMeasurement() == 0;   // 0 = успех
}
//функция чтения значений датчика
bool scd41Read(float& co2, float& temp, float& hum) {
    bool ready = false;
    if (scd.getDataReadyStatus(ready) != 0 || !ready) return false;   // новые данные раз в ~5 с

    uint16_t c;
    float t, h;
    if (scd.readMeasurement(c, t, h) != 0 || c == 0) return false;    // 0 ppm = ещё не готово

    co2 = c;
    temp = t;
    hum = h;
    return true;
}
