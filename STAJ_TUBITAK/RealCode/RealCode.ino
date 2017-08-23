

// Frequency modes for TIMER4
#define PWM187k 1   // 187500 Hz
#define PWM94k  2   //  93750 Hz
#define PWM47k  3   //  46875 Hz
#define PWM23k  4   //  23437 Hz
#define PWM12k  5   //  11719 Hz
#define PWM6k   6   //   5859 Hz
#define PWM3k   7   //   2930 Hz

// Direct PWM change variables
#define PWM6        OCR4D
#define PWM13       OCR4A

// Terminal count
#define PWM6_13_MAX OCR4C

int Current = A0;
int Voltage = A1;
      
      float P;
      float Pmax=0.00;
      float D=0.00;
      float I;
      float V;
      float Increment_value=1.00;
      unsigned long start=0;

// Configure the PWM clock
// The argument is one of the 7 previously defined modes
void pwm613configure(int mode)
{
// TCCR4A configuration
TCCR4A=0;

// TCCR4B configuration
TCCR4B=mode;

// TCCR4C configuration
TCCR4C=0;

// TCCR4D configuration
TCCR4D=0;

// TCCR4D configuration
TCCR4D=0;

// PLL Configuration
// Use 96MHz / 2 = 48MHz
PLLFRQ=(PLLFRQ&0xCF)|0x30;
// PLLFRQ=(PLLFRQ&0xCF)|0x10; // Will double all frequencies

// Terminal count for Timer 4 PWM
OCR4C=255;
}

// Set PWM to D6 (Timer4 D)
// Argument is PWM between 0 and 255
void pwmSet6(int value)
{
OCR4D=value;   // Set PWM value
DDRD|=1<<7;    // Set Output Mode D7
TCCR4C|=0x09;  // Activate channel D
}

// Set PWM to D13 (Timer4 A)
// Argument is PWM between 0 and 255



      
void setup() {
  Serial.begin(9600);
   pwm613configure(PWM23k);

  pinMode(Current,INPUT);
  pinMode(Voltage,INPUT);
 
}

void loop() {
  float D=power();
  pwmSet6(D);
}



float power(){
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
            
            if (P>=Pmax){
              D=D+Increment_value;
              Pmax=P;
              Serial.println(D);
              Serial.println("++++++++++++++++++++++++++++++++ D is incremented +++++++++++++++++++++++++++++++++");

          }
            else if (P<Pmax){
              D=D-Increment_value;
              Pmax=P;
              Serial.println(D);
              Serial.println("-------------------------------- D is decremented ----------------------------------");

              
              }
          }
          Serial.print("Maximum Power of the system is ");
          Serial.println(Pmax); 
          return D;
            
  
    }
      }
}
