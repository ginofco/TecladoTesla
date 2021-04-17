/*  Gizmossônico
 *  por Gino Passos
 *  
 *  Demonstracao do uso do sensor ultrassonico HC-SR04
 *  
 *  Utiliza partes do codigo do site
 *  https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
 *  
 * Ultrasonic Sensor HC-SR04 and Arduino Tutorial
 * by Dejan Nedelkovski,
 * www.HowToMechatronics.com
 *
*/
#include "pitches.h"

int bright_red    = 0;   // how bright the RED LED is
int bright_green  = 0;   // how bright the GREEN LED is
int bright_blue   = 0;   // how bright the BLUE LED is
int LED_RED       = 3;   // PWM pin for red LED
int LED_GREEN     = 5;   // PWM pin for green LED
int LED_BLUE      = 6;   // PWM pin for blue LED
int LED_RED2      = 11;  // PWM pin for red LED
int LED_GREEN2    = 10;  // PWM pin for green LED
int LED_BLUE2     = 9;   // PWM pin for blue LED

const int trigPin = 13; //9;   // defines pins numbers
const int echoPin = 12; //10;

const int trigPin2 = 8; //12;   // defines pins numbers
const int echoPin2 = 7; //11;
const int outNotesPin = 2;

long duration;           // defines variables
int  distance;

long duration2;           // defines variables
int  distance2;

int notes[] = { 
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4
};


void setup() {
  pinMode(LED_RED,   OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE,  OUTPUT);
  pinMode(LED_RED2,   OUTPUT);
  pinMode(LED_GREEN2, OUTPUT);
  pinMode(LED_BLUE2,  OUTPUT);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

  pinMode(trigPin2, OUTPUT); // Sets the trigPin2 as an Output
  pinMode(echoPin2, INPUT);  // Sets the echoPin2 as an Input

  Serial.begin(9600);
}

void loop() {
  int sensorValue,sensorValue2,keyNumber;
  int dur1;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor

  sensorValue = 1023.0 * (  ((float) (distance - 5)) / 50.0 );
  if (distance > 50) sensorValue = 1023;
  if (distance < 5) sensorValue  = 0;

  keyNumber = 9 * ( ((float) sensorValue) / 1023.0); 
  if (sensorValue > 960) keyNumber = 9;
  if (sensorValue < 100) keyNumber = 0;

  if ( sensorValue < 320) {
    bright_red = 255 - (int)(255. * (sensorValue / 320.));
    bright_green = (int) (255 * (float)(sensorValue / 320.));
    bright_blue = 0;
  }
  if (( sensorValue >= 320) && ( sensorValue < 640)) {
    bright_red = 0;
    bright_green = 255 - (int)(255. * ((sensorValue-320.) / 320.));
    bright_blue = (int) 255 * (float)((sensorValue-320.) / 320.);
  }

  if (( sensorValue >= 640) && ( sensorValue < 960)) {
    bright_red = (int) 145 * (float)((sensorValue-640.) / 320.);
    bright_green = 0;
    bright_blue = 110 - (int)(110. * ((sensorValue-640.) / 320.));
  }
  if ( sensorValue >= 960) {
    bright_red = 145;
    bright_green = 0;
    bright_blue = 110;
  }
  analogWrite(LED_RED,   bright_red);
  analogWrite(LED_GREEN, bright_green);
  analogWrite(LED_BLUE,  bright_blue);
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);         
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);  
  // Calculating the distance
  distance2= duration2*0.034/2;
  // Prints the distance on the Serial Monitor
  sensorValue2 = 1023.0 * (  ((float) (distance2 - 5)) / 50.0 );
  if (distance2 > 50) sensorValue2 = 1023;
  if (distance2 < 5) sensorValue2  = 0;

  if ( sensorValue2 < 320) {
    bright_red = 255 - (int)(255. * (sensorValue2 / 320.));
    bright_green = (int) (255 * (float)(sensorValue2 / 320.));
    bright_blue = 0;
  }
  if (( sensorValue2 >= 320) && ( sensorValue2 < 640)) {
    bright_red = 0;
    bright_green = 255 - (int)(255. * ((sensorValue2-320.) / 320.));
    bright_blue = (int) 255 * (float)((sensorValue2-320.) / 320.);
  }

  if (( sensorValue2 >= 640) && ( sensorValue2 < 960)) {
    bright_red = (int) 145 * (float)((sensorValue2-640.) / 320.);
    bright_green = 0;
    bright_blue = 110 - (int)(110. * ((sensorValue2-640.) / 320.));
  }
  if ( sensorValue2 >= 960) {
    bright_red = 145;
    bright_green = 0;
    bright_blue = 110;
  }
  analogWrite(LED_RED2,   bright_red);
  analogWrite(LED_GREEN2, bright_green);
  analogWrite(LED_BLUE2,  bright_blue);
  
  dur1 = 0;
  if (distance2 < 50) {
    tone(outNotesPin, notes[keyNumber], 10);
    dur1 = 50 + 200. *( distance2/ 40. );
  }
  delay(dur1);

  //Serial.print("Distance: "); 
  //Serial.print(distance);
  //Serial.print("Distance2: "); 
  //Serial.print(distance2);
  //Serial.print("        sensorValue: "); 
  //Serial.print(sensorValue);
  //Serial.print("        keyNumber: "); 
  //Serial.println(keyNumber);

}
