int motorPin = 3;            // Assign pin for motor control (NOTE: must use PWM pin)
float maxVoltage = 255;      // Set global variable for max voltage
float voltageValue;          // Set gloabal variable voltageValue


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);    // Set motor pin to output

}

void loop() {
  // put your main code here, to run repeatedly:
  for(float i=1.; i <= maxVoltage; i++) {
    Serial.print("The current voltage value is: ");
    voltageValue = i * (9./255.);           // Gives value back in terms of 9V battery
    Serial.println(voltageValue);
    Serial.println(i);
    Serial.println("");
    // analogWrite(motorPin, i);
    delay(50);
  }
}
