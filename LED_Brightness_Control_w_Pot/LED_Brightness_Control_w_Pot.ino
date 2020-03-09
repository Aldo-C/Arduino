int DimmableLED = 9;      //LED is hooked up to pin 9 on Arduino Board
int PotPin = A0;          //Potentiometer is hooked to pin A0
int readValue;            //Read analog value from pot
int writeValue;           //Analog value we will write to LED pin

void setup() {

  Serial.begin(9600);             //Turn on serial port at 9600 baud
  pinMode(PotPin, INPUT);           //Set pot pin to a readable pin
  pinMode(DimmableLED, OUTPUT);     //Set LED pin to a writeable pin

}

void loop() {

  readValue = analogRead(PotPin);             //Read voltage from pot and assign it to readValue variable
  writeValue = (85.0 / 341.0) * readValue;    //Setting analog value to be written to LED pin

  analogWrite(DimmableLED, writeValue);       //Writing the value from writeValue to the LED pin
  Serial.println("You are at a write value of: ");
  Serial.println(writeValue);
  Serial.println(" ");

}
