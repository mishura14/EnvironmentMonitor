#include <TFT_eSPI.h>
#include "src/UI/Components/Card/Card.h"
#include "src/UI/Theme.h"
#include "src/UI/Screens/MainScreen/MainScreen.h"
#include "src/Sensors/RTC/RTC.h"
#include "src/UI/Components/Clock/Clock.h"
#include <Wire.h>
#include "src/Sensors/Light/Light.h"


TFT_eSPI tft = TFT_eSPI();

bool rtcOk = false;
unsigned long lastClockTick = 0;


void setup() {
    Serial.begin(115200);
    Wire.begin(27, 22);

    tft.init();
    tft.invertDisplay(true);
    tft.setRotation(1);
    drawMainScreen(tft);

    // Инициализируем RTC
    rtcOk = rtcBegin();
    if (!rtcOk) {
        Serial.println("RTC not found");
    }

    // Инициализируем BH1750
    if (!lightBegin()) {
           Serial.println("BH1750 not found");
    } else {
        Serial.println("BH1750 initialized");
    }

}

void loop() {
    static float currentLux = 0.0f;

    // Получаем освещённость
    lightRead(currentLux);

    // Обновляем часы раз в секунду
    if (rtcOk && millis() - lastClockTick >= 1000) {
        lastClockTick = millis();

        DateTime now = rtcGetTime();

        updateMainScreen(tft, now, currentLux);
    }
}
