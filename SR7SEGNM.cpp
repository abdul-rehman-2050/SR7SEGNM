/*

|| @file SR7SEGNM.cpp
|| @version 1.0
|| @author ABDUL REHMAN
|| @contact supermind2002@gmail.com
-------------------------------------------------------

*/


#include <SR7SEGNM.h>

const byte SR7SEGNM::segChar[]={
		0b00111111,
  		0b00000110,
  		0b01011011,
  		0b01001111,
  		0b01100110,
  		0b01101101,
  		0b01111101,
	  	0b00000111,
  		0b01111111,
  		0b01101111,
	  	0b00000000
	};
SR7SEGNM::SR7SEGNM(int clkPin,int dtPin,int strbPin,int nSegments){

	clockPin=clkPin;
	dataPin=dtPin;
	strobPin=strbPin;
	numberOfSegments = nSegments;
}

void SR7SEGNM::begin(){
	
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	pinMode(strobPin, OUTPUT);
	reset();
	
}

void SR7SEGNM::reset(){
	int i=0;
	digitalWrite(strobPin, LOW);
	for(i=numberOfSegments-1;i>=0;i--){
		shiftOut(dataPin, clockPin, MSBFIRST, segChar[0]);
	}
	digitalWrite(strobPin, HIGH);
}

void SR7SEGNM::updateSegments(int segmentBuffer[]){
	int i=0;
	digitalWrite(strobPin, LOW);
	for(i=numberOfSegments-1;i>=0;i--){
		shiftOut(dataPin, clockPin, MSBFIRST, segChar[segmentBuffer[i]]);
	}
	digitalWrite(strobPin, HIGH);
}

void SR7SEGNM::offAllSegments(){
	int i=0;
	digitalWrite(strobPin, LOW);
	for(i=numberOfSegments-1;i>=0;i--){
		shiftOut(dataPin, clockPin, MSBFIRST, 0);
	}
	digitalWrite(strobPin, HIGH);
}
