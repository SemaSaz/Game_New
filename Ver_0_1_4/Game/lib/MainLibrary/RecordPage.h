#ifndef RecordPage_h
#define RecordPage_h

#include <Arduino.h>
#include <OLED_I2C.h>
#include "GameController.h"
#include <EEPROM.h>


class RecordPage : public GameController
{
private:
    OLED* _oled;



public:
    RecordPage(OLED* oled);
    void main_Record();
};


#endif