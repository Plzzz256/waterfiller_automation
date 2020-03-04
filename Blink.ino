#include <Servo.h>

Servo servo;
int angle = 10;
int ledPin = 2;
int ledPin1 = 3;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  servo.attach(8);
  servo.write(angle);
} 

void loop()
{
/*  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  delay(2000);
*/
   // scan from 0 to 180 degrees
  for(angle = 10; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 10; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  }
}
