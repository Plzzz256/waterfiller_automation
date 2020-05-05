#define dirPin 2 // Board Control Motor pin
#define stepPin 3 // Board Control Motor pin
#define inputPin 4 // Sensor 
#define stepsPerRevolution 33
#define relay 6
int val = 0; // variable

void setup()
{
  // Declare pins as output:
  pinMode(relay, OUTPUT);
  digitalWrite(relay,HIGH); // HIGH = Close || LOW(0) = OPEN 
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(inputPin, INPUT);

  Serial.begin(9600);
}

void loop()
{

  val = digitalRead(inputPin); // read input value
  if (val == LOW)  // value 0 = found
  {
    Serial.print("FOUND\n");
    digitalWrite(dirPin, HIGH);
    // Spin the stepper motor 1 revolution slowly
    for (int i = 0; i < stepsPerRevolution; i++)
    {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
    delay(5000);

    digitalWrite(relay, LOW);
    delay(21000); //wait 21 seconds = 21000
    digitalWrite(relay, HIGH);
  }

  else
  {
    Serial.print("NOT FOUND\n");
    for (int i = 0; i < stepsPerRevolution; i++)
    {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
    delay(5000);
  }
}
