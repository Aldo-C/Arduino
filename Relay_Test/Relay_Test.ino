int LEDPin = 13;
int RelayPin = 8;
String RelayStatus;


void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(RelayPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.print("Type 'open' or 'close' to turn the relay off or on: ");
  while(Serial.available() == 0){
  }
  RelayStatus = Serial.readString();

  Serial.print("Relay status is: ");
  Serial.print("[");                  //These are debugging lines to see how the string is being stored
  Serial.print(RelayStatus);
  Serial.println("]");                //Debugging revealed /n was being included at the end of the string

  if(RelayStatus == "close\n"){
    digitalWrite(RelayPin, HIGH);
  }
  else if(RelayStatus == "open\n"){
    digitalWrite(RelayPin, LOW);
  }
  else{
    Serial.println("I don't understand.");
  }

}
