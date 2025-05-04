#include "Joystic.h"
#include <Arduino.h>

void Joystic::initPins(int X1, int Y1, int switch_pin1){
    pinMode(X1, INPUT);
    pinMode(Y1, INPUT);
    pinMode(switch_pin1, INPUT);
    pinX = X1, pinY = Y1, switch_pin = switch_pin1;
    digitalWrite(switch_pin1, HIGH);
}

int Joystic::position_processing(){
    int X = analogRead(pinX);              
    int Y = analogRead(pinY);          
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
}

int Joystic::check_switch(){
    return digitalRead(switch_pin);
}



