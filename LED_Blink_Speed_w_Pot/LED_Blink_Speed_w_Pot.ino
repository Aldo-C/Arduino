int BlinkableLED = 9;         //LED is hooked up to pin 9 on Arduino Board
int PotPin = A0;              //Potentiometer is hooked up to pin A0 on Arduino Board
int readValue;                //Variable to which analog value from pot will be stored
int writeValue;               //Variable to which analog write value to LED will be stored

void setup() {

  Serial.begin(115200);                   //Turn on serial port at 115200 baud
  pinMode(PotPin, INPUT);                 //Set pot pin to be a readable pin
  pinMode(BlinkableLED, OUTPUT);          //Set LED pin to be a writeable pin

}

void loop() {

  readValue = analogRead(PotPin);                 //Read voltage as analog input from pot and assign it to readValue
  writeValue = (1000.0 / 1023.0) * readValue;     //Take readValue and convert it to a millisecond blink speed

  Serial.print("Current analog read value is: ");   //Print current analog value being input from potentiometer
  Serial.println(readValue);                        //Print current analog value being input from potentiometer
  Serial.print("Blink delay in ms: ");              //Print writeValue in milliseconds after conversion
  Serial.println(writeValue);                       //Print writeValue in milliseconds after conversion
  Serial.println(" ");                              //Tits

  digitalWrite(BlinkableLED, HIGH);         //Turn on LED
  delay(writeValue);                        //Use writeValue for millisecond delay between on and off
  digitalWrite(BlinkableLED, LOW);          //Turn off LED
  delay(writeValue);                        //Use writeValue for millisecond delay between on and off

}
