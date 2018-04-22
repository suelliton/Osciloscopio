/******************************************************************
 * PID Simple Example (Augmented with Processing.org Communication)
 * Version 0.3
 * by Brett Beauregard
 * License: Creative-Commons Attribution Share-Alike
 * April 2011
 ******************************************************************/

#include <PID_v1.h>

//Define Variables we'll be connecting to
double Input[6];
int inputPin[6];


unsigned long serialTime; //this will help us know when to talk with processing
PID myPID(10, 2, 3,0.01,0.28,0, DIRECT);
void setup(){
  //initialize the serial link with processing
  Serial.begin(9600);  
  //initialize the variables we're linked to
  for(int i = 0 ; i < 6 ; i++){
    inputPin[i] = i;
  }
  pinMode(6,OUTPUT);
}

void loop(){
      analogWrite(6,180);
      for(int i = 0 ; i < 6 ; i++){
          Input[i] = analogRead(inputPin[i]);
      }
  
      SerialSend();
  
 
  
}


/********************************************
 * Serial Communication functions / helpers
 ********************************************/


void SerialSend(){

       for(int i = 0 ; i < 6 ; i++){
            //Serial.print(Input[i]);
            Serial.print(Input[i]);   
            Serial.print(" ");
       }
 
 
  if(myPID.GetMode()==AUTOMATIC) Serial.print("Automatic");
  else Serial.print("Manual");  
  Serial.print(" ");
  if(myPID.GetDirection()==DIRECT) Serial.println("Direct");
  else Serial.println("Reverse");

}

