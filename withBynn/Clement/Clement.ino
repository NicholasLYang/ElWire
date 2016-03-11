/* CLEMENTS BOARD!
PORT A AND PORT E BROKEN!
PORT A REPLACED WITH PORT F */
int LARM = 7, CHST = 3,
    RARM = 4, LEGS = 5;
int LEDPINS[] = {LARM, CHST, RARM, LEGS};
#define NUMPINS 4

void setup() {
  setPins();
//  testPins();
}
void loop(){
  allSync();
//  uniqueLights();
  delay(60000);//restarts after 1 min
}
//============begin timing functions============================
void allSync(){
  slowFlicker(6300);// 0:00 - 6:30 
  allOn(4150);// 6:30 - 10:45
  strobeAll(1210);//10:45 - 11:66
  allOn(4510);//11:66 - 16:17
  strobeAll(8300);//16:17 - 17:00
  strobeParts(12520);//17:00 - 29:52
  slowFlicker(8480);//29:52 - 38:00
  allOn(300000);//38:00 - end
}
void uniqueLights(){
  delay(3577 + 377);
  allOn(1564 + 841);
  strobeAll(2874);
  allOn(6352 + 200 + 200 + 200);
  allOff(200 + 967 + 3210 + 1175);
  allOn(100);
  allOff(223 + 100 + 284);
  strobeParts(4141);
  allOff(705);
  allOn(493 + 4671 + 6249);
  strobeAll(3724 + 523);
  allOff(20);
}

//============end timing functions==============================
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
  int strobePeriod = 400;//ms -> REMEMBER PERIOD IS ONE COMPLETE CYCLE!
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
void slowFlicker(int duration){
  int strobeOn = 300;
  int strobeOff = 100;
  int overlapTime = duration % (strobeOn + strobeOff);
  for(int currcycle = 0; currcycle < duration / (strobeOn + strobeOff); currcycle++){
    allOn(strobeOn);
    allOff(strobeOff);  
  }
  allOn(overlapTime);
  allOff();
}
//============end wire functions==================================
