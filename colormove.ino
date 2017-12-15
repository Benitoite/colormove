// Colormove by Richard E. Barber
// 15 DEC 2017

//declare pin assignments

int r = 10;
int g = 9;
int b = 11;
int r2 = 6;
int g2 = 3;
int b2 = 5;

int pushSW=A5;

//declare some variables

int varR = 127;
int varB = 127;
int varG = 127;

int sw=0;

int x=512;
int y=512;


// the setup routine runs once when you press reset:
void setup() {         


  // initialize the pins
  pinMode(pushSW, INPUT_PULLUP);
  pinMode(r, OUTPUT);   
  pinMode(g, OUTPUT);   
  pinMode(b, OUTPUT);   
  pinMode(r2, OUTPUT);   
  pinMode(g2, OUTPUT);   
  pinMode(b2, OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {

  x = analogRead(A0);      //Read joystick
  y = analogRead(A1);
  varR =  (x/4);
  varB =  (y/4);
  varG = -x/4+256;
  analogWrite(r2,varR);    //PWM an LED
  analogWrite(b2,varB);
  analogWrite(g2,varG);
  
  sw=!digitalRead(pushSW); //inverting the switch logic

  if (sw){
    analogWrite(r,varR);  //PWM the other LED
    analogWrite(b,varB);
    analogWrite(g,varG);
  }
  else{
    digitalWrite(r,LOW);  //keep it off
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
  }

}
