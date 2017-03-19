/*************************************
 * Janey Farina
 * ES 100
 * Haptic Glove finger tracking test 2
 *************************************/



//////////////////////////////////////////////////////////////////////////////
// SETUP
//////////////////////////////////////////////////////////////////////////////


// Pin Definitions
#define TOP_PRESS_PIN A6
#define LOW_PRESS_PIN A7
#define MOTOR_PIN_A 6
#define MOTOR_PIN_B 5
#define JOINT_POT_PIN A0
#define ENCODER_PIN_A A1
#define ENCODER_PIN_B A2

// Zone definitions
#define FREE 1
#define BLOCK 0
#define TOUCH 1
#define NO_TOUCH 0

int refAngle = 500;
int zone = FREE;

void setup() {
  pinMode(TOP_PRESS_PIN, INPUT);
  pinMode(LOW_PRESS_PIN, INPUT);
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(JOINT_POT_PIN, INPUT);
  pinMode(ENCODER_PIN_A, INPUT);
  pinMode(ENCODER_PIN_B, INPUT);
  
  Serial.begin(9600);

  int refAngle = 700;
  int zone = FREE;
}


//////////////////////////////////////////////////////////////////////////////
// Main Loop
//////////////////////////////////////////////////////////////////////////////


void loop() {
  int angle = analogRead(JOINT_POT_PIN);
  int topPress = analogRead(TOP_PRESS_PIN);
  int lowPress = analogRead(LOW_PRESS_PIN);

  Serial.print(topPress);
  Serial.print(",");
  Serial.println(lowPress);


  zone = getZone(angle);

  if (zone == FREE){
    if (topPress < 1020 || lowPress < 1000){
      forward(100);
    }
    else{
      motorstop();
    }
  }
  else if (zone == BLOCK){
    reverse(200);
  }
  else{
    motorstop();
  }
  delay(10);
}

//////////////////////////////////////////////////////////////////////////////
// Magic Functions
//////////////////////////////////////////////////////////////////////////////


int getZone(int angle){
  if (angle > refAngle){
    return BLOCK;
  }
  else{
    return FREE;
  }
}


//////////////////////////////////////////////////////////////////////////////
// Motor Control 
//////////////////////////////////////////////////////////////////////////////


void forward(int mspeed) {
  digitalWrite(MOTOR_PIN_A, LOW);   
  analogWrite(MOTOR_PIN_B, mspeed);  
}

void reverse(int mspeed) {
  analogWrite(MOTOR_PIN_A, mspeed);   
  digitalWrite(MOTOR_PIN_B, LOW);  
}

void motorstop() {
  digitalWrite(MOTOR_PIN_A, LOW);   
  digitalWrite(MOTOR_PIN_B, LOW);  
}
