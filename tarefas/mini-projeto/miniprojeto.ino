//Carrega a biblioteca do sensor ultrassonico
#include "Ultrasonic.h"
#include "NewTone.h"
 
#define pino_trigger 9
#define pino_echo 8
const int buzzer = 11;
float distCMold = 0;
unsigned long duration;
unsigned long old;
int stateLED = 0;
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup() {
  old = millis();
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
 
void loop() {
  unsigned long now = millis();
  float distCM;
  distCM = ultrasonic.distanceRead(CM);  
  distCMold = distCM;
  duration = intAPITO(distCM);
  if(now >= old +duration){
    old = now;
    if (distCM < 160 || distCM == 755){
        stateLED = !stateLED;
        piscaLEDS(stateLED);
      NewTone(buzzer, 1000, 50);
    }else{
      piscaLEDS(LOW);
    }
  }
}
void piscaLEDS(int estado){
  digitalWrite(4,estado);
  digitalWrite(5,estado);
  digitalWrite(6,estado);
  digitalWrite(7,estado);
}

unsigned long intAPITO(float dist){
  unsigned long ret;
  if (dist != 755){
    ret = dist * 3 + 50;
    return ret;
  }
}
