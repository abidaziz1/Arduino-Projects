#include <Stepper.h>

// Define the number of steps per revolution for the motor (28BYJ-48)
#define STEPS 2048

// Create an instance of the Stepper class with the steps and the pins connected to the motor driver
Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  // Set the speed of the motor (in RPM)
 // stepper.setSpeed(10); // Adjust the speed as needed
}

void loop() {
  // Move the motor forward one revolution
  stepper.setSpeed(6);
  stepper.step(STEPS);
  delay(1000); // Wait for one second

  // Move the motor backward one revolution
  stepper.step(-STEPS);
  delay(1000); // Wait for one second

  stepper.setSpeed(12);
  stepper.step(4096);
  delay(1000); // Wait for one second

  // Move the motor backward one revolution
  stepper.step(-4096);
  delay(1000); // Wait for one second

  // Move the motor forward one revolution
  stepper.setSpeed(18);
  stepper.step(STEPS);
  delay(1000); // Wait for one second

  // Move the motor backward one revolution
  stepper.step(-STEPS);
  delay(1000); // Wait for one second

}
