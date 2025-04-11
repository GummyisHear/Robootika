int sensorPin = 0;
int red1 = 13;
int green1 = 12;
int orange1 = 11;
int blue1 = 10;
int red2 = 9;
int green2 = 8;
int orange2 = 7;
int blue2 = 6;

int ledPins[] = { 13, 12, 11, 10, 9, 8, 7, 6 };

void setup()
{
  int len = sizeof(ledPins) / sizeof(ledPins[0]);
  for (int i = 0; i < len; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  int len = sizeof(ledPins) / sizeof(ledPins[0]);
  for (int i = 0; i < 4; i++) {
    onColor(i, getDelay());
  }
  for (int i = 2; i >= 1; i--) {
    onColor(i, getDelay());
  }
  
  for (int i = 0; i < 4; i++) {
    onColor(rand() % 4, getDelay());  
  }
  for (int i = 0; i < 4; i++) {
    onColor(rand() % 4, getDelay());  
  }
  for (int i = 0; i < 4; i++) {
    onColor(rand() % 4, getDelay());  
  }
}

void onColor(int colorId, int wait) {
  if (colorId == 0) red(wait);
  if (colorId == 1) green(wait);
  if (colorId == 2) orange(wait);
  if (colorId == 3) blue(wait);
}

int getDelay() {
    int sensorValue = analogRead(sensorPin);
    float mult = sensorValue / 1023.0;
    int wait = 50 + mult * 500;
    return wait;
}

void blue(int wait)
{
  digitalWrite(blue1, HIGH);
  digitalWrite(blue2, HIGH);
  delay(wait);
  digitalWrite(blue1, LOW);
  digitalWrite(blue2, LOW);
}

void red(int wait)
{
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  delay(wait);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
}

void green(int wait)
{
  digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);
  delay(wait);
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
}

void orange(int wait)
{
  digitalWrite(orange1, HIGH);
  digitalWrite(orange2, HIGH);
  delay(wait);
  digitalWrite(orange1, LOW);
  digitalWrite(orange2, LOW);
}
