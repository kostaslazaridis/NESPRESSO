#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <PID_v1.h>
 

 



//============================PINS================================
// constants won't change. They're used here to set pin numbers:
const int small_cup_led = 6;      // the number of the LED pin
const int big_cup_led = 7;      // the number of the LED pin
const int heater = 5;    
const int pump = 9; 
const int small_cup_buttonPin = 2;   
const int big_cup_buttonPin = 3; 
const int thermometerPin = A0;    
//================================================================


const int led_delay_on_off = 500;

const unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

unsigned long previousMillis ;
unsigned long  thermal_runaway_time=1*60000;
   

//======================COFEE PARAMETERS======================
const int small_cup_time=6000; //run time for the pump in milli seconds
const int big_cup_time=11000;  //run time for the pump in milli seconds
double Setpoint = 0; //temperature for the water in degrees

unsigned long time_to_sleep=10000; //time that coffee machine will sleep
//============================================================

//======================PID PARAMETERS======================
//Define Variables we'll be connecting to
double Input, Output;
//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
int WindowSize = 5000;
unsigned long windowStartTime;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
//===========================================================

void setup() {
   Serial.begin(9600);

   /* Setup pin 2,3 as an interrupt and attach handler. */
   attachInterrupt(digitalPinToInterrupt(small_cup_buttonPin), small_cup, RISING);
   attachInterrupt(digitalPinToInterrupt(big_cup_buttonPin)  , big_cup  , RISING);
  
   windowStartTime = millis();
   previousMillis = millis();

   //tell the PID to range between 0 and the full window size
   myPID.SetOutputLimits(0, WindowSize);
   myPID.SetMode(AUTOMATIC);
   
   //---------------------------
   //connecting the components
   //---------------------------
   pinMode(small_cup_buttonPin,INPUT);
   pinMode(big_cup_buttonPin,INPUT);
  
   pinMode(small_cup_led,OUTPUT);
   pinMode(big_cup_led,OUTPUT);

   pinMode(pump,OUTPUT);
   pinMode(heater,OUTPUT);

  
   //----------INITIALIZE----------------//
   digitalWrite(small_cup_led,LOW);        
   digitalWrite(big_cup_led,LOW);     
   warmUp();
   
}



void loop() {

    
    if ((unsigned long)(millis() - previousMillis) >= time_to_sleep) { 
        enterSleep();     
        warmUp();
        previousMillis = millis();
    }
    else{
      keepItWarm();
    }

    
}


  
