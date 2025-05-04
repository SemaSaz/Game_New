#include "RecordPage.h"
#include <OLED_I2C.h>


RecordPage::RecordPage(OLED* oled) : _oled(oled){
    //asd
}

void RecordPage::main_Record(){
    delay(500);
    while(checkSwitch() != 0){
        _oled->clrScr();
        // Serial.println(EEPROM.read(10));
        // Serial.println(EEPROM.read(11));
        _oled->drawLine(1, 20, 128, 20);
        _oled->print("CarGame", 5, 25);
        _oled->drawLine(1, 40, 128, 40);
        _oled->print("PongGame", 5, 45);
        _oled->drawLine(60, 1, 60, 64);
        _oled->print("Games", 62, 5);
        _oled->print("Rec", 97, 5);
        _oled->drawLine(95, 1, 95, 64);
        _oled->print(String(EEPROM.read(10)), 63, 23);
        _oled->print(String(EEPROM.read(11)), 97, 23);
        _oled->print(String(EEPROM.read(15)), 63, 43);
        _oled->print(String(EEPROM.read(16)), 97, 43);
        _oled->update();
        delay(5);
    }
    _oled->clrScr();
    delay(500);
}