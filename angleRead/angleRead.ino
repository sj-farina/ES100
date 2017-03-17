/***********************
* Test setup to characterize the pot and pressure sensor
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


void forward() {
  //Serial.println("forward");
  digitalWrite(MOTOR1A, LOW);   
  digitalWrite(MOTOR1B, HIGH);  
}

void reverse() {
  digitalWrite(MOTOR1A, HIGH);   
  digitalWrite(MOTOR1B, LOW);  
}

void motorstop() {
  digitalWrite(MOTOR1A, LOW);   
  digitalWrite(MOTOR1B, LOW);  
}

void loop() {
  int potValue = analogRead(JOINT1);
  int pressValue1 = analogRead(PRESS1);
  int pressValue2 = analogRead(PRESS2);
  Serial.print(potValue);
  Serial.print(',');
  Serial.print(pressValue1);
  Serial.print(',');
  Serial.println(pressValue2);
  if (potValue > 100){
    forward();
  }
  else{
    motorstop();
  }
  delay(100);
}



