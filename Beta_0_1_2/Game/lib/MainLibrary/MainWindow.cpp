#include "MainWindow.h"
#include <Arduino.h>
void MainWindow::change_pozition(){
    int time_valut = 1;
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
}

void MainWindow::choose_game(){
    //asd
}


MainWindow::MainWindow(OLED* _myOLED) : myOLED(_myOLED){
    //asd
}