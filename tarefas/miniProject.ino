//Carrega a biblioteca do sensor ultrassonico
#include "Ultrasonic.h"

//Define os pinos para o trigger e echo
#define pino_trigger 9
#define pino_echo 8
const int buzzer = 11; 
unsigned long duration = 500;
unsigned long old;
unsigned long rightnow;
int state = 0;
int stateLED = 0;
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);



void setup() {
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
  float distCM;
  long microsec = ultrasonic.timing();
  distCM = ultrasonic.convert(microsec, Ultrasonic::CM);
  duration = freqAPITO(distCM);
  
  if (now >= old+duration){
    old = now;
    state = !state;
    apitaBUZZER(state);
    
    Serial.print("Distancia em cm: ");
    Serial.println(distCM);

  }
  rightnow = millis();
  if(now >= rightnow+25){
    rightnow = now;
    stateLED = !stateLED;
    if (distCM <= 20){
      piscaLEDS(stateLED); // ARRUMAR LED !!!
    }
  }
//  }else if (distCM < 20){
//    digitalWrite(4,HIGH);
//    delay(25);
//    digitalWrite(4,LOW);
//    delay(25);
//  }
  
  //Exibe informacoes no serial monitor
 
}

void piscaLEDS(int estado){
  digitalWrite(4,estado);
  digitalWrite(5,estado);
  digitalWrite(6,estado);
  digitalWrite(7,estado);
}

void apitaBUZZER(int estado){
  if(estado)
    tone(buzzer, 1000);
  else
    noTone(buzzer);
}

unsigned long freqAPITO(float dist){
  unsigned long ret;
  ret = dist * 10 + 50;
  return ret;
}
