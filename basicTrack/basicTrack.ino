/***********************
 * First basic tracking and stopping
 * Angle runs 490 - 755 on Arduino @ 5v
************************/

#define MOTOR1A 6
#define MOTOR1B 5
#define JOINT1 A0
#define PRESS1 A7
#define PRESS2 A6

void setup() {
  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(JOINT1, INPUT);
  pinMode(PRESS1, INPUT);
  pinMode(PRESS2, INPUT);

  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(JOINT1);
  int pressValue = analogRead(PRESS1);
  int angle = potValue;

  if (angle > 700){
    reverse(200);
  }
  else if (angle < 550){
    forward(255);
  }
  else{
    motorstop();
  }
  delay(100);
}




void forward(int mspeed) {
  digitalWrite(MOTOR1A, LOW);   
  analogWrite(MOTOR1B, mspeed);  
}

void reverse(int mspeed) {
  analogWrite(MOTOR1A, mspeed);   
  digitalWrite(MOTOR1B, LOW);  
}

void motorstop() {
  digitalWrite(MOTOR1A, LOW);   
  digitalWrite(MOTOR1B, LOW);  
}



