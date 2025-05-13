int switchPin = 2;  // lüliti 1
int switchPin2 = 1;  // lüliti 2
int potPin = A0;  // potentsiomeeter
int motor1Pin1 = 3;  // viik 2 (L293D)
int motor1Pin2 = 4;  // viik 7 (L293D)
int enablePin = 9;  // viik 1(L293D)

void setup() {
  // sisendid
  pinMode(switchPin, INPUT);
  pinMode(switchPin2, INPUT);
  // väljundid
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
}

void loop() {
  // mootori kiirus
  int motorSpeed = analogRead(potPin);
  // aktiveeri mootor
  if (digitalRead(switchPin2) == HIGH)
  {
    analogWrite(enablePin, motorSpeed);
  }
  else
  {
    analogWrite(enablePin, 0);
  }

  // kui lüliti on HIGH, siis liiguta mootorit ühes suunas:
  if (digitalRead(switchPin) == HIGH)
  {
    digitalWrite(motor1Pin1, LOW);  // viik 2 (L293D) LOW
    digitalWrite(motor1Pin2, HIGH);  // viik 7 (L293D) HIGH
  }
  // kui lüliti on LOW, siis liiguta mootorit teises suunas:
  else
  {
    digitalWrite(motor1Pin1, HIGH);  // viik 2 (L293D) HIGH
    digitalWrite(motor1Pin2, LOW);  // viik 7 (L293D) LOW
  }
}
