/*
################################################################################
# File Name:             MAX7219_9.ino                                             
# Board:                 Arduino UNO         
# Programming Language:	 Wiring / C /Processing /Fritzing / Arduino IDE          
#						
# Objective:             Scrolling LED dot Matrix
#										  
# Operation:	         Scrolls a message over a 16x8 LED dot matrix
#			
# Author:                Marcelo Moraes 
# Date:                  July 9th, 2013	
# Place:                 Sorocaba - SP - Brazil	
#					
################################################################################
 
 This code is a public example.
 */



//******************************************************************************
// visit this web page for further information about MaxMatrix library
// https://code.google.com/p/arudino-maxmatrix-library/
//******************************************************************************

#include <Button.h>
#include <MaxMatrix.h>
#include <avr/pgmspace.h>

PROGMEM prog_uchar CH[] = {
3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};


#define	UP_BUTTON 2	
#define	DOWN_BUTTON 3
#define START_BUTTON 4
#define RIGHT_BUTTON 5
#define LEFT_BUTTON 6

int USE_POT_CONTROL = 1;

int data = 51;    // 8, DIN pin of MAX7219 module
int load = 53;    // 9, CS pin of MAX7219 module
int clock = 52;   // 10, CLK pin of MAX7219 module

int maxInUse = 5;    //change this variable to set how many MAX7219's you'll use
int maxNumber = maxInUse*8;

int Intensity = 0;
int BUF_SIZE = 10;

int SPEED_IN = A0;
int SCROLL_DELAY = 75;

int t;
int scrollDelay;
char serialMessage[100];
char newMessage[100];
char *curMessage;
boolean newMessageAvailable = false;


MaxMatrix m(data, load, clock, maxInUse); // define module
Button BT_UP = Button(UP_BUTTON,BUTTON_PULLUP_INTERNAL);
Button BT_DOWN = Button(DOWN_BUTTON,BUTTON_PULLUP_INTERNAL);
Button BT_START = Button(START_BUTTON,BUTTON_PULLUP_INTERNAL);
Button BT_RIGHT = Button(RIGHT_BUTTON,BUTTON_PULLUP_INTERNAL);
Button BT_LEFT = Button(LEFT_BUTTON,BUTTON_PULLUP_INTERNAL);

byte buffer[100];

// active sentenses
char string1[] = " Hello, my name is Marcelo Moraes and...         ";
char string2[] = " I am so glad to show you my Arduino scrolling dot Matrix         ";
char string3[] = " using MAX7219 IC and now we have new features on it         ";
char string4[] = " The new features are:   Start scrolling button, Speed and Intensity Control.         ";
char string5[] = " Visit my blog at:     http://arduinobymyself.blogspot.com.br         ";
char string6[] = " There you will find a lot of projects with Arduino.          ";
char string7[] = " the code and libraries to build the projects"          ;
char string8[] = " Thanks for watching =)            ";


// just for tests
char string9[] = " A B C D E F G H I J K L M N O P Q R S T U V X W Y Z ";
char string10[] = " a b c d e f g h i j k l m n o p q r s t u v x w y z ";
char string11[] = " 1 2 3 4 5 6 7 8 9 0 - = ";
char string12[] = " ! @ # $ % ¨ & * ( ) _ + ";
char string13[] = " ' , . ; ~ ] ´ [ | < > : ^ } ` { / ?  ";

char string14[] = " Hello !         ";




void setup(){
  m.init(); // module initialize
  m.setIntensity(Intensity); // dot matix intensity 0-15
  Serial.begin(57600); // serial communication initialize
  
  if (USE_POT_CONTROL){
    pinMode(SPEED_IN, INPUT);
  }
  else{
    scrollDelay = SCROLL_DELAY;
  }
  //strcpy(curMessage, "ArduinoByMyself          ");
  newMessage[0] = '\0';
}

void loop(){
  while(!BT_START.isPressed()){
    }
  //scrollDelay = getScrollDelay();
  readSerial();
  scrollText();
  //Serial.println(maxNumber);
}


void readSerial(void)
{
  int putIndex = 0;

  while (Serial.available())
  {
    newMessage[putIndex] = (char)Serial.read();
    if ((newMessage[putIndex] == '\n') || (putIndex >= BUF_SIZE-3))	// end of message character or full buffer
    {
      // put in a message separator and end the string
      newMessage[putIndex++] = ' ';
      newMessage[putIndex] = '\0';
      // restart the index for next filling spree and flag we have a message waiting
      putIndex = 0;
      newMessageAvailable = true;
    }
    else
      // Just save the next char in next location
      newMessage[putIndex++];
  }
}

void scrollText(void)
{

  if(newMessageAvailable){	// there is a new message waiting
    strcpy(serialMessage, newMessage);	// copy it in
    newMessageAvailable = false;
    printStringWithShift(serialMessage, scrollDelay);
  }
    
  // messages sequency
  curMessage = string1;
  printStringWithShift(curMessage, scrollDelay);
  //*
  curMessage = string2;
  printStringWithShift(curMessage, scrollDelay);
  curMessage = string3;
  printStringWithShift(curMessage, scrollDelay);
  curMessage = string4;
  printStringWithShift(curMessage, scrollDelay);
  curMessage = string5;
  printStringWithShift(curMessage, scrollDelay);
  curMessage = string6;
  printStringWithShift(curMessage, scrollDelay);
  curMessage = string7;
  printStringWithShift(curMessage, scrollDelay);
  curMessage = string8;
  printStringWithShift(curMessage, scrollDelay);
  //*/

}



int getScrollDelay(void){
  if (USE_POT_CONTROL){
    t = analogRead(SPEED_IN);
    t = map(t, 0, 1023, 5, 300);
    return(t);
  }
  else{
    t = SCROLL_DELAY;
  }
}

void printCharWithShift(char c, int shift_speed){
  shift_speed = getScrollDelay();
  
  if(BT_UP.isPressed()){
      Intensity = Intensity +1;
      if(Intensity > 15){
        Intensity = 15;
      }
      m.setIntensity(Intensity);
    }
    else if(BT_DOWN.isPressed()){
      Intensity = Intensity - 1;
      if(Intensity < 0){
        Intensity = 0;
      }
      m.setIntensity(Intensity);
    }
    
  
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7*c, 7);
  m.writeSprite(maxNumber, 0, buffer);
  m.setColumn(maxNumber + buffer[0], 0);
  
  for (int i=0; i<buffer[0]+1; i++) 
  {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}

void printStringWithShift(char* s, int shift_speed){
  while (*s != 0){
    shift_speed = getScrollDelay();
    printCharWithShift(*s, shift_speed);
    s++;
  }
}

void printString(char* s)
{
  
  int col = 0;
  while (*s != 0)
  {
    if (*s < 32) continue;
    char c = *s - 32;
    memcpy_P(buffer, CH + 7*c, 7);
    m.writeSprite(col, 0, buffer);
    m.setColumn(col + buffer[0], 0);
    col += buffer[0] + 1;
    s++;
  }
}
