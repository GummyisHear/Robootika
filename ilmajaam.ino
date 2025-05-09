#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A1;
const int lightPin = A0;

float temperature;
float voltage;
float degreesF;
int lightLevel;

unsigned long previousMillis = 0;
const long interval = 1000;
unsigned long emojiMillis = 0;
const long emojiInterval = 10000;
unsigned long lastEmojiShowTime = 0;
unsigned long lastDegreeSwitch = 0;
bool fDegrees = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(tempPin, INPUT);
  pinMode(lightPin, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    lightLevel = analogRead(lightPin);
    voltage = getVoltage(tempPin);
	temperature = (voltage - 0.5) * 100.0;
    degreesF = temperature * (9.0/5.0) + 32.0;

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
    }
    else {
      lcd.print(temperature, 1);
      lcd.print(" C");
    }

    lcd.setCursor(0, 1);
    lcd.print("Light: ");
    lcd.print(lightLevel);
    lcd.print(" lx");
  }

  if (currentMillis - lastEmojiShowTime >= emojiInterval) {
    lastEmojiShowTime = currentMillis;

    lcd.clear();
    lcd.setCursor(6, 0);
    if (temperature > 25) {
      lcd.print(":)");
    } else {
      lcd.print(":(");
    }

    delay(1000);
  }
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}
