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

  Serial.println("What position would you like to set the servo to? ");
  while(Serial.available() == 0) {
  }
  pos = Serial.parseInt();        //Read user input

  myServo.write(pos);             //Write pos to servo
  delay(servoDelay);

}
