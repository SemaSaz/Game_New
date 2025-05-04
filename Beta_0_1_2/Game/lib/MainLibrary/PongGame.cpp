#include "PongGame.h"
#include <OLED_I2C.h>

PongGame::PongGame(OLED* oled) : _oled(oled){
    //sd
}



void PongGame::draw_Cicrle(){
    _oled->drawCircle(pozRX, pozRY, 4);
}


void PongGame::ball_ph(){
    if (pozRY - 5 <= 1){
        dvizY *= -1;
    }
    if (pozRY >= 62){
      if (pozRX <= pozLine + 22 and pozRX >= pozLine - 2){
        dvizY *= -1;
        chetBoll += 1;
      }
      else{
         recordBoll = max(recordBoll, chetBoll);
         _oled->clrScr();//Очищаем буфер дисплея. 
         //_oled->setFont(SmallFont);//Перед выводом текста необходимо выбрать шрифт.
         _oled->print("GAME OVER!", 30, 20);
         _oled->print("Your chet:", 20, 30);
         _oled->print(String(chetBoll), 100, 30);
         _oled->print("Record:", 20, 40);
         _oled->print(String(recordBoll), 100, 40);
         _oled->update();//Выводим информацию из буфера на экран.
         delay(1000);
         funcCheck = 0;
         pozLine = 30;
         pozRX = 30;
         pozRY = 35;
         speedBoll = 0;
         chetBoll = 0;
      }
    }

   if (pozRX - 5 <= 1){
        dvizX *= -1;
        
    }
    if (pozRX + 5 >= 128){
        dvizX *= -1;
    }
    
    speedBoll += 0.001;
    if (dvizY > 0){
      pozRY += dvizY;
      pozRY += speedBoll;
    }
    else{
      pozRY += dvizY;
      pozRY -= speedBoll;
      }
   if (dvizX > 0){
      pozRX += dvizX;
      pozRX += speedBoll;
    }
    else{
      pozRX += dvizX;
      pozRX -= speedBoll;
      }
}



void PongGame::draw_user(){
    int position_checker = obrbotka();
    if(position_checker == 2 and pozLine + 21 < 127){
        pozLine += 3;
    }
    if(position_checker == 1 and pozLine - 1 > 1){
        pozLine -= 3;
    }
    _oled->drawLine(pozLine, 63, pozLine + 20, 63); 
}

void PongGame::choose_nap(){
    long a = random(6, 45);
    pozRX = int(a);
    delay(50);

    long b = random(6, 120);
    pozRY = int(a);
    delay(50);

    long a1 = random(1, 1024);
    delay(50);

    if (a1 % 2 == 0){
        dvizY = -1;
    }
    else{
        dvizY = 1;
    }

    long b1 = random(1, 1024);
    delay(50);
    b1 =  random(1, 1024);

    if (b1 % 2 == 0){
        dvizX = -1;
    }
    else{
        dvizX = 1;
    }
}


void PongGame::main_Pong(){
    choose_nap();
    delay(200);
    while(checkSwitch() != 0){
        _oled->clrScr(); 
        _oled->drawLine(1, 1, 1, 64); 
        _oled->drawLine(127, 1, 127, 64); 
        _oled->drawLine(1, 1, 128, 1); 
        obrbotka();
        ball_ph();
        draw_Cicrle();
        draw_user();
        _oled->update();
        delay(5); 
    }
    _oled->clrScr();
    delay(500);
}
