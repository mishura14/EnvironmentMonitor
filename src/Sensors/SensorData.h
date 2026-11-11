#pragma once
#include <cmath>


//если значение нет то экран покажет --
struct SensorData {
    float lux      = NAN;   // BH1750, люксы
    float shtTemp  = NAN;   // SHT3x, °C
    float shtHum   = NAN;   // SHT3x, %
    float bmpTemp  = NAN;   // BMP280, °C
    float pressure = NAN;   // BMP280, гПа
    float co2      = NAN;   // SCD41, ppm
    float scdTemp  = NAN;   // SCD41, °C
    float scdHum   = NAN;   // SCD41, %
};
