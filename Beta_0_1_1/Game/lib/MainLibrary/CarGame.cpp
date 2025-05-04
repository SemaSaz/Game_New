#include "CarGame.h"
#include <OLED_I2C.h>

CarGame::CarGame(OLED* oled) : _oled(oled){
    //sd
}


void CarGame::draw_car_first(){
    _oled->drawRect(car1Y, car1X, car1Y + 10, car1X + 10); 
    _oled->drawRect(car1Y, car1X+1, car1Y - 3, car1X + 4); 
    _oled->drawRect(car1Y, car1X+7, car1Y - 3, car1X + 10); 
    _oled->drawRect(car1Y+10, car1X+7, car1Y+13, car1X + 10); 
    _oled->drawRect(car1Y+10, car1X+1, car1Y+13, car1X + 4); 
    if (car1X > 70){
    int a = randNumber1;
       randNumber1 = random(30, 50);
        while(a == randNumber1){
            randNumber1 = random(30, 50);
          }
       car1Y = randNumber1;
       car1X = -10;
       chet += 1;
    }  
}


void CarGame::draw_car_second(){
    _oled->drawRect(car2Y, car2X, car2Y + 10, car2X + 10);
    _oled->drawRect(car2Y, car2X+1, car2Y - 3, car2X + 4); 
    _oled->drawRect(car2Y, car2X+7, car2Y - 3, car2X + 10); 
    _oled->drawRect(car2Y+10, car2X+7, car2Y+13, car2X + 10); 
    _oled->drawRect(car2Y+10, car2X+1, car2Y+13, car2X + 4); 
    if (car2X > 70){
        randNumber2 = random(50, 70);
        chet += 1;
        car2Y = randNumber2; 
        car2X = -80;
    }
}

void CarGame::draw_car_third(){
    _oled->drawRect(car3Y, car3X, car3Y + 10, car3X + 10);
    _oled->drawRect(car3Y, car3X+1, car3Y - 3, car3X + 4); 
    _oled->drawRect(car3Y, car3X+7, car3Y - 3, car3X + 10); 
    _oled->drawRect(car3Y+10, car3X+7, car3Y+13, car3X + 10); 
    _oled->drawRect(car3Y+10, car3X+1, car3Y+13, car3X + 4); 
    if (car3X > 70){
        randNumber3 = random(70, 85);
        car3Y = randNumber3;
        car3X = -60;
        chet += 1;
    }  
}

void CarGame::draw_my_car(){
    check_car_position();
    _oled->drawRect(poz1X, poz1Y, poz2X, poz2Y); 
    _oled->drawRect(poz1X, poz1Y+1, poz2X-14, poz2Y-9); 
    _oled->drawRect(poz1X, poz1Y+10, poz2X-14, poz2Y);
    _oled->drawRect(poz1X+14, poz1Y+10, poz2X, poz2Y);
    _oled->drawRect(poz1X+14, poz1Y+1, poz2X, poz2Y-9);
}

void CarGame::null_pozition(){
    speeD = 0.3;
    car1X = -10;
    car1Y = 40;
    randNumber1 = 40;
    car2X = -50;
    car2Y = 70;
    randNumber2;
    car3X = -30;
    car3Y = 60; 
    randNumber3 = 0;
    rec = max(chet, rec);
    chet = 0;
    poz1X = 40;
    poz2X = 50;

    poz1Y = 45;
    poz2Y = 60;
  
}

void CarGame::draw_all(){
    draw_car_first();
    draw_car_second();
    draw_car_third();
    draw_my_car();
}

void CarGame::check_car_position(){
    int position_checker = obrbotka();
    if (position_checker == 2){
            if (poz1X + 5 < 103 and poz2X + 5 < 103){
                poz1X += 2;
                poz2X += 2;
            }
         }
       if (position_checker == 1){
            if (poz1X - 5 > 25 and poz2X - 5 > 25){
                poz1X -= 2;
                poz2X -= 2;
         }
       }
        if (position_checker == 5){
            if (poz1Y + 1 < 64 and poz2Y < 64){
                poz1Y += 2;
                poz2Y += 2;
         }
       }
     if (position_checker == 4){
       if (poz1Y - 1 > 0 and poz2Y > 0){
            poz1Y -= 2;
            poz2Y -= 2;
       }
      }
}

void CarGame::physicks(){
    if ((poz1Y <= car1X + 10 and poz1Y > car1X - 15) and (poz1X  > car1Y - 14 and poz1X < car1Y + 14)){
        _oled->clrScr();
        _oled->print("GAME OVER!", 30, 30);
        _oled->update();
        delay(2500);
        null_pozition();
    }

    if (poz1Y <= car2X + 10  and poz1Y > car2X - 15 and (poz1X  > car2Y - 14 and poz1X < car2Y + 14)){
        _oled->clrScr();
        _oled->print("GAME OVER!", 30, 30);
        _oled->update();
        delay(2500);
        null_pozition();
    }

    if (poz1Y <= car3X + 10  and poz1Y > car3X - 15 and (poz1X  > car3Y - 14 and poz1X < car3Y + 14)){
        _oled->clrScr();
        _oled->print("GAME OVER!", 30, 30);
        _oled->update();
        delay(2500);
        null_pozition();
    }





}

void CarGame::main_car(){
    delay(500);
    while(checkSwitch() != 0){
        _oled->clrScr(); 
        _oled->drawLine(25, 1, 25, 64); 
        _oled->drawLine(103, 1, 103, 64);
        obrbotka();
        _oled->print("c=", 2, 2);
        _oled->print(String(chet), 14, 2);
        _oled->print("r=", 2, 10);
        _oled->print(String(rec), 14, 10);

        draw_all();
        physicks();
        speeD += 0.001;
        car1X+=speeD;
        car2X+=speeD;
        car3X+=speeD;
        _oled->update();
        delay(5); 
    }
    _oled->clrScr();
    delay(500);
}