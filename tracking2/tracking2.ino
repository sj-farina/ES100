/*************************************
 * Janey Farina
 * ES 100
 * Haptic Glove finger tracking test 2
 * Rotation (dv/dt) sense only, no preasure 
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

int refAngle;

int buff_len = 10;
int reg_buff[] = {0,0,0,0,0,0,0,0,0,0};

void setup() {
  pinMode(TOP_PRESS_PIN, INPUT);
  pinMode(LOW_PRESS_PIN, INPUT);
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(JOINT_POT_PIN, INPUT);
  pinMode(ENCODER_PIN_A, INPUT);
  pinMode(ENCODER_PIN_B, INPUT);
  
  Serial.begin(9600);

  refAngle = 600;
}


//////////////////////////////////////////////////////////////////////////////
// Main Loop
//////////////////////////////////////////////////////////////////////////////


void loop() {
  int angle = analogRead(JOINT_POT_PIN);
  int topPress = analogRead(TOP_PRESS_PIN);
  int lowPress = analogRead(LOW_PRESS_PIN);
  int slope = findSlope(angle);

  Serial.print(angle);
  Serial.print(",");
  Serial.print(angle);
  Serial.print(",");  
  Serial.print(topPress);
  Serial.print(",");  
//  Serial.print(topPress);
//  Serial.print(",");
  Serial.print(lowPress);
  Serial.print(",");  
  Serial.print(",");  
  Serial.println(slope);

  if (slope > 0){
    forward(50);
  }
  else if (slope < 0){
    reverse(60);
  }
  else{
    motorstop();
  }
  
  delay(10);
}

//////////////////////////////////////////////////////////////////////////////
// Magic Functions
//////////////////////////////////////////////////////////////////////////////

int findSlope(int potValue){
  for(int i = 0; i < buff_len - 1; i++){
    reg_buff[i] = reg_buff[i+1];
  }
  reg_buff[buff_len - 1] = potValue;
  
  int slope1 = reg_buff[buff_len/2 - 1] - reg_buff[0];
  int slope2 = reg_buff[buff_len - 1] - reg_buff[buff_len/2 - 1];

  return (slope1+slope2)/2;
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
