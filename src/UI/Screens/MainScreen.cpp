#include "MainScreen.h"
#include "../Components/Button.h"
#include "../Theme.h"

void drawMainScreen(TFT_eSPI& tft){
    tft.fillScreen(TFT_BLACK);
    tft.invertDisplay(true);

    drawButtonMain(
        tft,
        5,40,
        100,90,
        COLOR_CARD,
        "TEMP"
    );
    drawButtonMain(
      tft,
      5,135,
      100,90,
      COLOR_CARD,
      "CO2"

    );
}
