const int led15 = A5;
const int led14 = A4;
const int led13 = 13;
const int led12 = 12;
const int led11 = 11;
const int led10 = 10;
int usedPins[] = {led15, led14, led13, led12, led11, led10};

const int level0 = A0;
const int level1 = A1;
const int level2 = A2;
const int level3 = A3;
int usedLevels[] = {level0, level1, level2, level3};
int x = 0;
int y = 0;
int xLength = sizeof(usedPins) -1;
int yLength = sizeof(usedLevels) -1;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < xLength; i++){
   pinMode(usedPins[i], OUTPUT);
  }
  for (int i = 0; i < yLength; i++){
   pinMode(usedLevels[i], OUTPUT);
   digitalWrite(usedLevels[i], HIGH);
  }
  digitalWrite(usedLevels[y], LOW);
}

void loop() {
  if (x > xLength){
    x = 0;
    digitalWrite(usedLevels[y], HIGH);
    y += 1;
    if (y > yLength) {
      y = 0;
    }
    digitalWrite(usedLevels[y], LOW);
  }
  digitalWrite(usedPins[x], HIGH);
  delay(100);
  digitalWrite(usedPins[x], LOW);
  x += 1;
Serial.println(x,y);
}
