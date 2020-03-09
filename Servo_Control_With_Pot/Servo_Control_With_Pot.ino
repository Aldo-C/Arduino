#include <Servo.h>        //Load the servo library, no ; needed to load libraries.

int pos = 0;              //Declare and initialize the pos variable

int servoPin = 9;         //The pin we will control the servo from
int servoDelay = 25;      //Delay to servo motor so it isn't over-driven

int PotPin = A0;          //Pin to which pot is hooked to
int potReading;           //Variable to which the pot reading will be saved.

Servo myServo;            //assigns the servo libraries to the myServo object

void setup() {
  
  Serial.begin(115200);
  myServo.attach(servoPin);
  pinMode(PotPin, INPUT);
  
}

void loop() {

  //The map() function takes a value and its minimum and maximum readings and converts them to another variables min/max
  //map(fromValue, fromMin, fromMAX, toMin, toMax)

  potReading = analogRead(PotPin);
  pos = map(potReading, 0, 1023, 30, 160);    //Read input from potientiometer and map it to outputs in the servos range
  myServo.write(pos);                         //Write pos to servo
  delay(servoDelay);

}
