const byte LedPin=5;
const byte InterruptPin=2;
volatile byte State=LOW;



void setup() {
  pinMode(LedPin,OUTPUT);
  pinMode(InterruptPin,INPUT);
  attachInterrupt(digitalPinToInterrupt(InterruptPin),myISR,CHANGE);
}

void loop() {
  
  digitalWrite(LedPin,State);
}

void myISR(){
 
  State=!State;
 
}
