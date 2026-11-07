#include "MainScreen.h"
#include "../../Components/Card/Card.h"
#include "../../Theme.h"
#include "../../Layout.h"
#include "../../Components/Text/Text.h"
#include <RTClib.h>
#include "../../Components/Clock/Clock.h""
#include "../../Components/Date/Date.h""



//обновляемые часы на главной панели
static ClockView headerClock = {85, 10, 2, COLOR_TEXT, COLOR_BG, TL_DATUM, -1};

//обновляемая дата
static DateView headerDate = {125,16,1,COLOR_MUTED,COLOR_BG,TL_DATUM,-1};

//обновляемые часы в карте датчика света
static ClockView lightClock = {225, 115, 1, COLOR_MUTED, COLOR_CARD, TL_DATUM, -1};

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
      "PREESSURE",// мелкая надпись карты
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
      "420",//значение датчика
      COLOR_LIGHT,// цвет значения датчика
      "lux",// в чем измеряется
      820

    );
}
//обновление главного экрана
void updateMainScreen(TFT_eSPI& tft, const DateTime& now){
    updateClock(tft,headerClock,now);
    updateClock(tft,lightClock,now);
    updateDate(tft,headerDate,now);
}
