const int button1Pin = 12;  	//viik kunu on ühebdatud nupp1
const int button2Pin = 11; 	//viik kuhu on ühendatud nupp2
const int ledPin =  13;

void setup()
{
  pinMode(button1Pin, INPUT); //algväärtuse nupu viigu sisendiks
  pinMode(button2Pin, INPUT); //algväärtuse nupu viigu sisendiks
  pinMode(ledPin, OUTPUT);   //algväärtuse LED viigu väljundiks
}

void loop()
{
  int button1State, button2State;  //nupu oleku muutujad
  button1State = digitalRead(button1Pin);// salvestame muutujasse nupu hetke väärtuse(HIGH või LOW)
  button2State = digitalRead(button2Pin);
  
  if (button1State == LOW || button2State == LOW)
  {
    digitalWrite(ledPin, HIGH);  // lülitame LED sisse
  }
  else                          
  {
    digitalWrite(ledPin, LOW);  // lülitame LED välja
  }    	
}
