
/*
 * RGB LED test
 */
int bright_red = 0;    // how bright the RED LED is
int bright_green = 0;    // how bright the GREEN LED is
int bright_blue = 0;    // how bright the BLUE LED is
int LED_RED = 3;   // PWM pin for red LED
int LED_GREEN = 5; // PWM pin for green LED
int LED_BLUE = 6;  // PWM pin for blue LED


void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensorValue = (float) analogRead(A0);
  Serial.println(sensorValue);

  if ( sensorValue < 320) {
    bright_red = 255 - (int)(255. * (sensorValue / 320.));
    bright_green = (int) (255 * (float)(sensorValue / 320.));
    analogWrite(LED_RED,   bright_red);
    analogWrite(LED_GREEN, bright_green);
    analogWrite(LED_BLUE, 0);
  }

  if (( sensorValue >= 320) && ( sensorValue < 640)) {
    bright_green = 255 - (int)(255. * ((sensorValue-320.) / 320.));
    bright_blue = (int) 255 * (float)((sensorValue-320.) / 320.);
    analogWrite(LED_RED,   0);
    analogWrite(LED_GREEN, bright_green);
    analogWrite(LED_BLUE, bright_blue);
  }

  if (( sensorValue >= 640) && ( sensorValue < 960)) {
    bright_blue = 255 - (int)(255. * ((sensorValue-640.) / 320.));
    bright_red = (int) 255 * (float)((sensorValue-640.) / 320.);
    
    analogWrite(LED_BLUE, bright_blue);
    analogWrite(LED_GREEN, 0);
    analogWrite(LED_RED,  bright_red);
  }
  
  if ( sensorValue >= 960) {
    analogWrite(LED_BLUE, 0);
    analogWrite(LED_GREEN, 0);
    analogWrite(LED_RED,  255);
  }
  
  delay(30);
}
