const int sensorPin = 0;
const int ledPin = 12;
int lightLevel, high = 0, low = 1023; 

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  lightLevel = analogRead(sensorPin);
  manualTune();
  digitalWrite(ledPin, lightLevel);

  Serial.print(lightLevel);
  Serial.println("");          
  delay(1000);                
}

void manualTune()
{
  lightLevel = map(lightLevel, 300, 800, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}
