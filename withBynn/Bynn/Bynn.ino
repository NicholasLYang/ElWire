/* NOTE:
BYNNS PORT F USED TO BE BROKEN; NOW iT WORKS
IN ITS PLACE PORT G IS BROKEN! */
int HOOD = 2,
    RARM = 3, LARM = 4,
    CHST = 5, STOM = 6,
    LLEG = 9, RLEG = 8;
int LEDPINS[] = {HOOD, RARM, LARM, CHST, STOM, LLEG, RLEG};
#define NUMPINS 7 // this is here because sizeof array apparently returns bite sized stuff

void setup() {
  setPins();
//  testWires();
}
void loop(){
  strobeAll(3577);
  allOn(377 + 1564 + 1186 + 1075);
  strobeAll(2000);
  allOff(400);
  allOn(6352 + 200 + 200);
  allOff(200 + 200 + 967 + 3210);
  allOn(1175 + 100 + 223 + 100 + 284);
  strobeParts(4141);
  allOn(705 + 493 + 300);
  allOff(4671 + 6249 + 3324);
  upperHalf();
  delay(50);
  lowerHalf();
  delay(20000);
  allOff();
  delay(120000);
  
  allOff(60000);//restarts after 1 min
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
void lowerHalf(){
  digitalWrite(LLEG, HIGH);
  digitalWrite(RLEG, HIGH);
}
void upperHalf(){
  digitalWrite(HOOD, HIGH);
  digitalWrite(RARM, HIGH);
  digitalWrite(LARM, HIGH);
  digitalWrite(CHST, HIGH);
  digitalWrite(STOM, HIGH);
}
