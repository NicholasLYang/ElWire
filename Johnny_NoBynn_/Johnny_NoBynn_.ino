int LA = 2;
int CH = 6;//PORT B DOES NOT WORK SUBSITUTED PORT E
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
  allOn();
  delay(250);
  allOff();
}


void allOn(){ for(int i = 0; i < sizeof(LEDPINS); i++){ digitalWrite(LEDPINS[i], HIGH); } }
void allOff(){ for(int i = 0; i < sizeof(LEDPINS); i++){ digitalWrite(LEDPINS[i], LOW); } }

//cycle lasts 50ms
void strobeFull(int cycles){
  for (int i = 0; i <= cycles; i++){
    allOff();
    delay(25);

    allOn();
    delay(25);
  }
}

//cycle lasts 200ms, start is int that indicates which indice of LEDPINS to start iterating from
void strobeParts(int cycles, int start){
  for (int cycle = 0; cycle <= cycles; cycle++){
    for(int PIN = start; PIN < start + sizeof(LEDPINS); PIN++){
      digitalWrite(LEDPINS[ PIN % sizeof(LEDPINS) ] , HIGH);
      delay(25);
      
      digitalWrite(LEDPINS[ PIN % sizeof(LEDPINS) ], LOW);
      delay(25);
    }
  }
}

void loop() {
  delay(3558);

  allOn();

  delay(667);

  allOff();

  delay(750);

  allOn();

  delay(750);

  allOff();

  delay(750);

  allOn();

  delay(3800);

  strobeFull(17);

  allOff();
  delay(150);

  allOn();

  delay(8277);

  allOff();

  delay(5702);

  allOn();

  delay(100);

  allOff();

  delay(718);

  strobeParts(28, CH);

  allOn();

  delay(60000);
}
