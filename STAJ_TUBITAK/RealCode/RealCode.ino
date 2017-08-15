

void setup() {
  Serial.begin(9600);
 
}

void loop() {
  float DUTYcycle=power();
  analogWrite(5,DUTYcycle);

}



float power(){
      int T= 1000;
      unsigned long last_t=millis();
      int Current = A0;
      int Voltage = A1;
      float D=0;
      float P;
      float I;
      float V;
      float Increment_value=0.01;
      int Pmax=0;
      float DC;
      
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
          DC=D*255;
          return DC;   
  
  }
}
