const int calibrationLED = 13;              //LED to turn on for calibration purposes
const int laserEmitter = 5;                 //"Laser" pin
const int alarmBuzzer = 9;                  //Piezzo buzzer pin

const int laserReceiver = A0;               //"Laser" receiving photo resistor
int sensorValue;                            //Blank variable for use later
int sensorLow = 1023;                       //For setting low point input for photo resistor
int sensorHigh = 0;                         //For setting high point input for photo resistor

void setup() {
  Serial.begin(115200);                           //Turn on serial communications for debugging

  pinMode(laserEmitter, OUTPUT);                  //Set "laser" pin to output
  pinMode(calibrationLED, OUTPUT);                //Set calibration pin to output
  pinMode(alarmBuzzer, OUTPUT);                   //Set piezzo buzzer pin to output

  digitalWrite(calibrationLED, HIGH);             //Turn on the calibration LED to indicate calibration period has begun

  while(millis() < 5000) {                        //Begin while loop to last the duration of 5 seconds since Arduino ON
    sensorValue = analogRead(laserReceiver);      //Read value from the "laser" receiver and assign it to sensorValue

    digitalWrite(laserEmitter, HIGH);             //Turn on "laser" for a high value reading
    delay(1000);
    digitalWrite(laserEmitter, LOW);              //Turn off "laser" for a low value reading
    
    if (sensorValue > sensorHigh) {               //Takes the highest sensor value read and assigns it to sensorHigh
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {                //Takes the lowest sensor value read and assigns it to sensorLow
      sensorLow = sensorValue;
    }

    //Debugging prints
    //Serial.print("L: ");
    //Serial.print(sensorLow);
    //Serial.print("  H: ");
    //Serial.println(sensorHigh);
    
  }

  digitalWrite(calibrationLED, LOW);              //Turn off the calibration LED to indicate end of calibration period

}

void loop() {
  digitalWrite(laserEmitter, HIGH);                       //Turn on the "laser" for some shenanigans
  sensorValue = analogRead(laserReceiver);                //Assign reading from photo resistor to sensorValue

  Serial.print("Sensor value: ");
  Serial.print(sensorValue);
  Serial.print("  L: ");
  Serial.print(sensorLow);
  Serial.print("  H: ");
  Serial.println(sensorHigh);

  int detectionValue =                                    //Map the values from sensorLow & sensorHigh to values between 1 and 100
    map(sensorValue, sensorLow, sensorHigh, 0, 100);      //then take the current reading of sensorValue and assign it a mapped
  Serial.print("Mapped sensor value: ");                  //value between 1 and 100 and then assign that value to detectionValue
  Serial.println(detectionValue);

  if (detectionValue < 100) {                             //If the detection value drops below the maximum light threshold of 100
    tone(alarmBuzzer, 2000);                              //then sound the piezzo buzzer at a frequency of 2khz aka FU-KYOO
  }
  if (detectionValue == 100) {                            //If the detection value is at the maximum light threshold of 100
    noTone(alarmBuzzer);                                  //then turn off the piezzo buzzer at its assigned pin
  }

}
