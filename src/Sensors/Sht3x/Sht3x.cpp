#include "Sht3x.h"
#include <Wire.h>
#include <Adafruit_SHT31.h>
#include <cmath>

static Adafruit_SHT31 sht;

//подключение датчика
bool sht3xBegin(){
    return sht.begin(0x44);
}
//получение данных с датчика
bool sht3xRead(float& temp, float& hum){
    float t = sht.readTemperature();
    float h = sht.readHumidity();
    if (isnan(t) || isnan(h)) return false;
    temp = t;
    hum = h;
    return true;
}
