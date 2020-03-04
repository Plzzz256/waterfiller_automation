int ledPin = 2;
int ledPin1 = 3;

void setup()
{
  pinMode(ledPin, OUTPUT);
} 

void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  delay(2000);
  digitalWrite(ledPin1, HIGH);
}
