#define MOTOR1A 6
#define MOTOR1B 5
#define JOINT1 A0
#define PRESS1 A7

int buff_len = 10;
int reg_buff[] = {0,0,0,0,0,0,0,0,0,0};


void setup() {
  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(JOINT1, INPUT);
  pinMode(PRESS1, INPUT);
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
  int pressValue = analogRead(PRESS1);
//  Serial.println(potValue);

  for(int i = 0; i < buff_len -1; i++){
    reg_buff[i] = reg_buff[i+1];
  }
  reg_buff[buff_len -1] = potValue;

  for(int i = 0; i < buff_len -1; i++){
    Serial.print(reg_buff[i]);
    Serial.print(',');
  }  
    Serial.println(' ');

  
  //Serial.print(',');
  //Serial.println(pressValue);
  if (potValue > 100){
    forward();
  }
  else{
    motorstop();
  }
  delay(100);
}

