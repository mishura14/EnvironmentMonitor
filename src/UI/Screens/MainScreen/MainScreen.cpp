#include "MainScreen.h"
#include "../../Components/Card/Card.h"
#include "../../Theme.h"
#include "../../Layout.h"
#include "../../Components/Text/Text.h"
#include <RTClib.h>
#include "../../Components/Clock/Clock.h"
#include "../../Components/Date/Date.h"
#include "../../Components/Light/Light.h"
#include "../../../Sensors/SensorData.h"
//кординаты надписи максимальной освещенности
static const int LIGHT_X = GAP + CARD_W + GAP + GAP + CARD_W;   // левый край карточки LIGHT
static const int LIGHT_Y = 40;

static float luxPeak = 0;     // максимум освещённости за сегодня
static int shownPeak = -1;    // что сейчас нарисовано
static int peakDay = -1;      // день, для которого считаем максимум

//обновляемые часы на главной панели
static ClockView headerClock = {85, 10, 2, COLOR_TEXT, COLOR_BG, TL_DATUM, -1};

//обновляемая дата
static DateView headerDate = {125,16,1,COLOR_MUTED,COLOR_BG,TL_DATUM,-1};

//обновляемые часы в карте датчика света
static ClockView lightClock = {225, 115, 1, COLOR_MUTED, COLOR_CARD, TL_DATUM, -1};

//показатель датчика освещенности
static LightView lightState = {225, 68, 4, COLOR_LIGHT, COLOR_CARD, TL_DATUM, -1};

void drawMainScreen(TFT_eSPI& tft){
    tft.fillScreen(COLOR_BG);

    // главная надпись сверху слева
    drawText(tft,"CLIMATE",8,10,2,COLOR_TEXT,COLOR_BG);


    //датчик температуры
    drawCardMain(
        tft,
        GAP,40,// положение
        CARD_W,CARD_HIGHT,// размер
        COLOR_CARD,// цвет карты
        "TEMP",// мелкая надпись карты
        "23.4",// значение датчика
        COLOR_TEMP,// цвет значения датчика
        "C",// в чем измерятеся
        "+_"// изменения за час
    );

    //датчик со2
    drawCardMain(
      tft,
      GAP,135,//положение
      CARD_W, CARD_HIGHT,//размер
      COLOR_CARD,// цвет карты
      "CO2",// мелкая надпись карты
      "900",//значение датчика
      COLOR_CO2,//цвет значения датчика
      "ppm",// в чем измеряется
      "+_"// изменения за час

    );

    //датчик влажности
    drawCardMain(
        tft,
        GAP+CARD_W+GAP,40,// положение
        CARD_W,CARD_HIGHT,// размер
        COLOR_CARD,// цвет карты
        "HUM",// мелкая надпись карты
        "46",// значение датчика
        COLOR_HUM,// цвет значения датчика
        "%",// в чем измеряется
        "+_"// изменения за час
    );

    //датчик давления атмосферы
    drawCardMain(
      tft,
      GAP+CARD_W+GAP,135,//положение
      CARD_W, CARD_HIGHT,//размер
      COLOR_CARD,// цвет карты
      "PRESSURE",// мелкая надпись карты
      "1013",//значение датчика
      COLOR_PRESSURE,// цвет значения датчика
      "hPa",// в чем измеряется
      "+_"// изменения за час

    );

    //датчик отображение lux
    drawLightCardMain(
      tft,
      GAP+CARD_W+GAP+GAP+CARD_W,40,//положение
      CARD_W, CARD_HIGHT+GAP+CARD_HIGHT,//размер
      COLOR_CARD,// цвет карты
      "LIGHT",// мелкая надпись карты
      "lux",// в чем измеряется
      820

    );
    resetClock(headerClock);
    resetClock(lightClock);
    resetDate(headerDate);
    resetLight(lightState);
    shownPeak = (int)luxPeak;
}
//обновление главного экрана
void updateMainScreen(TFT_eSPI& tft, const DateTime& now, const SensorData& d){
    updateClock(tft, headerClock, now);
    updateClock(tft, lightClock, now);
    updateDate(tft, headerDate, now);
    updateLight(tft, lightState, d.lux);

    // новый день: максимум считаем заново
    if (now.day() != peakDay) { peakDay = now.day(); luxPeak = 0; }
    if (!isnan(d.lux) && d.lux > luxPeak) luxPeak = d.lux;

    int peak = (int)luxPeak;
    if (peak != shownPeak) {
        drawLightPeak(tft, LIGHT_X + 10, LIGHT_Y + 165, peak, COLOR_MUTED, COLOR_CARD);
        shownPeak = peak;
    }
}
