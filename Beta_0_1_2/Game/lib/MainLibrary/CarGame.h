#ifndef CarGame_h
#define CarGame_h

#include <Arduino.h>
#include <OLED_I2C.h>
#include "GameController.h"

class CarGame : public GameController
{
private:
  OLED* _oled;
  void draw_car_first();
  void draw_car_second();
  void draw_car_third();
  void null_pozition();
  void draw_my_car();
  void draw_all();
  void physicks();
  void check_car_position();


  float speeD = 0.3;
 
  float car1X = -10;
  float car1Y = 40;
  float randNumber1 = 40;

  float car2X = -50;
  float car2Y = 70;
  float randNumber2;

  float car3X = -30;
  float car3Y = 60; 
  float randNumber3;
  int chet = 0, rec = 0;

  float poz1X = 40;
  float poz2X = 50;

  float poz1Y = 45;
  float poz2Y = 60;
  
public:
  CarGame(OLED* oled);
  void main_car();
  
};





#endif