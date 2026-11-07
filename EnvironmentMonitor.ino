#include <TFT_eSPI.h>
#include "src/UI/Components/Card/Card.h"
#include "src/UI/Theme.h"
#include "src/UI/Screens/MainScreen/MainScreen.h"
#include "src/Sensors/RTC/RTC.h"
#include "src/UI/Components/Clock/Clock.h"
#include <Wire.h>


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

    rtcOk = rtcBegin();
    if(!rtcOk) Serial.println("RTC not found");

}

void loop() {
    if(rtcOk && millis() - lastClockTick >= 1000){
        lastClockTick = millis();
        updateMainScreen(tft, rtcGetTime());
    }
}
