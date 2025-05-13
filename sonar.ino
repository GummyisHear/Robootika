#define ECHO_PIN 10
#define TRIG_PIN 11

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Serial.begin(960);
}

void loop() {
  Serial.println(measure()); 
}

int measure()
{
  digitalWrite(TRIG_PIN,HIGH);
  digitalWrite(TRIG_PIN,LOW);
  int distance = pulseIn(ECHO_PIN, HIGH)/50;
  return constrain(distance,1,300);
}
