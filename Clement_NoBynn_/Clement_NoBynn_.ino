int LA = 6;//BAD PORT A
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

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(667);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(750);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(750);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(750);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(3800);

  strobeFull(17);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(150);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(8077);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(2053);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(2569);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(1280);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(100);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(718);

  strobeParts(28, RA);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(60000);
}
