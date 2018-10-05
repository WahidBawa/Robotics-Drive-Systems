#include <Servo.h> // This imports the header file for servo functions
int leftAdd, rightAdd; // intializes these variables
Servo leftServo, rightServo; // Creates and initializes the servo objects
void setup() {
  rightServo.attach(A4); // rightServo inputs/outputs will come from the specified port
  leftServo.attach(A3); // leftServo inputs/outputs will come from the specified port
  rightServo.write(90); // Writes the stop states to the 360 servos
  leftServo.write(90); // Writes the stop states to the 360 servos
}

void loop() {
  int joyX = analogRead(A1); // Reads input from the joystick
  int joyY = analogRead(A2); // Reads the input from the joystick
  int mapY = map(joyY, 0, 1023, 0, 180); // Converts the inputs from the joystick inputs to be written to the servos
  int mapX = map(joyX, 0, 1023, 0, 180); // Converts the inputs from the joystick inputs to be written to the servos
  leftAdd = mapX - 90; // This will take the mapped value minus the center point of the 360 servos
  rightAdd = mapX - 90; // This will take the mapped value minus the center point of the 360 servos

  int rightServoVal = mapY + rightAdd; // This will set the outputs for the servo
  int leftServoVal = 180 - mapY + leftAdd; // This will set the outputs of the servo
  
  rightServo.write(rightServoVal); // Writes the values to the servo
  leftServo.write(leftServoVal); // Writes the values to the servo

}
