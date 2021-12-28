

// Variables will change:
int smallcup_State = LOW;         // the current state of the output pin
int smallcup_buttonState;             // the current reading from the input pin
int smallcup_lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long smallcup_lastDebounceTime = 0;  // the last time the output pin was toggled


int small_cup_button() {
  // read the state of the switch into a local variable:
  int smallcup_read = digitalRead(small_cup_buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (smallcup_read != smallcup_lastButtonState) {
    // reset the debouncing timer
    smallcup_lastDebounceTime = millis();
  }

  if ((millis() - smallcup_lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (smallcup_read != smallcup_buttonState) {
      smallcup_buttonState = smallcup_read;

      // only toggle the LED if the new button state is HIGH
      if (smallcup_buttonState == HIGH) {
        smallcup_State = !smallcup_State;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  smallcup_lastButtonState = smallcup_read;
  
  // set the LED:

  return smallcup_State;


}

void resetSmallCupButton(){
  smallcup_State = LOW;         // the current state of the output pin
  smallcup_lastButtonState = LOW;   // the previous reading from the input pin
}
