//Carrega a biblioteca do sensor ultrassonico
#include "Ultrasonic.h"

//Define os pinos para o trigger e echo
#define pino_trigger 5
#define pino_echo 6
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop() {
  //Le as informacoes do sensor, em cm e pol
  float distCM;
  long microsec = ultrasonic.timing();
  distCM = ultrasonic.convert(microsec, Ultrasonic::CM);
  if (distCM < 10){
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
  }else if (distCM < 20){
    digitalWrite(4,HIGH);
    delay(25);
    digitalWrite(4,LOW);
    delay(25);
  }
  
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(distCM);
}
