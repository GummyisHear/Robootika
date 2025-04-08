const int RED_PIN = 11;
 
const int GREEN_PIN = 9;
 
const int BLUE_PIN = 10;
 
int DISPLAY_TIME = 100;  // värvimuutuse kiirus
 
void setup()
 
{
 
  pinMode(RED_PIN, OUTPUT);
 
  pinMode(GREEN_PIN, OUTPUT);
 
  pinMode(BLUE_PIN, OUTPUT);
 
}
 
void loop()
 
{
 
mainColors();
 
showSpectrum();
 
}
 
void mainColors()
 
{
 
// Kõik LEDid on välja lülitatud
 
  digitalWrite(RED_PIN, LOW);
 
  digitalWrite(GREEN_PIN, LOW);
 
  digitalWrite(BLUE_PIN, LOW);
 
 delay(1000);
 
//Põleb punane
 
  digitalWrite(RED_PIN, HIGH);
 
  digitalWrite(GREEN_PIN, LOW);
 
  digitalWrite(BLUE_PIN, LOW);
 
  delay(1000);
 
// Põleb roheline
 
  digitalWrite(RED_PIN, LOW);
 
  digitalWrite(GREEN_PIN, HIGH);
 
  digitalWrite(BLUE_PIN, LOW);
 
  delay(1000);
 
// Sinine on sisse lülitatud
 
  digitalWrite(RED_PIN, LOW);
 
  digitalWrite(GREEN_PIN, LOW);
 
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(1000);
 
// Kollane.
 
  digitalWrite(RED_PIN, HIGH);
 
  digitalWrite(GREEN_PIN, HIGH);
 
  digitalWrite(BLUE_PIN, LOW);
 
  delay(1000);
 
// Lilla
 
  digitalWrite(RED_PIN, LOW);
 
  digitalWrite(GREEN_PIN, HIGH);
 
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(1000);
 
//Roosa
 
  digitalWrite(RED_PIN, HIGH);
 
  digitalWrite(GREEN_PIN, LOW);
 
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(1000);
 
//Valge ehk kõik on sisse lülitatud
 
  digitalWrite(RED_PIN, HIGH);
 
  digitalWrite(GREEN_PIN, HIGH);
 
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(1000);
 
}
 
// Vikerkaar. 
 
void showSpectrum()
 
{
 
  int x;
 
  for (x = 0; x < 768; x++)
 
  {
 
    showRGB(x);  // 
 
    delay(10);   // paus 0,001 sek
 
  }
 
}
 
// ShowRGB()  põhivärvid: 
 
// 0 = punane 
 
// 255 = roheline
 
// 511 = sinine
 
// 767 = jälle punane 
 
void showRGB(int color)
 
{
 
  int redIntensity;
 
  int greenIntensity;
 
  int blueIntensity;
 
  if (color <= 255)                
 
  {
 
    redIntensity = 255 - color;    // lülitakse välja punane
 
    greenIntensity = color;        // lülitakse sisse roheline
 
    blueIntensity = 0;             // sinine on välja lülitatud
 
  }
 
  else if (color <= 511)          
 
  {
 
    redIntensity = 0;                     // punane on välja lülitatud
 
    greenIntensity = 255 - (color - 256); 
 
    blueIntensity = (color - 256);        
 
  }
 
  else if (color >= 512)             
 
  {
 
    redIntensity = (color - 512);        
 
    greenIntensity = 0;                  
 
    blueIntensity = 255 - (color - 512);  
 
  }
 
  analogWrite(RED_PIN, redIntensity); // punase LED´i sujuv ümberlülitamine
 
  analogWrite(BLUE_PIN, blueIntensity);
 
  analogWrite(GREEN_PIN, greenIntensity);
 
}
