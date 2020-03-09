int potPin = A0;             // Assign potentiometer pin
float potReading;            // Create variable for potentiometer reading
int motorPin = 3;            // Assign pin for motor control (NOTE: must use PWM pin)
float currentVoltage;        // Set global variable for max voltage
float rotorPinOutput;        // Set gloabal variable rotorPinOutput for writing to motorPin and controlling rotor speed


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);    // Set motor pin to output
  pinMode(potPin, INPUT);       // Assign pot pin to read incoming data

}

void loop() {
  // put your main code here, to run repeatedly:
  potReading = analogRead(potPin);                  // Read input value from potentiometer and store it in potReading variable
  Serial.print("Potentiometer reading is: ");
  Serial.println(potReading);                       // Print potReading value for debugging purposes.
  Serial.println("");
  rotorPinOutput = ( 255. / 1023. ) * potReading;   // Map potReading to a value that can be used with digitalWrite
  Serial.print("Output to rotor pin is: ");
  Serial.println(rotorPinOutput);
  Serial.println("");
  currentVoltage = ( 9. / 255. ) * rotorPinOutput;  // Map rotorPinOutput to a real voltage value
  Serial.print("The output voltage to the rotor is: ");
  Serial.println(currentVoltage);
  Serial.println("");
  analogWrite(motorPin, rotorPinOutput);           // Writes the output value (0-255) to the rotor pin

  //delay(500);
}
