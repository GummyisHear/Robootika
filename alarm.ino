#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A1;
const int lightPin = A0;
const int humidityPin = A2;
const int buzzerPin = 8;

float temperature;
float voltage;
float degreesF;
int lightLevel;
int humidityLevel;

unsigned long previousMillis = 0;
const long interval = 1000;
unsigned long lastEmojiShowTime = 0;
const long emojiInterval = 10000;
unsigned long lastDegreeSwitch = 0;
bool fDegrees = false;
bool potato = true;
bool lemon = false;

bool danger = false;
bool lastDangerState = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(tempPin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(humidityPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    lightLevel = analogRead(lightPin);
    voltage = getVoltage(tempPin);
    temperature = (voltage - 0.5) * 100.0;
    degreesF = temperature * (9.0 / 5.0) + 32.0;
    humidityLevel = analogRead(humidityPin);

    danger = false;
    if (temperature > 30 || lightLevel < 100) {
      danger = true;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    if (currentMillis - lastDegreeSwitch > 500) {
      lastDegreeSwitch = currentMillis;
      fDegrees = !fDegrees;
    }
    if (fDegrees) {
      lcd.print(degreesF, 1);
      lcd.print(" F");
    } else {
      lcd.print(temperature, 1);
      lcd.print(" C");
    }

    lcd.setCursor(0, 1);
    lcd.print("L:");
    lcd.print(1023 - lightLevel);
    lcd.print(" H:");
    lcd.print(humidityLevel / 10);

    if (danger && !lastDangerState) {
      playAlarm();
    }

    lastDangerState = danger;
  }
}

float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814);
}

void playAlarm() {
  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, 1000, 200);
    delay(250);
  }
  noTone(buzzerPin);
}
