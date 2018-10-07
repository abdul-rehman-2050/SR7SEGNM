
#include<SR7SEGNM.h>

const char MAX_DIGITS = 3;


SR7SEGNM segments4094(A0,A1,A2,MAX_DIGITS);

int digitBuffer[MAX_DIGITS]={0};

void setup(){
  int i=0;
  segments4094.begin();
  for(i=1;i<=MAX_DIGITS;i++){
   digitBuffer[i-1]=i; 
  }
  delay(1000);  
  segments4094.updateSegments(digitBuffer);
}

void loop(){
  
}