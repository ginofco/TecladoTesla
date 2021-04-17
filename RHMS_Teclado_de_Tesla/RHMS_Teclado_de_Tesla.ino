
/** Rio Hack/Maker Space - RHMS
 * 
 * Programa "Teclado de Tesla"
 * Firmware para o Arduino Uno, em circuito com 2 CIs
 * CD74HC4067 multiplexador/demultiplexador de 16 portas
 * 
 * EM DESENVOLVIMENTO com base no material abaixo descrito
 * 
 * This example demonstrates how to read digital signals
 * It assumes there are push buttons with pullup resistors
 * connected to the 16 channels of the 74HC4067 mux/demux
 * 
 * For more about the interface of the library go to
 * https://github.com/pAIgn10/MUX74HC4067
 */

#include "MUX74HC4067.h"
#include "pitches.h"

long duration;           // defines variables

int notes[] = {
   NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5  
};

// Creates a MUX74HC4067 instance
// 1st argument is the Arduino PIN to which the EN pin connects
// 2nd-5th arguments are the Arduino PINs to which the S0-S3 pins connect

//MUX74HC4067 mux1(9, 10, 11, 12, 13);
//MUX74HC4067 mux2(4, 5, 6, 7, 8);
MUX74HC4067 mux1(6, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);  // Initializes serial port
    // Waits for serial port to connect. Needed for Leonardo only
    while ( !Serial ) ;
  
  // Configures how the SIG pin will be interfaced
  // e.g. The SIG pin connects to PIN 3 on the Arduino,
  //      and PIN 3 is a digital input
  mux1.signalPin(A1, INPUT, DIGITAL);
  //mux2.signalPin(2, INPUT, DIGITAL);
}

// Reads the 16 channels and reports on the serial monitor
// if the corresponding push button is pressed
void loop()
{
  byte data1;
  byte data2;

  for (byte i = 0; i < 16; ++i)
  {
    // Reads from channel i and returns HIGH or LOW
    data1 = mux1.read(i);
    //data2 = mux2.read(i);
    
    Serial.print("Push button at channel ");
    Serial.print(i);
    Serial.print(" is ");
    if ( data1 == HIGH ) Serial.println("mux1 not pressed ");
    
    else if ( data1 == LOW ) {
      Serial.println("mux1 pressed ");
      tone(A0, notes[i], 30);
    }
    //if ( data2 == HIGH ) Serial.println(" mux2 not pressed ");
    //else if ( data2 == LOW ) Serial.println(" mux2 pressed ");


    
  }
  Serial.println();
  
  delay(1500);
}
