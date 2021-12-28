

// Variables will change:
int bigcup_State = LOW;             // boolean variable if button was pressed

int bigcup_buttonState = LOW;       // the current reading from the input pin
int bigcup_lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long bigcup_lastDebounceTime = 0;  // the last time the output pin was toggled



int big_cup_button() {


   
  // read the state of the switch into a local variable:
    int bigcup_read = digitalRead(big_cup_buttonPin);
        
    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:
  
    // If the switch changed, due to noise or pressing:
    if (bigcup_read != bigcup_lastButtonState) {
      // reset the debouncing timer
      bigcup_lastDebounceTime = millis();
    }
  
    if ((millis() - bigcup_lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:
  
      // if the button state has changed:
      if (bigcup_read != bigcup_buttonState) {
        bigcup_buttonState = bigcup_read;
  
        // only toggle the LED if the new button state is HIGH
        if (bigcup_buttonState == HIGH) {
          bigcup_State = !bigcup_State;
        }
      }
    }
  
    // save the reading. Next time through the loop, it'll be the lastButtonState:
    bigcup_lastButtonState = bigcup_read;
    
    // set the LED:
  
    return bigcup_State;

}


void resetBigCupButton(){
  bigcup_State = LOW;         // the current state of the output pin
  bigcup_lastButtonState = LOW;   // the previous reading from the input pin
}
