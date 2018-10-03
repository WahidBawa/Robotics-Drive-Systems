#include <Servo.h>
int rightAdd = 0;
int leftAdd = 0;
Servo leftServo;
Servo rightServo;
void setup() {
  rightServo.attach(A4);
  leftServo.attach(A3);
  rightServo.write(90);
  leftServo.write(90);
  Serial.begin(9600);
}

void loop() {
  int joyX = analogRead(A1);
  int joyY = analogRead(A2);
  Serial.print("joyX: ");
  Serial.print(joyX);
  Serial.print("\n");
  Serial.print("joyY: ");
  Serial.print(joyY);
  int mapY = map(joyY, 0, 1023, 0, 180);
  int mapX = map(joyX, 0, 1023, 0, 180);
//  int mapY = joyY << 3;
//  int mapX = joyX << 3;
//  Serial.print("mapX: ");
//  Serial.print(mapX);
//  Serial.print("\n");
//  Serial.print("mapY: ");
//  Serial.print(mapY);
  leftAdd = mapX - 90;
  rightAdd = mapX - 90;

  int rightServoVal = mapY + rightAdd;
  int leftServoVal = 90 + 90- mapY + leftAdd;
  
  rightServo.write(rightServoVal);
  leftServo.write(leftServoVal);

}
