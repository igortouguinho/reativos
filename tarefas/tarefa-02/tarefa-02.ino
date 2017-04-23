/* === Tafera 2 - 23/04/2017 ===
 * ===     Igor Touguinhó    ===
 * ===     Tiago Rezende     ===*/
 
#define BTN_PIN1 2
#define BTN_PIN2 4
#define LED_PIN 13
int state = 0;              // estado led
int btn1ST = 0;             // estado botão 1
int btn2ST = 0;             // estado botão 2
int btn1LS = 0;             // último estado botão 1
int btn2LS = 0;             // último estado botão 1
int timing = 1000;          // tempo de variação do led
unsigned long btnTime = -1;  //tempo de pressionamento do botao
unsigned long old;          // tempo auxiliar
void setup() {
  // definindo modo do led e dos botões
  pinMode(LED_PIN, OUTPUT); 
  pinMode(BTN_PIN1, INPUT);
  pinMode(BTN_PIN2, INPUT);

}

void loop() {
  unsigned long now = millis(); // tempo atual
  // pisca-pisca do led
  if (now>=old+timing){
    old = now;
    state=!state;
    digitalWrite(LED_PIN,state);
  }
  
  // lendo estado dos botões
  btn1ST = digitalRead(BTN_PIN1); 
  btn2ST = digitalRead(BTN_PIN2);

  //checando pressionamento único botão 1 (ACELERAR)
  if (btn1ST == HIGH && btn1LS == LOW){
    btn1LS=btn1ST;
    timing = max(timing-100,50);              // reduzindo o intervalo de tempo entre os estados
    //checando clique nos dois botoes em menos de 500ms
    if((now - btnTime) <= 500){
      while(1);                               //PARANDO NO ESTADO EM QUE ESTIVER O LED
    }
    btnTime = now;
  }else if (btn1ST == LOW && btn1LS == HIGH){ // Zerando o tempo ao soltar o botão 
    btn1LS = btn1ST;                          // para que o mesmo botão nao seja 
    btnTime = 0;                              // pressionado duas vezes para parar o led
  }else{
    btn1LS = btn1ST;
  }
  
  //checando pressionamento único botão 2 (DESACELERAR)
  if (btn2ST == HIGH && btn2LS == LOW){
    btn2LS=btn2ST;
    timing = min(timing+100,3000);            // aumentando o intervalo de tempo entre os estados
    //checando clique nos dois botoes em menos de 500ms
    if((now - btnTime) <= 500){
      while(1);                               //PARANDO NO ESTADO EM QUE ESTIVER O LED
    }
    btnTime = now;
  }else if (btn2ST == LOW && btn2LS == HIGH){ // Zerando o tempo ao soltar o botão 
    btn2LS = btn2ST;                          // para que o mesmo botão nao seja 
    btnTime = 0;                              // pressionado duas vezes para parar o led
  }else{
    btn2LS = btn2ST;
  }
  
}



