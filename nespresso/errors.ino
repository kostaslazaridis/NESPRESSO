
unsigned long previousTime;
int lastTemp = read_thermometer();
int thermalRunAwayDifference=5;

void checkForThermalRunAway(){
    if(((millis()-previousTime) >= thermal_runaway_time) && (abs(read_thermometer() - lastTemp) <=thermalRunAwayDifference)){
      coolDown();
      errorled();
    }
}

void errorled(){
  int state = HIGH;
  do{
   digitalWrite(small_cup_led,state);
   digitalWrite(big_cup_led,!state);
   delay(led_delay_on_off);
   state=!state;
  }
  while(true);
}
