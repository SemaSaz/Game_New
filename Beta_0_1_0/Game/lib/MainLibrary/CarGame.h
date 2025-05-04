#ifndef CarGame_h
#define CarGame_h

#include <Arduino.h>
#include <OLED_I2C.h>


class CarGame
{
private:
  OLED* _oled;
  
  
public:
  CarGame(OLED* oled);
  void draw_car();
};





#endif