#include <TFT_eSPI.h>
#include "src/UI/Components/Button.h"
#include "src/UI/Theme.h"
#include "src/UI/Screens/MainScreen.h"


TFT_eSPI tft = TFT_eSPI();

void setup() {
    tft.init();
    tft.setRotation(1);
    drawMainScreen(tft);
}

void loop() {

}
