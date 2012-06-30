/*
 * DeplacementManuel.cpp
 *
 *  Created on: 24 juin 2012
 *      Author: alex
 */

#include "DeplacementManuel.h"
#include "Servo.h"
#include "Arduino.h"
#include "HardwareSerial.h"
extern HardwareSerial Serial;

void deplacementM(Servo servos[],  HardwareSerial Serial){

		 int rawSerial;
		 int pulsewidth;
	if (Serial.available()) {
		 char ch = Serial.read();
		 Serial.println(ch);
	     switch(ch){

	      case '0'...'9':
	        rawSerial = rawSerial * 10 + ch - '0';
	        Serial.println(rawSerial);
	      break;

	      case 'x':
	       pulsewidth = map(rawSerial, 0,100, 0,180);
	       servos[3].write(pulsewidth);
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


