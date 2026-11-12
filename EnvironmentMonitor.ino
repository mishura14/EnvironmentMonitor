#include <TFT_eSPI.h>
#include "src/UI/Components/Card/Card.h"
#include "src/UI/Theme.h"
#include "src/UI/Screens/MainScreen/MainScreen.h"
#include "src/Sensors/RTC/RTC.h"
#include "src/UI/Components/Clock/Clock.h"
#include <Wire.h>
#include "src/Sensors/Light/Light.h"
#include "src/Sensors/Sensors.h"


TFT_eSPI tft = TFT_eSPI();

bool rtcOk = false;
SensorData sensorData;
unsigned long lastSensorTick = 0;
unsigned long lastUiTick = 0;;


void setup() {
    Serial.begin(115200);
    Wire.begin(27, 22);
    sensorsBegin();

    tft.init();
    tft.invertDisplay(true);
    tft.setRotation(1);
    drawMainScreen(tft);

    rtcOk = rtcBegin();
        if (!rtcOk) Serial.println("RTC not found");

    sensorsBegin();   // подключает BH1750 и SHT3x, статус пишет в Seria

}

void loop() {
    // датчики раз в секунду
    if (millis() - lastSensorTick >= 1000) {
        lastSensorTick = millis();
        sensorsUpdate(sensorData);
        Serial.printf(" lux=%.0f\n temp=%.0f\n hum=%.0f\n co2=%.0f", sensorData.lux, sensorData.shtTemp, sensorData.shtHum, sensorData.co2);
    }

    // экран дважды в секунду; сами компоненты решают, нужна ли перерисовка
    if (millis() - lastUiTick >= 500) {
        lastUiTick = millis();
        DateTime now = rtcOk ? rtcGetTime() : DateTime();   // без RTC часы покажут 00:00, свет работает
        updateMainScreen(tft, now, sensorData);
    }
}
