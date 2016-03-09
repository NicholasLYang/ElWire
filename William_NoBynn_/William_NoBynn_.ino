int LA = 2; // Left Arm
int CH = 3; // Chest Head
int RA = 4; // Right Arm
int LG = 5; // Legs

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
  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);
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
  delay(9161);
  
  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(840);

  strobeFull(57); // <Num * 50 = however many milliseconds = 2874

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(6352); // 12.876 - 19.228

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(600); //19.228 - 19.828

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(1167 + 3210);//19.828 - 24.205

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(1175 + 100 + 223);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);

  delay(100); // 25.701

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(284); 
  
  strobeParts(20, LG); // Num * 200 = 4141 26.085

  digitalWrite(CH, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(LG, LOW);

  delay(705 + 493);

  digitalWrite(CH, HIGH);
  digitalWrite(LA, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(LG, HIGH);
  
  delay(4671);
  
  strobeFull(32); // Num * 50 = 6249
  
  
}  
