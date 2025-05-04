#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "JoystickHandler.h"
#include <Arduino.h>

class GameController {
public:
    int obrbotka(){
        int X = analogRead(A2);              
        int Y = analogRead(A1);          
        if (X <= 522 and X >= 500 and Y <= 1023 and Y >= 1000){
            Serial.println("Left");
            return 1;
        } 
        if (X <= 522 and X >= 500 and Y >= 0 and Y <= 10){
            Serial.println("Right");
            return 2;
        }
        if (X <= 522 and X >= 500 and Y >= 500 and Y <= 515){
            Serial.println("Stop");
            return 3;
        }
        if (X >= 0 and X <= 10 and Y <= 518 and Y >= 500){
            Serial.println("UP");
            return 4;
        }
        if (X <= 1023 and X >= 1018 and Y <= 518 and Y >= 500){
            Serial.println("Down");
            return 5;
        }
    };

    int checkSwitch(){
        return digitalRead(2);
    };

private:
   
};

#endif 
