class Blink {
  //member variables
  int pin;
  long lastTime;
  long refTime;
  long intervalOn;
  long intervalOff;
  

  //constructor

  public: 
  Blink(int PinNumber,long OnTime,long OffTime){
    //initialize the member variables to the inputs
    refTime=0;
    lastTime=millis();
    
    pin=PinNumber;
    intervalOn=OnTime;
    intervalOff=OffTime;
    
    
    pinMode(pin,OUTPUT);
    
    }

  void update(){
    if ((lastTime-refTime)>intervalOn&&(digitalRead(pin)==HIGH)){
      refTime=lastTime;
      digitalWrite(pin,LOW);
      Serial.println("led Low");
      }
      if((lastTime-refTime)>intervalOff&&(digitalRead(pin)==LOW)){
        refTime=lastTime;
      digitalWrite(pin,HIGH);
            Serial.println("led high");

        }
    }
  
  };

Blink led1(5,300,700);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
 led1.update();
 }
