#include "init_master.h"
#include "GameController.h"
#include <OLED_I2C.h>
#include "MainWindow.h"
#include "PongGame.h"
#include "CarGame.h"
#include "RecordPage.h"
#include "EEPROM.h"



extern uint8_t SmallFont[];
OLED myOLED(SDA, SCL);

MainWindow* class_mainW = nullptr;
CarGame* class_car = nullptr;
PongGame* class_pong = nullptr;
RecordPage* class_record = nullptr;

void setup() {
  randomSeed(analogRead(0)); 
  Serial.begin(9600);
  if(EEPROM.read(0) != 1){
    EEPROM.write(0, 1);
    EEPROM.write(10, 0);
    EEPROM.write(11, 0);
    EEPROM.write(15, 0);
    EEPROM.write(16, 0);
  }
  Serial.println("Hello");
  joy.initPins(pinX, pinY, swPin);
  myOLED.begin();
  myOLED.setFont(SmallFont);
  class_mainW = new MainWindow(&myOLED);
  class_car = new CarGame(&myOLED);
  class_pong = new PongGame(&myOLED);
  class_record = new RecordPage(&myOLED);
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
    if(choose_game == 3){
      class_record->main_Record();
    }
  }
   
}
