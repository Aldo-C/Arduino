#include <Servo.h>        //Load the servo library, no ; needed to load libraries.

int pos = 0;              //Declare and initialize the pos variable

int servoPin = 9;         //The pin we will control the servo from
int servoDelay = 25;      //Delay to servo motor so it isn't over-driven

Servo myServo;            //assigns the servo libraries to the myServo object

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
  
}

void loop() {

  for(pos = 30; pos <= 160; pos += 5) {
    myServo.write(pos);        //Send servo to pos
    delay(servoDelay);         //Pause servo for 25ms
  }

  for(pos = 160; pos >= 30; pos -= 5) {
    myServo.write(pos);
    delay(servoDelay);
  }

}
