
void enterSleep(void){
  Serial.println("Good Night");
  Serial.println("Going to sleep Zzz");
  delay(500);
  coolDown();
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  /* The program will continue from here. */
  /* First thing to do is disable sleep. */
  sleep_disable(); 
  myPID.SetMode(AUTOMATIC);
}
