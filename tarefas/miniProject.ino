//Carrega a biblioteca do sensor ultrassonico
#include "Ultrasonic.h"
#include "NewTone.h"

//Define os pinos para o trigger e echo
#define pino_trigger 9
#define pino_echo 8
const int buzzer = 11; 
unsigned long duration = 500;
unsigned long old;
int state = 0;
int stateLED = 0;
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
//  old = millis();
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Le as informacoes do sensor, em cm e pol
  unsigned long now = millis();
  float distCM, distCMold = 0;
  int gap;
  distCM = ultrasonic.distanceRead(CM);
  if(now >= old +duration){
    
    old = now;
      duration = intAPITO(distCM);
    
    
//    if(distCM < 15)
//      duration = 50;
//    if(distCM > 15 && distCM < 50)
//      duration = 150;
//    if(distCM > 50 && distCM < 100)
//      duration = 200;
//    if(distCM > 35 && distCM <150)
//      duration = 250;
    
    Serial.print("Cent: ");  
    Serial.print(distCM);  
    Serial.print(" atraso : ");  
    Serial.println(duration);    
    NewTone(buzzer, 250, 50);
  }
  
//  interv = intAPITO(distCM);
//  Serial.println(interv);
//  if (now1 >= old1+interv){
//    old1 = now1;
//    noTone(buzzer);
//  }
//  if (now >= old+100){
//    old = now;
//    state = !state;
//    if(state == 1){
//      tone(buzzer, 1000);
//    }else{
//      noTone(buzzer);
//    }
//  }
//  if (now >= old+interv){
//    old = now;
//    state = !state;
//    noTone(buzzer);
//  }
//  if (distCM <= 20){
//    if(now >= old+25){
//      old = now;
//      stateLED = !stateLED;
//      piscaLEDS(stateLED);
//    }
//  }else{
//    piscaLEDS(LOW);
//  }
  
}

void piscaLEDS(int estado){
  digitalWrite(4,estado);
  digitalWrite(5,estado);
  digitalWrite(6,estado);
  digitalWrite(7,estado);
}

int medeGAP(float dist, float distOLD){
 float gap = abs(dist-distOLD);
 if (gap > 30){
  return 1;
 }else{
  return 0;
 }
}

unsigned long intAPITO(float dist){
  unsigned long ret;
  if (dist != 755){
    ret = dist * 5 + 50;
    return ret;
  }
  
}
