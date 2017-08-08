#include <CurieTimerOne.h>



# define SERIAL_PORT_LOG_ENABLE 1

 const int oneSec=1000000;
 bool toggle=0;
 int time;

 void Blink(){
  digitalWrite(9, toggle);
  toggle= !toggle;
}

void setup() {
  #ifdef SERIAL_PORT_LOG_ENABLE
  Serial.begin(115200);
  while(!Serial);
  #endif

  pinMode(9,OUTPUT);

}

void loop() {

  for(int m=1; m<9;m=m*2){
    time=oneSec/m;
    CurieTimerOne.start(time,&Blink);

    #ifdef SERIAL_PORT_LOG_ENABLE
    Serial.print("The blink period:");
    Serial.println(time);
    #endif
    delay(4000);

    #ifdef SERIAL_PORT_LOG_ENABLE 
    Serial.print("Total number of ticks in 4 seconds");
    Serial.println(CurieTimerOne.rdRstTickCount());
    Serial.println("*******");
    #endif
    }
}
