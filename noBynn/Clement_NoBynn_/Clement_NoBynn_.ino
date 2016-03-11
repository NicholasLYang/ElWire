int LA = 6;//BAD PORT A
int CH = 7;
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

void allOn(){ 
  digitalWrite(LA, HIGH);
  digitalWrite(CH, HIGH);  
  digitalWrite(RA, HIGH);  
  digitalWrite(LG, HIGH);    
}
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
  strobeFull(3577 / 50);// Integer division???!!! ey
  delay(27);
  allOn();
  delay(377 + 1564 + 841);
  strobeFull(2874 / 50);
  delay(24);
  allOn();
  delay(6352 + 200);
  allOff();
  delay(200 + 200 + 1167);
  allOn();
  delay(3210);
  allOff();
  delay(1175);
  allOn();
  delay(100);
  allOff();
  delay(223 + 100 + 284);
  strobeParts(4141 / 200, 2);
  allOff();
  delay(705);
  allOn();
  delay(493 + 4671 + 6249);
  strobeFull(50);  
  delay(60000);
}
