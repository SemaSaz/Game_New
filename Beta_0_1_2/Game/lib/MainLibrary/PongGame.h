#ifndef PongGame_h
#define PongGame_h

#include <Arduino.h>
#include <OLED_I2C.h>
#include "GameController.h"

class PongGame : public GameController
{
private:
    OLED* _oled;
    void draw_Cicrle();
    void choose_nap();
    void draw_user();
    void ball_ph();


    float pozLine = 30;
    float pozRX = 30;
    float pozRY = 35;
    float dvizY = 1;
    float dvizX = 1;
    float funcCheck = 0;
    int koorStrel = 2;
    int GameStarus = 0;
    float speedBoll = 0;
    int chetBoll = 0;
    int recordBoll = 0;

public:
    PongGame(OLED* oled);
    void main_Pong();
};

#endif