
// Joystick x- and y- axes are connected to A10 and A9 analog pins of Arduino.

int joyX = A10; //  X - axis of Joystick
int joyY = A9; // y - axis of Joystick
int x, y, dir; 

void setup()
{ 
  Serial.begin(9600);
}

void loop()
{ 
  x = joyX;    // y value btwn 0 and 1023) 
  y = joyY;    // x value btwn 0 and 1023) 
  y = map(analogRead(joyX), 0, 1023, 900, 2100); 
  x = map(analogRead(joyY), 0, 1023, 900, 2100);
  
  if ( x > 1400 && x < 1600 && y > 1400 && y < 1600){
    dir = 0;
  }
  if ( x > 1400 && x < 1600 && y > 2000 && y < 2200){
    dir = 1;
  }
  if ( x > 2000 && x < 2200 && y > 1400 && y < 1600){
    dir = 2;
  }
  if ( x > 1400 && x < 1600 && y > 800 && y < 1000){
    dir = 3;
  }
  if ( x > 800 && x < 1000 && y > 1400 && y < 1600){
    dir = 4;
  }
  if ( x > 800 && x < 1200 && y > 2000 && y < 2200){
    dir = 5;
  }
  if ( x > 2000 && x < 2200 && y > 2000 && y < 2200){
    dir = 6;
  }
  if ( x > 2000 && x < 2200 && y > 800 && y < 1200){
    dir = 7;
  }
  if ( x > 800 && x < 1200 && y > 800 && y < 1200){
    dir = 8;
  }
  
  Serial.println(dir);
}
