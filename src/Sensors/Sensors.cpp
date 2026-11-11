#include "Sensors.h"
#include <Arduino.h>
#include "Light/Light.h"
#include "Sht3x/Sht3x.h"


static bool lightOk, shtOk;

//подключение всех датчиков
void sensorsBegin(){
    lightOk = lightBegin();
    shtOk = sht3xBegin();


    Serial.printf("BH1750: %s\n", lightOk ? "OK" : "FAIL");
    Serial.printf("SHT3x:  %s\n", shtOk   ? "OK" : "FAIL");
}

//обновление датчиков
void sensorsUpdate(SensorData& d){
    if (lightOk) {
        if (!lightRead(d.lux)) d.lux = NAN;   // ошибка чтения = "нет данных"
    }
    if (shtOk) sht3xRead(d.shtTemp, d.shtHum);
}
