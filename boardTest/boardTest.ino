int A = 2, B = 3, C = 4, D = 5, E = 6, F = 7, G = 8, H = 9;
int LEDPINS[] = {A, B, C, D, E, F, G, H};
#define NUMPINS 8
void setup(){
  setPins();
  testPins();
}
void loop(){
  testPins();
}

//============begin setup functions=============================
void setPins(){
  for(int PININDEX = 0; PININDEX < NUMPINS; PININDEX++){
    pinMode( LEDPINS[PININDEX], OUTPUT ); 
  }
}
void testPins(){
  for(int PININDEX = 0; PININDEX < NUMPINS; PININDEX++){
    digitalWrite( LEDPINS[PININDEX], HIGH);
    delay(250);
    digitalWrite( LEDPINS[PININDEX], LOW);
  }
  allOn(3000);
  allOff(3000);
  strobeAll(3000);
  strobeParts(10000);
}
//==========end setup functions==================================
//==========begin wire functions=================================
void allOn(){// Turns every pin on and leaves it on
  for(int PININDEX = 0; PININDEX < NUMPINS; PININDEX++){
    digitalWrite( LEDPINS[PININDEX], HIGH);
  }
}
void allOn(int timeOn){// Turns every pin on->delays->leaves on
  allOn();
  delay(timeOn);
}
void allOff(){//Turns every PIN off and leaves it off
  for(int PININDEX = 0; PININDEX < NUMPINS; PININDEX++){
    digitalWrite( LEDPINS[PININDEX], LOW);
  }
}
void allOff(int timeOff){// Turns every PIN off->delay->leaves off
  allOff();
  delay(timeOff);
}
void strobeAll(int duration){// FLICKERS ALL PINS - pls make strobeperiod even
  int strobePeriod = 500;//ms -> REMEMBER PERIOD IS ONE COMPLETE CYCLE!
  int overlapTime = duration % strobePeriod;
  for(int currcycle = 0; currcycle < duration / strobePeriod; currcycle++){
    allOn(strobePeriod / 2);
    allOff(strobePeriod / 2);
  }
  allOn(overlapTime);
  allOff();
}
void strobeParts(int duration){//Flickers different body parts at different intervals!
  int singleFlickerPeriod = 100;// How long a single pin is on for
  int strobePeriod = NUMPINS * singleFlickerPeriod;  
  int overlapTime = duration % strobePeriod;
  for(int currcycle = 0; currcycle < duration / strobePeriod; currcycle++){
    for( int PININDEX = 0; PININDEX < NUMPINS; PININDEX++){
      digitalWrite( LEDPINS[ PININDEX ], HIGH);
      delay(singleFlickerPeriod);
      digitalWrite( LEDPINS[ PININDEX ], LOW);
    }
  }
  allOn(overlapTime);
  allOff();
}
//============end wire functions==================================

