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
  delay(3577 + 377 + 1564);
  allOn();
  delay(841);
  
  strobeFull(2874 / 50);//Yay integer division
  delay(24);
  
  allOn();
  delay(6352 + 200 + 200 + 200);
  
  allOff();
  delay(1167 + 3210 + 1175 + 100 + 223);
  
  allOn();
  delay(100);
  
  allOff();
  delay(284);
  
  strobeParts(4141 / 200, 2);
  
  allOff();
  delay(705 + 493);
  
  allOn();
  delay(4671);
  
  strobeFull(6249 / 50); //32144
  
  allOff();  
  delay(60000);
}
