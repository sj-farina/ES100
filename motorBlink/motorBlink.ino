/*******************
* Test for the Hbridge
* Pins 5 and 6 control
* needs more current than arduino can supply via usb
*
********************/ 

void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}



void loop() {
  digitalWrite(6, HIGH);   
  digitalWrite(5, LOW);   
  delay(1000);  
  digitalWrite(6, LOW);   
  digitalWrite(5, LOW);   
  delay(3000);                         
  digitalWrite(6, LOW);   
  digitalWrite(5, HIGH);   
  delay(1000);    
  digitalWrite(6, LOW);   
  digitalWrite(5, LOW);   
  delay(3000);    
                   
}
