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
