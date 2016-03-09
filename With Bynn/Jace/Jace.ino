int LA = 2;
int CH = 3;
int RA = 4;
int LG = 5;
int LEDPINS[] = {LA, CH, RA, LG};

void setup() {
  pinMode(CH, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(RA, OUTPUT);
  pinMode(LG, OUTPUT);
  testWires();
}

void testWires(){
  allOn(250);
  allOff(0);
}

//v time is in ms! turns on for (time) ms!
void allOn(int time){ for(int i = 0; (unsigned)i < sizeof(LEDPINS); i++){ digitalWrite(LEDPINS[i], HIGH); } delay(time);}
void allOff(int time){ for(int i = 0; (unsigned)i < sizeof(LEDPINS); i++){ digitalWrite(LEDPINS[i], LOW); } delay(time);}

//cycle lasts 50ms
void strobeFull(int cycles){
  for (int i = 0; i <= cycles; i++){
    allOff(25);
    allOn(25);
  }
}

//cycle lasts 200ms, start is int that indicates which indice of LEDPINS to start iterating from
void strobeParts(int cycles, int start){
  for (int cycle = 0; cycle <= cycles; cycle++){
    for(int PIN = start; (unsigned)PIN < start + sizeof(LEDPINS); PIN++){
      digitalWrite(LEDPINS[ PIN % sizeof(LEDPINS) ] , HIGH);
      delay(25);
      digitalWrite(LEDPINS[ PIN % sizeof(LEDPINS) ], LOW);
      delay(25);
    }
  }
}

void loop(){
  delay(3577 + 377 + 1564);
  allOn(841);
  strobeFull(2874 / 50);
  delay(24);
  allOn(6352 + 200 + 200 + 200 + 200);
  allOff(967 + 3210 + 1175 + 100 + 223);
  allOn(100);
  allOff(284);
  strobeParts( 4141 / 200, 2);
  delay(141);
  allOff(705 + 493);
  allOn(4671);
  strobeFull( (3724 + 523) / 50);
  
  delay(60000);//restarts after 1 min
}
