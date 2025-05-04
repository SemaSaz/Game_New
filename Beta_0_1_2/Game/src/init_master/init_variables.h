#ifndef init_variables_h
#define init_variables_h

#include <Arduino.h>

#define pinX    A2  // ось X джойстика
#define pinY    A1  // ось Y джойстика
#define swPin    2  // кнопка джойстика
#define ledPin  13  // светодиод на Pin 13
String go = "";
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
float poz1X = 40;
float poz2X = 50;
//******************
float poz1Y = 45;
float poz2Y = 60;
//***************************************************************
float speeD = 0.3;
//X Y bots*******************************************************
float car1X = -10;
float car1Y = 40;
float randNumber1 = 40;

float car2X = -50;
float car2Y = 70;
float randNumber2;

float car3X = -30;
float car3Y = 60; 
float randNumber3;
//***************************************************************
int chet = 0;
int rec = 0;
const unsigned char Car12 [] = {
0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0xF8, 0x08, 0x08, 0x08, 0x08, 0x08, 0xF8, 0x20, 0xE0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 0x49, 0xFF, 0x88, 0x88, 0x88, 0x88, 0x88,
0xFF, 0x49, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x00, 
};




#endif


