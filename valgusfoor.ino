const int RED_PIN = 13;

const int YELLOW_PIN = 12;

const int GREEN_PIN = 11;

const int DAY_PIN = 8;

const int NIGHT_PIN = 7;

void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(DAY_PIN, OUTPUT);
  pinMode(NIGHT_PIN, OUTPUT);
}

void loop()
{
  paev();
  paev();
  oo();
}

void paev()
{
  digitalWrite(DAY_PIN, HIGH);
  
  digitalWrite(RED_PIN, HIGH);
  delay(1500);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(1000);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(1500);
  for (int i = 0; i < 6; i++) {
    digitalWrite(GREEN_PIN, HIGH);
    delay(300);
    digitalWrite(GREEN_PIN, LOW);
    delay(300);
  }
  digitalWrite(YELLOW_PIN, HIGH);
  delay(1000);
  digitalWrite(YELLOW_PIN, LOW);

  digitalWrite(DAY_PIN, LOW);
}

void oo()
{
  digitalWrite(NIGHT_PIN, HIGH);

  for (int i = 0; i < 12; i++) {
    digitalWrite(YELLOW_PIN, HIGH);
    delay(300);
    digitalWrite(YELLOW_PIN, LOW);
    delay(300);
  }
  
  digitalWrite(NIGHT_PIN, LOW);
}
