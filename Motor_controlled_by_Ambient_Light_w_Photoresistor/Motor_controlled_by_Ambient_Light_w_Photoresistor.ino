int photoRes = A0;      // Assign pin for photoresistor
int powerPin = 3;       // Assign pin for power to rotor
int calibrationLED = 13;

float lightValue;       // Variable for value read from photoresistor
float voltageValue;     // Variable for value being sent to powerPin
int lowerBound = 200;     // Set lower bound for incoming values from photoresistor
int upperBound = 1023;   // Set upper bound for incoming values from photoresistor


void setup() {
  Serial.begin(9600);     // Enable serial monitor
  pinMode(photoRes, INPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(calibrationLED, OUTPUT);

  digitalWrite(calibrationLED, HIGH);         // Turn on on-board LED to indicate calibration

  while(millis() < 5000) {                    // During the first 5 seconds of bootup
    lightValue = analogRead(photoRes);        // Read value from photoresistor and save it to lightValue

    if (lightValue < lowerBound) {            // If current low light ambient value is less than intial, then reset to current
      lowerBound = lightValue;
    }
    if (lightValue < upperBound || lightValue > upperBound) {            // if current max light ambient value is greater than or less than initial, then reset to current
      upperBound = lightValue;
    }
  }

  digitalWrite(calibrationLED, LOW);          // Turn off on-board LED to indicate calibration has ended

}

void loop() {
  lightValue = analogRead(photoRes);    // Read value from photoresistor
  Serial.print("The current reading from the photoresistor is: ");
  Serial.println(lightValue);
  voltageValue =
    map(lightValue, lowerBound, upperBound, 0, 255);        // Map the reading from lightValue which should have a value between lowerBound and upperBound to values that can be written
                                                            // by the analogWrite command 0 to 255
  Serial.print("The value being sent to the rotor is: ");
  Serial.println(voltageValue);

  // analogWrite(powerPin, voltageValue);

  delay(500);

}
