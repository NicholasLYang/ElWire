int LA = 2;
int CH = 3;
int RA = 4;
int LG = 5;

void setup() {
  pinMode(CH, OUTPUT);
  pinMode(LA, OUTPUT);  
  pinMode(RA, OUTPUT);
  pinMode(LG, OUTPUT);
}

//cycle lasts 50ms
void strobeFull(int cycles){
  for (int i = 0; i <= cycles; i++){ 
    digitalWrite(CH, LOW);  
    digitalWrite(LG, LOW); 
    digitalWrite(LA, LOW); 
    digitalWrite(RA, LOW);

    delay(25);

    digitalWrite(CH, HIGH); 
    digitalWrite(LG, HIGH); 
    digitalWrite(LA, HIGH); 
    digitalWrite(RA, HIGH);

    delay(25);
  }
}

//cycle lasts 200ms
void strobeParts(int cycles, int start){
  int x = start - 2;
  for (int i = 0; i <= cycles; i++){
    digitalWrite(x, HIGH);
    delay(25);
    digitalWrite(x, LOW);
    delay(25);
    digitalWrite((x+1)%4, HIGH);
    delay(25);
    digitalWrite((x+1)%4, LOW);
    delay(25);
    digitalWrite((x+2)%4, HIGH);
    delay(25);
    digitalWrite((x+2)%4, LOW);
    delay(25);
    digitalWrite((x+3)%4, HIGH);
    delay(25);
    digitalWrite((x+3)%4, LOW);
    delay(25);  
  } 
}

void loop() {
  delay(9105);
  
  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(1170);

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

  delay(7877);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(620);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(2986);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(2893);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(10);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  strobeParts(28, LG);

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(367);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);
  
  delay(60000);
}  
