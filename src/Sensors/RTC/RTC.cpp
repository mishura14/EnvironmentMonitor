#include "RTC.h"
#include "Wire.h"

static RTC_DS3231 rtc;

bool rtcBegin(){
    if(!rtc.begin(&Wire)) return false; // подключение к датчику.
    if(rtc.lostPower()){ // проверяет достоверность времени
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));// запись данных в переменные
    }
    return true;
}

DateTime rtcGetTime(){// читает регистры где хранятся данные
    return rtc.now();
}
