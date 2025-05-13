#define ECHO_PIN 10
#define TRIG_PIN 11
int motorPin1=12;
int distance=1;
int LedPin=13;
int duration;
const int buzzerPin = 2;

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(motorPin1,OUTPUT);
  pinMode(LedPin,OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN,LOW);
  delay(200);
  digitalWrite(TRIG_PIN,HIGH);
  delay(200);
  digitalWrite(TRIG_PIN,LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance=duration/58;
  Serial.println(distance);
  if (distance>50)
  {
      analogWrite(motorPin1,100);
      digitalWrite(LedPin,0);
    noTone(buzzerPin);     
      delay(1000);}  
  else
  {
    analogWrite(motorPin1,0);
      digitalWrite(LedPin,250);
       tone(buzzerPin, 1000);
  }
}
