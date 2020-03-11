#include <AccelStepper.h>
#define dirPin 2 // Board Control Motor pin
#define motorInterfaceType 1
#define stepPin 3 // Board Control Motor pin
#define stepsPerRevolution 33
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
void setup() 
{
  // put your setup code here, to run once:
 pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  stepper.setMaxSpeed(1000);
}

void loop() 
{
  // Set the current position to 0:
  stepper.setCurrentPosition(0);
  // Run the motor forward at 200 steps/second until the motor reaches 400 steps (2 revolutions):
  while(stepper.currentPosition() != 400)
  {
    stepper.setSpeed(200);
    stepper.runSpeed();
  }
  delay(1000);
}
  
