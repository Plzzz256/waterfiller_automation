// Define stepper motor connections and steps per revolution:
#define dirPin 2 // Board Control Motor pin
#define stepPin 3 // Board Control Motor pin
#define inputPin 4 // Sensor 
#define stepsPerRevolution 33
int relay_1 = 5;
int val = 0; // variable
int found = 0; // variable
int not_found = 0; // variable


void setup() 
{
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(relay_1, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  val = digitalRead(inputPin); // read input value
  if (val == LOW)  // value 0 = found 
   {
    found = found + 1;
    Serial.print("1 FOUND\n");
    digitalWrite(dirPin, HIGH);
    // Spin the stepper motor 1 revolution slowly:
    for (int i = 0; i < stepsPerRevolution; i++) 
    {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
    delay(5000);
    digitalWrite(relay_1, 0);
    delay(5000);
    digitalWrite(relay_1, 1);
   }
  else
  {
  not_found = not_found + 1;
  Serial.print("0 NOT FOUND\n");
  }
}
