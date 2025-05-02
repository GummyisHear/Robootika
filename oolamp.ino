const int ledPins[] = {10, 9, 8};
const int SensorPin = A0;
const int treshold = 300;

int cycle = 0;
 
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 9; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}
 
void loop() {
  lightShow();
}
 
void lightShow() {
  int potValue = analogRead(SensorPin);
  float rad = 0.024;
  int brightness = map(potValue, treshold, 1023, 300, 255);
 
  if (potValue < treshold) {
    setRGB(0, 0, 0);
    return;
  } 

  cycle = (cycle + 1) % 255;
  float c = cycle / 255.0 * M_PI;
  int r = sin(c) * 255;
  int g = sin(c) * 255;
  int b = sin(c) * 255; 
  Serial.println("C: " + String(c) + " R: " + String(r) + "G: " + String(g) + "B: " + String(b));
  
  setRGB(r, g, b);
  delay(10);
}
 
void setRGB(int red, int green, int blue) {
  analogWrite(ledPins[0], red);
  analogWrite(ledPins[2], green);
  analogWrite(ledPins[1], blue);
}
