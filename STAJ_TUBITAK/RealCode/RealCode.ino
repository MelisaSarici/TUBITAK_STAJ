
#define Pmax 0
#define previous_t  0
#define D 0

class Power {

  long P;
  long V;
  long I;
  long Increment_value;
  long T;
  long reading_period;
  unsigned long last_t;
  int Current;
  int Voltage;
  
  public: Power(long T,int current, int voltage,long increment_value){
      unsigned long last_t=millis();

      Voltage=voltage;
      Current=current; 
      Increment_value= increment_value;   
      pinMode(current,INPUT);
      pinMode(voltage,INPUT);
    };


    void power(){
       unsigned long last_t=millis();
      
      if (last_t==T){
        I=analogRead(Current);
        V=analogRead(Voltage);
        P=I*V;
        Serial.print("Power of the system:");
        Serial.println(P);
        
          if ((D>=0)&&(D<1)){
            if(P>Pmax){
              D==D+Increment_value;
          }
            else if (P<Pmax){
              D==D-Increment_value;
              }
          }
          return D;   
      }   
      }
  
  };


/////////////////////////////////////////////
void pwm_control(long D,int pin){

  int f;//the predetermined frequency of the signal

  unsigned long time_on=(1/f)*D;
  unsigned long time_off=(1/f)*(1-D);
  pinState=HIGH;

while(1){
 
  if  (pinState=HIGH){
    digitalWrite(pin,pinState);
    if ((millis()-last_time)==time_on){
      pinState=LOW;
      last_time=millis();
      }
  }
      else if (pinState=LOW){
        digitalWrite(pin,pinState);
        if ((millis()-last_time)==time_off)){
          pinState=HIGH;
          last_time=millis();
          
          }
        }
}

  }
  ///////////////////////////////////////

Power(5,5,5,5);

void setup() {
  Serial.begin(9600);
  int PWM_pin=;
}

void loop() {
  D=Power.power();
  pwm_control(D,PWM_pin);

}
