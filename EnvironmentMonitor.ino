#include <TFT_eSPI.h>
#include "src/UI/Components/Card/Card.h"
#include "src/UI/Theme.h"
#include "src/UI/Screens/MainScreen/MainScreen.h"


TFT_eSPI tft = TFT_eSPI();

void setup() {
    tft.init();
    tft.invertDisplay(true);
    tft.setRotation(1);
    drawMainScreen(tft);
}

void loop() {

}
