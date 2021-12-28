
const float minValue = 5; //difference between the setvalue and the actual temperature



void warmUp(){
  Serial.println("Working hard to warm the water");
  int state = HIGH;
  unsigned long startedTime = millis();
  
  do{
      checkForThermalRunAway();
      set_temp();
     
      if( (millis()-startedTime) >= led_delay_on_off ){
        startedTime = millis();
        blinkLeds(state);
        state=!state;
      }
  }
  while(abs(read_thermometer()-Setpoint) >= minValue);
  digitalWrite(small_cup_led,LOW);
  digitalWrite(big_cup_led,LOW); 
}


void extrude_Cofee(int pumping_time){
  unsigned long startedTime=millis();
  digitalWrite(pump,HIGH);
  do{
      checkForThermalRunAway();
      set_temp();
  }
  while((millis()-startedTime) < pumping_time);
  digitalWrite(pump,LOW);
  
}

void keepItWarm(){
  checkForThermalRunAway();
  set_temp();
}

void blinkLeds(int state){
   digitalWrite(small_cup_led,state);
   digitalWrite(big_cup_led,state);
}
