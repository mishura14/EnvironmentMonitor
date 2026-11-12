#include "Sensors.h"
#include <Arduino.h>
#include "BMP280/Bmp280.h"
#include "Light/Light.h"
#include "Scd41/Scd41.h"
#include "Sht3x/Sht3x.h"
#include "BMP280/BMP280.h""


static bool lightOk, shtOk, scd41Ok, bmp280Ok;

//подключение всех датчиков
void sensorsBegin(){
    lightOk = lightBegin();
    shtOk = sht3xBegin();
    scd41Ok = scd41Begin();
    bmp280Ok = bmp280Begin();


    Serial.printf("BH1750: %s\n", lightOk ? "OK" : "FAIL");
    Serial.printf("SHT3x:  %s\n", shtOk   ? "OK" : "FAIL");
    Serial.printf("SCD41:  %s\n", scd41Ok   ? "OK" : "FAIL");
}

//обновление датчиков
void sensorsUpdate(SensorData& d){
    if (lightOk) {
        if (!lightRead(d.lux)) d.lux = NAN;   // ошибка чтения = "нет данных"
    }
    if (shtOk) sht3xRead(d.shtTemp, d.shtHum);
    if (scd41Ok) scd41Read(d.co2, d.scdTemp, d.scdHum);
    if (bmp280Ok) bmp280Read(d.bmpTemp, d.pressure);
}
