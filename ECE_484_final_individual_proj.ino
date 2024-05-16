#include <SD.h>                           //include SD module library
#include  <TMRpcm.h>                       //include speaker control library

#define  SD_ChipSelectPin 53             //define CS pin


const int flipper_r_out = 2;
const int flipper_l_out = 3;

const int flipper_r_in = 10;
const int flipper_l_in = 9;



TMRpcm tmrpcm;    //crete  an object for speaker library

unsigned long time;

unsigned long prevTime;

void setup() {

  prevTime = 0;
  pinMode(flipper_r_in, INPUT);
  pinMode(flipper_l_in, INPUT);
  pinMode(flipper_r_out, OUTPUT);
  pinMode(flipper_l_out, OUTPUT);

  tmrpcm.speakerPin  = 11;                  //define speaker pin. 
                                          //you  must use pin 9 of the Arduino Uno and Nano, pin 11 of the Arduino Mega                                    
  
  if (!SD.begin(SD_ChipSelectPin)) {      //see  if the card is present and can be initialized
    
    return;                               //don't  do anything more if not
  }
  
  tmrpcm.setVolume(6);                    //0  to 7
  tmrpcm.play("SOUND1.wav");         //the sound file "SOUND1"  will play each time the arduino powers up, or is reset

}

void loop() {
  //play sound at given time interval
  // unsigned long time = millis();
  // if(time > prevTime + 5000){
  //   //tmrpcm.play("SOUND1.wav");  
  //   prevTime = time;
  // }
  //flipper code
  if(digitalRead(flipper_r_in) == HIGH){
    digitalWrite(flipper_r_out, HIGH);

  } else{
    digitalWrite(flipper_r_out, LOW);
    
  }
  if(digitalRead(flipper_l_in) == HIGH){
    digitalWrite(flipper_l_out, HIGH);
  }else{
    digitalWrite(flipper_l_out, LOW);
  }

 
}

