#include "ProjectRase.h"
#include "Servo.h"
#include "Arduino.h"
#include "HardwareSerial.h"
#include "DeplacementManuel.h"

extern HardwareSerial Serial;

int rawSerial;
int pulsewidth = 90;
const byte servoPins[4] = {6,7,8,9};

Servo servos[4];

void setup() {

   Serial.begin(9600);

   // Affectation des servos pour chaque pattes
   for(int i = 0; i < 4; i++){
     servos[i].attach(servoPins[i]);
   }

}

void loop() {
   // Get serial input from Processing
   if (Serial.available()) {

     char ch = Serial.read();
     switch(ch){

      case '0'...'9':
        rawSerial = rawSerial * 10 + ch - '0';
        Serial.println(rawSerial);
      break;

      case 'x':
       //pulsewidth = map(rawSerial, 0,100, 0,180);
       servos[3].write(rawSerial);
       rawSerial = 0;
      break;
      case 'y':
       //pulsewidth = map(rawSerial, 0,100, 0,180);
       servos[3].write(rawSerial);
       rawSerial = 0;
      break;
     }
     }

}
