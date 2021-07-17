#include <Servo.h>
#define SERVO_PIN 2
#define BTN_PLUS_PIN 3
#define BTN_MINUS_PIN 4
#define PLUS_LIMIT 106
#define MINUS_LIMIT 86
#define NULL_POSITION 96

Servo spinservo;  
int iCurPos = NULL_POSITION;

void setup() {
  //Serial.begin(9600);
  pinMode(BTN_PLUS_PIN, INPUT_PULLUP);
  pinMode(BTN_MINUS_PIN, INPUT_PULLUP);
  spinservo.attach(SERVO_PIN);
  spinservo.write(NULL_POSITION);
  delay(1000);
}
void loop() {
  if (digitalRead(BTN_PLUS_PIN) && iCurPos<PLUS_LIMIT) iCurPos += 1;
  if (digitalRead(BTN_MINUS_PIN) && iCurPos>MINUS_LIMIT) iCurPos -= 1;
  spinservo.write(iCurPos);
  //Serial.println(iCurPos);
  delay(200);
}
