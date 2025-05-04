#include "CarGame.h"
#include <OLED_I2C.h>

CarGame::CarGame(OLED* oled) : _oled(oled){
    //sd
}

void CarGame::draw_car(){
    _oled->print("Super Car", 2, 2);
    _oled->update();
    delay(1000);
}