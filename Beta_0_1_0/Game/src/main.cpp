#include "init_master.h"
#include "GameController.h"
#include <OLED_I2C.h>
#include "MainWindow.h"
#include "CarGame.h"

extern uint8_t SmallFont[];
OLED myOLED(SDA, SCL);

MainWindow* class_mainW = nullptr;
CarGame* class_car = nullptr;

// CarGame cr;


void setup() {
  randomSeed(analogRead(0)); 
  Serial.begin(9600);
  Serial.println("Hello");
  Serial.println(SDA);
  Serial.println(SCL);
  joy.initPins(pinX, pinY, swPin);
  myOLED.begin();
  myOLED.setFont(SmallFont);
  class_mainW = new MainWindow(&myOLED);
  class_car = new CarGame(&myOLED);
}
 
void loop() {
  if(class_mainW->main_window()){
    class_car->draw_car();
  }
   
}
/*
void nap(){
 // boolean ledState = digitalRead(swPin); // считываем состояние кнопки
  int X = analogRead(pinX);              // считываем значение оси Х
  int Y = analogRead(pinY);              // считываем значение оси Y
  Serial.println(koorStrel);
  if (X <= 522 and X >= 500 and Y <= 1023 and Y >= 1000){
     go = "Left";
     Serial.println("Left");
    } 
  if (X <= 522 and X >= 500 and Y >= 0 and Y <= 10){
      go = "Right";
      Serial.println("Right");
    }
  if (X <= 522 and X >= 500 and Y >= 500 and Y <= 515){
      go = "Stop";
      Serial.println("Stop");
    }
  if (X >= 0 and X <= 10 and Y <= 518 and Y >= 500){
      go = "UP";
      Serial.println("UP");
    }
  if (X <= 1023 and X >= 1018 and Y <= 518 and Y >= 500){
      go = "Down";
      Serial.println("Down");
    }
  
  }


void choiseNap(){
    long a = random(6, 45);
    pozRX = int(a);
    delay(300);
    long b = random(6, 120);
    pozRY = int(a);
    delay(400);
    long a1 = random(1, 1024);
    delay(300);
    if (a1 % 2 == 0){
        dvizY = -1;
      }
     else{
        dvizY = 1;
      }
      long b1 = random(1, 1024);
      delay(500);
      b1 =  random(1, 1024);
    if (b1 % 2 == 0){
        dvizX = -1;
      }
     else{
        dvizX = 1;
      }
      Serial.println(String(a) + " " + String(b) + " " + String(a1) + " " + String(b1));
  }  

void GAME1(){
dvish();
   myOLED.clrScr(); 
   myOLED.drawLine(25, 1, 25, 64); 
   myOLED.drawLine(103, 1, 103, 64); 
   
   myOLED.drawRect(poz1X, poz1Y, poz2X, poz2Y); 
   myOLED.drawRect(poz1X, poz1Y+1, poz2X-14, poz2Y-9); 
   myOLED.drawRect(poz1X, poz1Y+10, poz2X-14, poz2Y);
   myOLED.drawRect(poz1X+14, poz1Y+10, poz2X, poz2Y);
   myOLED.drawRect(poz1X+14, poz1Y+1, poz2X, poz2Y-9);

   
   myOLED.drawRect(car1Y, car1X, car1Y + 10, car1X + 10); 
   myOLED.drawRect(car1Y, car1X+1, car1Y - 3, car1X + 4); 
   myOLED.drawRect(car1Y, car1X+7, car1Y - 3, car1X + 10); 
   myOLED.drawRect(car1Y+10, car1X+7, car1Y+13, car1X + 10); 
   myOLED.drawRect(car1Y+10, car1X+1, car1Y+13, car1X + 4); 
   
   myOLED.drawRect(car2Y, car2X, car2Y + 10, car2X + 10);
   myOLED.drawRect(car2Y, car2X+1, car2Y - 3, car2X + 4); 
   myOLED.drawRect(car2Y, car2X+7, car2Y - 3, car2X + 10); 
   myOLED.drawRect(car2Y+10, car2X+7, car2Y+13, car2X + 10); 
   myOLED.drawRect(car2Y+10, car2X+1, car2Y+13, car2X + 4); 

   
   myOLED.drawRect(car3Y, car3X, car3Y + 10, car3X + 10);
   myOLED.drawRect(car3Y, car3X+1, car3Y - 3, car3X + 4); 
   myOLED.drawRect(car3Y, car3X+7, car3Y - 3, car3X + 10); 
   myOLED.drawRect(car3Y+10, car3X+7, car3Y+13, car3X + 10); 
   myOLED.drawRect(car3Y+10, car3X+1, car3Y+13, car3X + 4); 


   
   myOLED.print("c=", 2, 2);//в данном случае выводится строка, а не число.
   //myOLED.print(Car12, 20, 20);
   myOLED.print(String(chet), 14, 2);//в данном случае выводится строка, а не число.
   myOLED.print("r=", 2, 10);//в данном случае выводится строка, а не число.
   myOLED.print(String(rec), 14, 10);//в данном случае выводится строка, а не число.
   myOLED.update(); 
   delay(5);  
   speeD += 0.001;
    car1X+=speeD;
    car2X+=speeD;
    car3X+=speeD;
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
  
    if ((poz1Y <= car1X + 10 and poz1Y > car1X - 15) and (poz1X  > car1Y - 14 and poz1X < car1Y + 14)){
     myOLED.clrScr();//Очищаем буфер дисплея. 
     myOLED.setFont(SmallFont);//Перед выводом текста необходимо выбрать шрифт.
     myOLED.print("GAME OVER!", 30, 30);
     myOLED.update();//Выводим информацию из буфера на экран.
     delay(2500);
     car1X = -20;
     car1Y = random(30, 50);
     poz1X = 40;
     poz2X = 50;
     poz1Y = 45;
     poz2Y = 60;
     car2X = -60;
     car2Y = random(55, 65);
     car3X = -70;
     car3Y = random(70, 85); 
     rec = max(chet, rec);
     chet = 0;
     speeD = 0.3;
        }
     
  
    if (poz1Y <= car2X + 10  and poz1Y > car2X - 15 and (poz1X  > car2Y - 14 and poz1X < car2Y + 14)){
     myOLED.clrScr();//Очищаем буфер дисплея. 
     myOLED.setFont(SmallFont);//Перед выводом текста необходимо выбрать шрифт.
     myOLED.print("GAME OVER!", 30, 30);
     myOLED.update();//Выводим информацию из буфера на экран.
     delay(2500);
     car1X = -30;
     car1Y = random(34, 50);
     poz1X = 40;
     poz2X = 50;
     poz1Y = 45;
     poz2Y = 60; 
     car2X = -90;
     car2Y = random(55, 70);
     car3X = -60;
     car3Y = random(70, 85); 
     rec = max(chet, rec);
     chet = 0;
     speeD = 0.3;
        }
    if (poz1Y <= car3X + 10  and poz1Y > car3X - 15 and (poz1X  > car3Y - 14 and poz1X < car3Y + 14)){
     myOLED.clrScr();//Очищаем буфер дисплея. 
     myOLED.setFont(SmallFont);//Перед выводом текста необходимо выбрать шрифт.
     myOLED.print("GAME OVER!", 30, 30);
     myOLED.update();//Выводим информацию из буфера на экран.
     delay(2500);
     car1X = -30;
     car1Y = random(34, 50);
     poz1X = 40;
     poz2X = 50;
     poz1Y = 45;
     poz2Y = 60; 
     car2X = -90;
     car2Y = random(50, 65);
     car3X = -50;
     car3Y = random(70, 85); 
     rec = max(chet, rec);
     chet = 0;
     speeD = 0.3;
        }
  
  
      
    if (car2X > 70){
       randNumber2 = random(50, 70);
       chet += 1;
       car2Y = randNumber2; 
       car2X = -80;
      }
      if (car3X > 70){
       randNumber3 = random(70, 85);
       car3Y = randNumber3;
       car3X = -60;
       chet += 1;
      }  
     
}


void Pong(){
      if (funcCheck == 0){
        choiseNap();
        funcCheck++;
    }
   myOLED.clrScr(); 
   myOLED.drawLine(1, 1, 1, 64); 
   myOLED.drawLine(127, 1, 127, 64); 
   myOLED.drawLine(pozLine, 63, pozLine + 20, 63); 
   myOLED.drawLine(1, 1, 128, 1); 
   myOLED.drawCircle(pozRX, pozRY, 4);
   myOLED.update(); 
   nap();
   if(go == "Right" and pozLine + 21 < 127){
        pozLine += 3;
    }
  if(go == "Left" and pozLine - 1 > 1){
        pozLine -= 3;
    }
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
         myOLED.clrScr();//Очищаем буфер дисплея. 
         myOLED.setFont(SmallFont);//Перед выводом текста необходимо выбрать шрифт.
         myOLED.print("GAME OVER!", 30, 20);
         myOLED.print("Your chet:", 20, 30);
         myOLED.print(String(chetBoll), 100, 30);
         myOLED.print("Record:", 20, 40);
         myOLED.print(String(recordBoll), 100, 40);
         myOLED.update();//Выводим информацию из буфера на экран.
         delay(1000);
         funcCheck = 0;
         pozLine = 30;
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
   delay(5);  
  }
 void dvish(){
   nap();
    if (go == "Right"){
   if (poz1X + 5 < 103 and poz2X + 5 < 103){
   poz1X += 2;
   poz2X += 2;
    go = "";
   }
    }
  if (go == "Left"){
    if (poz1X - 5 > 25 and poz2X - 5 > 25){
   poz1X -= 2;
   poz2X -= 2;

   go = "";
    }
  }
   if (go == "Down"){
   if (poz1Y + 1 < 64 and poz2Y < 64){
   poz1Y += 2;
   poz2Y += 2;
   go = "";
    }
  }
if (go == "UP"){
  if (poz1Y - 1 > 0 and poz2Y > 0){
   poz1Y -= 2;
   poz2Y -= 2;
   go = "";
  }
 }
 }

 */