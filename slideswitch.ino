const int switchPin = 12;
const int ledPin =  13;

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int state = digitalRead(switchPin);
  Serial.println(state);
  
  if (state == LOW || state == LOW)
  {
    digitalWrite(ledPin, HIGH);  // lülitame LED sisse
  }
  else                          
  {
    digitalWrite(ledPin, LOW);  // lülitame LED välja
  }    	
}
