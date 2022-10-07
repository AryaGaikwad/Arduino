#include <Stepper.h>
int stepsPerRevolution = 200; //chnge acc to motor
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int i;

void setup() {
  Serial.begin(9600);
}

void loop() {
  myStepper.setSpeed(100);
  myStepper.step(100);
  myStepper.step(-stepsPerRevolution);

}
