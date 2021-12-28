
void enterSleep(void){
  Serial.println("Good Night");
  Serial.println("Going to sleep Zzz");
  delay(500);
  /* Setup pin 2,3 as an interrupt and attach handler. */
  attachInterrupt(0, interrupt, RISING);
  attachInterrupt(1, interrupt, RISING);
  coolDown();
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  /* The program will continue from here. */
  /* First thing to do is disable sleep. */
  sleep_disable(); 
  myPID.SetMode(AUTOMATIC);
}
