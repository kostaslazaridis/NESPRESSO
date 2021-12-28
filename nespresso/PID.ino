

void set_temp(){
   Input = read_thermometer();
   myPID.Compute();
   if (millis() - windowStartTime > WindowSize){ 
   //time to shift the Relay Window
      windowStartTime += WindowSize;
   }
   if (Output < millis() - windowStartTime){
     digitalWrite(heater, HIGH);
   }
   else
     digitalWrite(heater, LOW);
}

void coolDown(){
  myPID.SetMode(MANUAL);
  digitalWrite(heater, LOW);
}
