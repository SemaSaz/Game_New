#ifndef MainWindow_h
#define MainWindow_h

#include <Arduino.h>
#include <OLED_I2C.h>
#include "GameController.h"


class MainWindow: public GameController 
{
private:
    OLED* myOLED;
    int pozition_pointer = 2, pozition_pointer_old = 2;
    int drawing_Window(){
        processInput();
        if (check_button() != 1){
            switch (pozition_pointer)
            {
                case 2:
                    myOLED->clrScr(); 
                    myOLED->update();
                    return 1;
                case 20:
                    myOLED->clrScr();
                    myOLED->update(); 
                    return 2;
                case 40:
                    myOLED->clrScr();
                    myOLED->update(); 
                    return 3;
            }
           // CarGame(myOLED, SmallFont);
        }
        if(pozition_pointer != pozition_pointer_old){
            myOLED->clrScr();
            pozition_pointer_old = pozition_pointer;
        }
        
        myOLED->print("Super Car", 2, 2);
        myOLED->print("|", 100, pozition_pointer);
        myOLED->print("Information:", 2, 40);
        myOLED->print("Pong", 2, 20);
        myOLED->update(); 
        delay(10);
        return 0;
    };
    

public:
    MainWindow(OLED* _myOLED);
    void choose_game();
    void change_pozition();
    int check_button(){
        Serial.println(checkSwitch());
        return checkSwitch();
    };
    void processInput(){
        int time_valut = obrbotka();
        if(time_valut == 5){
            switch (pozition_pointer)
            {
                case 2:
                    pozition_pointer = 20;
                    delay(1000);
                    break;
                case 20:
                    pozition_pointer = 40;
                    delay(1000);
                    break;
                case 40:
                    pozition_pointer = 2;
                    delay(1000);
                    break;
            }
        }
        if(time_valut == 4){
            switch (pozition_pointer)
            {
                case 2:
                    pozition_pointer = 40;
                    delay(1000);
                    break;
                case 20:
                    pozition_pointer = 2;
                    delay(1000);
                    break;
                case 40:
                    pozition_pointer= 20;
                    delay(1000);
                    break;
            }
        }
    };
    int main_window(){
        int returned_value = drawing_Window();
        if(returned_value){
            return returned_value;
        }
        return 0;
    }
};

#endif