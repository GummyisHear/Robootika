const int red1 = 13;
const int blue1 = 12;
const int green1 = 11;

const int red2 = 10;
const int blue2 = 9;
const int green2 = 8;

const int red3 = 7;
const int blue3 = 6;
const int green3 = 5;

const int sensorPin = 0;

void setup()
{
  pinMode(red1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(green1, OUTPUT);
  
  pinMode(red2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(green2, OUTPUT);
  
  pinMode(red3, OUTPUT);
  pinMode(blue3, OUTPUT);
  pinMode(green3, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int lightLevel = analogRead(sensorPin);
  analogWrite(red1, lightLevel);

  Serial.println(lightLevel);
}
