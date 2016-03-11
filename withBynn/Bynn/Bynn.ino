int HO = 2, 
    RA = 3,
    LA = 4,
    CH = 5,
    ST = 6,
    LL = 9,
    RL = 8;
int LEDPINS[] = {HO, RA, LA, CH, ST, LL, RL};

void setup() {
  setPins();
//  testWires();
}
void loop(){
  strobeFull(3577);
  allOn(377 + 1564 + 1186 + 1075);
  strobeFull(2000);
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

//=================BEGIN FUNCTION BLOCK=============================
void setPins(){
  for(int PININDEX = 0; PININDEX < sizeof(LEDPINS); PININDEX++){
    pinMode(LEDPINS[PININDEX], OUTPUT);
  }
}
void testWires(){
//  allOn(2500);
//  allOff(300);
//  allOn(2500);
//  allOff(300);
//  allOn(2500);
//  allOff(300);
//  allOn(2500);
//  allOff(300);
}
//v time is in ms! turns on for (time) ms!
void allOn(){// ALL ON WITHOUT DELAY
  for(int PININDEX = 0; PININDEX < sizeof(LEDPINS); PININDEX++){
    digitalWrite(LEDPINS[PININDEX], HIGH);
  }
}
void allOn(int time){// ALL ON WITH DELAY
  for(int PININDEX = 0; PININDEX < sizeof(LEDPINS); PININDEX++){
    digitalWrite(LEDPINS[PININDEX], HIGH);
  }
  delay(time);
}
void allOff(){// ALL OFF WITHOUT DELAY
  for(int PININDEX = 0; PININDEX < sizeof(LEDPINS); PININDEX++){
    digitalWrite(LEDPINS[PININDEX], LOW);
  }
}
void allOff(int time){// ALL OFF WITH DELAY
  for(int PININDEX = 0; PININDEX < sizeof(LEDPINS); PININDEX++){
    digitalWrite(LEDPINS[PININDEX], LOW);    
  }
  delay(time);
}
void strobeFull(int cycles){// STROBE ENTIRE SUIT, CYCLE LASTS 200 MS EACH
  cycles /= 800;
  int extra = cycles % 800;
  for (int i = 0; i <= cycles; i++){
    allOff(400);
    allOn(400);
  }
  allOff();// JUST TO MAKE SURE THEY TURN THE FUCK OFF
  allOn(extra);
  allOff();
}
void strobeParts(int cycles){//cycle lasts 200ms, turns on body parts separately.
  int start = 2;
  int strobespeed = 100;// > 50 please dont break it!
  cycles /= 2 * strobespeed * sizeof(LEDPINS);
  int extra = cycles % ( 2 * strobespeed * sizeof(LEDPINS) );
  for (int cycle = 0; cycle <= cycles; cycle++){
    for(int PIN = start; (unsigned)PIN < start + sizeof(LEDPINS); PIN++){
      digitalWrite(LEDPINS[ PIN % sizeof(LEDPINS) ] , HIGH);
      delay(strobespeed);
      digitalWrite(LEDPINS[ PIN % sizeof(LEDPINS) ], LOW);
      delay(strobespeed);
    }
  }
  allOff();
  allOn(extra);
  allOff();
}
//===============END FUNCTION BLOCK=====================
void lowerHalf(){
  digitalWrite(LL, HIGH);
  digitalWrite(RL, HIGH);
}
void upperHalf(){
  digitalWrite(HO, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(CH, HIGH);
  digitalWrite(ST, HIGH);
}
