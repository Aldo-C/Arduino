const int firstLED = 5;             //First red LED
const int secondLED = 4;            //Second red LED
const int thirdLED = 3;             //Third red LED
const int lastLED = 2;              //Last LED which is green
const int calibrationLED = 13;

const int sensorPin = A0;
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
  Serial.begin(115200);

  pinMode(firstLED, OUTPUT);
  pinMode(secondLED, OUTPUT);
  pinMode(thirdLED, OUTPUT);
  pinMode(lastLED, OUTPUT);
  
  pinMode(calibrationLED, OUTPUT);
  digitalWrite(calibrationLED, HIGH);         //Turn on LED on pin 13 indicating calibration has begun

  while(millis() < 5000) {                    //5 seconds from Arduino ON, for calibration
    sensorValue = analogRead(sensorPin);      //read value from photoresistor

    if (sensorValue > sensorHigh) {           //closest sensor value to sensorHigh(0) is set to sensorHigh
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {            //closest sensor value to sensorLow(1023) is set to sensorLow
      sensorLow = sensorValue;
    }
  }

  digitalWrite(calibrationLED, LOW);          //Turn off LED on pin 13 indicating calibration has ended

}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  int brightness =
    map(sensorValue, sensorLow, sensorHigh, 1, 1000);
  Serial.println(brightness);
  delay(250);

  if (brightness > 0) {                     //If translated reading from sensor is over 0 then turn on the first red LED
    digitalWrite(firstLED, HIGH);
  }
  else {                                    //Otherwise turn off first red LED if reading goes below zero
    digitalWrite(firstLED, LOW);
  }

  if (brightness > 300) {                   //If translated reading from sensor is over 300 then turn on the second red LED
    digitalWrite(secondLED, HIGH);
  }
  else {                                    //Otherwise turn off second red LED if reading goes below 300
    digitalWrite(secondLED, LOW);
  }

  if (brightness > 500) {                   //If translated reading from sensor is over 500 then turn on the third red LED
    digitalWrite(thirdLED, HIGH);
  }
  else {                                    //Otherwise turn off third red LED if reading goes below 500
    digitalWrite(thirdLED, LOW);
  }

  if (brightness > 900) {                   //If translated reading from sensor is over 900 then turn on the green LED
    digitalWrite(lastLED, HIGH);
  }
  else {                                    //Otherwise turn off the green LED if reading goes below 900
    digitalWrite(lastLED, LOW);
  }

}
