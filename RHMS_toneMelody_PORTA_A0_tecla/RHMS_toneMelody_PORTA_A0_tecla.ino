/*
  
*/
#include <CapacitiveSensor.h>
#include "pitches.h"

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2); 

int LED_TEST = 6;

void setup() {
    cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
    Serial.begin(9600);
    pinMode(LED_TEST, OUTPUT);
}

void loop() {
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");
    Serial.println(1024);

    if (total1>400) {
      digitalWrite(LED_TEST, HIGH);   // turn the LED on (HIGH is the voltage level)
      long noteDuration = 1000 / 8;
      tone(A0, NOTE_G5, noteDuration);
    }
    else                      
      digitalWrite(LED_TEST, LOW);

    //noTone(A0);
}
