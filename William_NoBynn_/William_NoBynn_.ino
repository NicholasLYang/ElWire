int LA = 6; // Left Arm PORT A DOES NOT WORK SUBSTITUTED PORT
int CH = 3; // Chest Head
int RA = 4; // Right Arm
int LG = 5; // Legs
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
  delay(9161);

  allOn();
  delay(840);

  strobeFull(57); // <Num * 50 = however many milliseconds = 2874

  allOn();

  delay(6352); // 12.876 - 19.228

  allOff();
  delay(600); //19.228 - 19.828

  allOn();
  delay(1167 + 3210);//19.828 - 24.205

  allOff();
  delay(1175 + 100 + 223);

  allOn();
  delay(100); // 25.701

  allOff();
  delay(284);

  strobeParts(20, LG); // Num * 200 = 4141 26.085

  allOff();
  delay(705 + 493);

  allOn();
  delay(4671);

  strobeFull(32); // Num * 50 = 6249
  delay(120000);
}
