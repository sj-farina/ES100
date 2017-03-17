/***********************
 * First basic tracking and stopping
 * 
************************/


#define MOTOR1A 6
#define MOTOR1B 5
#define JOINT1 A0
#define PRESS1 A7

void setup() {
  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(JOINT1, INPUT);
  pinMode(PRESS1, INPUT);
  Serial.begin(9600);
}


void forward() {
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

int iscontact(int pressValue){
  if (pressValue < 990 - 5){
    return 1;
  }
  else{
    return 0;
  }
}

int zoneFind(int angle){
  int cutoff = 100;
  if (angle < cutoff){
    return 1;
  }
  else{
    return 0;
  }
}

void loop() {
  int potValue = analogRead(JOINT1);
  int pressValue = analogRead(PRESS1);
//  angle = angleFind(
  int angle = potValue;
  int zone = zoneFind(angle);
  int contact = iscontact(pressValue);
      Serial.println(zone);
      Serial.println(contact);
      Serial.println(pressValue);

  if (zone == 1){
    if (contact == 0){
      Serial.println("hold");
      motorstop();
    }
    else{
      Serial.println("forward");
      forward();
    }
  }
  else{
    Serial.println("back");
    reverse();

  }
  delay(100);
}




