#include "init_master.h"
#include "GameController.h"
#include <OLED_I2C.h>
#include "MainWindow.h"
#include "PongGame.h"
#include "CarGame.h"

extern uint8_t SmallFont[];
OLED myOLED(SDA, SCL);

MainWindow* class_mainW = nullptr;
CarGame* class_car = nullptr;
PongGame* class_pong = nullptr;


void setup() {
  randomSeed(analogRead(0)); 
  Serial.begin(9600);
  Serial.println("Hello");
  joy.initPins(pinX, pinY, swPin);
  myOLED.begin();
  myOLED.setFont(SmallFont);
  class_mainW = new MainWindow(&myOLED);
  class_car = new CarGame(&myOLED);
  class_pong = new PongGame(&myOLED);
}
 
void loop() {
  int choose_game = class_mainW->main_window();
  if(choose_game){
    if(choose_game == 1){
      class_car->main_car();
    }
    if(choose_game == 2){
      class_pong->main_Pong();
    }
  }
   
}
