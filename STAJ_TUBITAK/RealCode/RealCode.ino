int Current = A0;
int Voltage = A1;
      
      
      float D=0.00;
      float I;
      float V;
      float Increment_value=1.00;
      unsigned long start=0;


      
void setup() {
  Serial.begin(9600);
  pinMode(Current,INPUT);
  pinMode(Voltage,INPUT);
 
}

void loop() {
  float D=power();
  analogWrite(3,D);
}



float power(){
       float Pmax=0;
       float P;
      unsigned long T= 2000;
      unsigned long last_t=millis();
     if((last_t-start)>=T){
        start=last_t;
        I=analogRead(Current)*4.50/1024.00;
        V=analogRead(Voltage)*4.50/1024.00;
        P=I*V;
        Serial.print("Power of the system: ");
        Serial.println(P);
        Serial.print("Battery Voltage is ");
        Serial.println(V ,"V");
        Serial.print("Battery Current is ");
        Serial.println(I, "A");
        Serial.println();

    if ((V<4.3)&&(I<0.5)){
          if ((D>=0.00)&&(D<255.00)){
            if(P>=Pmax){
              D=D+Increment_value;
              Pmax=P;
              Serial.println(D);
              Serial.println("***");

          }
            else if (P<Pmax){
              D=D-Increment_value;
              Serial.println(D);
              Serial.println("***");

              
              }
          }
          Serial.println(Pmax); 
          return D;
            
  
    }
      }
}
