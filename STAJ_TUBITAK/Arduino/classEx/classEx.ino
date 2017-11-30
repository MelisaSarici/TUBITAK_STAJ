class Blink {
  //member variables
  int pin;
  unsigned long lastTime;
  long refTime;
  long intervalOn;
  long intervalOff;

  

  //constructor

  public: 
  Blink(int PinNumber,long OnTime,long OffTime){
    //initialize the member variables to the inputs
    refTime=0;
    
    pin=PinNumber;
    intervalOn=OnTime;
    intervalOff=OffTime;
    
    
    pinMode(pin,OUTPUT);
    digitalWrite(pin,LOW);
    
    };

  void K(){
         lastTime=millis();

    if (((lastTime-refTime)>=intervalOn)&&(digitalRead(pin)==HIGH)){
      refTime=lastTime;
      digitalWrite(pin,LOW);
      Serial.println("led Low");
      }
      if(((lastTime-refTime)>=intervalOff)&&(digitalRead(pin)==LOW)){
        refTime=lastTime;
      digitalWrite(pin,HIGH);
            Serial.println("led high");

        }
    }
  
  };


class Control{
  int ControlPin1;
  int ControlPin2;
  
  
  public:
  Control(int pin1,int pin2){
    ControlPin1=pin1;
    ControlPin2=pin2;
    pinMode(ControlPin1,OUTPUT);
    pinMode(ControlPin2,OUTPUT);
    }


void Cont(){

  if(digitalRead(ControlPin1)==LOW){
    digitalWrite(ControlPin2,HIGH);
    }
  else digitalWrite(ControlPin2,LOW);
  }
  
};


Blink led1(5,300,700);
Control leds(5,9);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
 led1.K();
 leds.Cont();
 }

 

