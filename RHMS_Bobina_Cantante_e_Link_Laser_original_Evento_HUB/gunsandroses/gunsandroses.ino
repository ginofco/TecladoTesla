#include "pitches.h"

//Sweet Child O Mine- Guns N Roses-------------------------------------------------------------------------------------------------------------------------------
int mainRiffD[] = {NOTE_D4 , NOTE_D5 , NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4};
int mainRiffE[] = {NOTE_E4 , NOTE_D5 , NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4};
int mainRiffG[] = {NOTE_G4 , NOTE_D5 , NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4};
    
int mainRiffDurations[] = {
//d4  d5  a4   g4  g5  g4  fs5  a4  
  6,  6,  6,   6,  6,  6,  6 ,  6};
//----------------------------------------------------------------------------------------------------------------------------------------------
void setup() {

for(int introTwoTimes = 0; introTwoTimes < 2; introTwoTimes++){
  for(int dTwice = 0; dTwice < 2; dTwice++){
    for (int thisNote = 0; thisNote < 8; thisNote++){
      int mainRiffDuration = 1000/mainRiffDurations[thisNote];
      tone(8, mainRiffD[thisNote], mainRiffDuration);
      int pauseBetweenNotes = mainRiffDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
  }
  
  for(int eTwice = 0; eTwice < 2; eTwice++){
    for (int thisNote = 0; thisNote < 8; thisNote++){
      int mainRiffDuration = 1000/mainRiffDurations[thisNote];
      tone(8, mainRiffE[thisNote], mainRiffDuration);
      int pauseBetweenNotes = mainRiffDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
  }
  
  for(int gTwice = 0; gTwice < 2; gTwice++){
    for (int thisNote = 0; thisNote < 8; thisNote++){
      int mainRiffDuration = 1000/mainRiffDurations[thisNote];
      tone(8, mainRiffG[thisNote], mainRiffDuration);
      int pauseBetweenNotes = mainRiffDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
  }
  
  for(int dTwice = 0; dTwice < 2; dTwice++){
    for (int thisNote = 0; thisNote < 8; thisNote++){
      int mainRiffDuration = 1000/mainRiffDurations[thisNote];
      tone(8, mainRiffD[thisNote], mainRiffDuration);
      int pauseBetweenNotes = mainRiffDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
  }
}

while(1); 
}
    
void loop() {

}


