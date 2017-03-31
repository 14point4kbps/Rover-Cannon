#define beam 8 //Digital signal pin # from opto-isolator

void setup() 
{
  Serial.begin(9600);
  pinMode(beam, INPUT); //Read signal from headlight 
  for(int bar = 4; bar <8; bar++)
  {
  pinMode(bar, OUTPUT); //Open digital pin 4-7 for output (barrel triggers)
  }
}

void loop() 
{
  for(int bar = 4; bar <8; bar++) //"bar" is barrel 1-4 on digital pins 4-7
  {
    while(digitalRead(beam)==1){ //do nothing while headlights are off (digital pin 8 signal)
      delay(100);}
    while(digitalRead(beam)==0){ //if headlights are on, fire next barrel on next digital pin
      digitalWrite(bar, HIGH); //trigger ignitor on bar digital pin "bar".
      delay(3500); //delay 3.5 seconds to reach high temp
      digitalWrite(bar, LOW); //turn off ignitor on digital pin "bar"
    }
   digitalWrite(bar, LOW);
  }
}
