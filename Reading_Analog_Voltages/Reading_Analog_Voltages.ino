int PotPin = A0;  //Assigns PotPin to pin A0 on Arduino
int readValue;    //Value we read from Vout on pot
float Voltage;    //declare our voltage variable

void setup() {

  pinMode(PotPin, INPUT);   //sets PotPin to INPUT mode
  Serial.begin(115200);     //Begin serial communications

}

void loop() {

  readValue = analogRead(PotPin);       //assign the input from PotPin to the readValue variable
  Serial.println(readValue);            //print analog read to serial monitor
  Voltage = (5.0/1023.0) * readValue;   //calculate the real world voltage
  Serial.println(Voltage);              //print actual voltage number
  delay(250);                           //delay 250ms
  Serial.println(" ");                  //print a space to make it pretty and SHIT

}
