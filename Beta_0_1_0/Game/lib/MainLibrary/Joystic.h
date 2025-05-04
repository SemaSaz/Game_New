#ifndef Joystic_H
#define Joystic_H

#include <Arduino.h>

class Joystic
{
private:
    int pinX, pinY, switch_pin;
    
public:
    int result = 0;
    void initPins(int X1, int Y1, int switch_pin1);
    int position_processing();
    int check_switch();
    virtual void check_pozition() {
        result = position_processing();
        Serial.println(result); 
    };

protected:
    
};




#endif