#include <Arduino.h>
#include <Servo.h>
#include <stdio.h>

//servo and GPIO declarations----
Servo mouth;

Servo rightEye;
Servo rightLid;

Servo leftEye;
Servo leftLid;

byte light = 2; //unnecessary LED
//---------------------

void setDefault() { //"blank" expression
  rightEye.write(90);
  leftLid.write(0);
  leftEye.write(90);
  rightLid.write(50);
  mouth.write(72);
}

void setup() {
  Serial.begin(9600);
  Serial.print("Moving Endo");

  mouth.attach(10); //12 to 72 degrees (open to closed)
  rightEye.attach(5); //50 left- 90 right+ 130
  rightLid.attach(3); //50 to 0
  leftEye.attach(6); //50 left- 90 right+ 130
  leftLid.attach(9); //0 to 60

  pinMode(light, OUTPUT);
  setDefault();
}

void openMouth() { //fully opened
  mouth.write(12);
}

void closeMouth() {
  mouth.write(72);
}

int tStartBlink;
void blink() {
  tStartBlink = millis();
  while ((millis() - tStartBlink) <= 200){
    rightLid.write(0);
    leftLid.write(60);
  }
  setDefault();
  return;
}

float tStartChomp;
void chomp() {
  tStartChomp = millis();
  while ((millis() - tStartChomp) <= 300){
    openMouth();
  }
  closeMouth();
  return;
}

void functionalTest() {
  blink();
  chomp();
  leftEye.write(120);
  rightEye.write(120);
  delay(500);
  leftEye.write(50);
  rightEye.write(50);
  delay(500);
  setDefault();
}

float clockTime = 0;
void loop() {

  functionalTest();
  delay(500);
  
}
