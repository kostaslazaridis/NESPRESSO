


void small_cup(){
    digitalWrite(small_cup_led,HIGH); //turn the small cup led on    
    extrude_Cofee(small_cup_time);    //extrude coffee
    digitalWrite(small_cup_led,LOW);  //turn the small cup led off
    previousMillis = millis();        //store the last moment that the coffee machine did smthg
}

void big_cup(){
    digitalWrite(big_cup_led,HIGH);   //turn the big cup led on
    extrude_Cofee(big_cup_time);      //extrude coffee
    digitalWrite(big_cup_led,LOW);    //turn the big cup led off
    previousMillis = millis();        //store the last moment that the coffee machine did smthg
}
