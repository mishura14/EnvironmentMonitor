#include "Bmp280.h"
#include <Wire.h>
#include <Adafruit_BMP280.h>

static Adafruit_BMP280 bmp(&Wire);

bool bmp280Begin() {
    // адрес 0x76; chip ID по умолчанию 0x58 (настоящий BMP280).
    // Если модуль на самом деле BME280 (ID 0x60), begin вернёт false:
    // тогда используй bmp.begin(0x76, 0x60).
    return bmp.begin(0x77);
}

bool bmp280Read(float& temp, float& pressureHpa) {
    float t = bmp.readTemperature();
    float p = bmp.readPressure();          // в паскалях
    if (isnan(t) || isnan(p) || p <= 0) return false;
    temp = t;
    pressureHpa = p / 100.0f;              // Па -> гПа
    return true;
}
