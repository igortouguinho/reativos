#define BUT_PIN 4
// Joystick x- and y- axes are connected to A10 and A9 analog pins of Arduino.

int joyX = A5; //  X - axis of Joystick
int joyY = A4; // y - axis of Joystick
int x, y; 
char dir;
// variavel pro tiro 
char sht = 'T';
void setup()
{ 
  Serial.begin(9600);
  pinMode(BUT_PIN, INPUT);
}

void loop()
{ 
  x = joyX;    // y value btwn 0 and 1023) 
  y = joyY;    // x value btwn 0 and 1023) 
  y = map(analogRead(joyX), 0, 1023, 900, 2100); 
  x = map(analogRead(joyY), 0, 1023, 900, 2100);
  //verificacao do tiro 
  int shoot = digitalRead(BUT_PIN);
  
  if ( x > 1400 && x < 1600 && y > 1400 && y < 1600){
    dir = 'S';
  }
  if ( x > 1400 && x < 1600 && y > 2000 && y < 2200){
    dir = 'W';
  }
  if ( x > 2000 && x < 2200 && y > 1400 && y < 1600){
    dir = 'D';
  }
  if ( x > 1400 && x < 1600 && y > 800 && y < 1000){
    dir = 'X';
  }
  if ( x > 800 && x < 1000 && y > 1400 && y < 1600){
    dir = 'A';
  }
  if ( x > 800 && x < 1200 && y > 2000 && y < 2200){
    dir = 'Q';
  }
  if ( x > 2000 && x < 2200 && y > 2000 && y < 2200){
    dir = 'E';
  }
  if ( x > 2000 && x < 2200 && y > 800 && y < 1200){
    dir = 'C';
  }
  if ( x > 800 && x < 1200 && y > 800 && y < 1200){
    dir = 'Z';
  }
  if(shoot){
    Serial.write(sht);
  }else{
  Serial.write(dir);
  }
}
