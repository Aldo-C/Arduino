int GreenLEDPin = 10;         //Assign pin to Green LED
int RedLEDPin = 9;            //Assign pin to Red LED
String colorChoice;           //Create an empty variable for color choice assignment
                              //NOTE: If colorChoice string placed in loop portion then the digitalWrite(..., LOW)
                              //      would not be needed, because the variable would be emptied every loop.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("What color would you like the son of a bitch to be (red, green, or both; case sensitive)?");    //Prompt user for color choice
  while(Serial.available() == 0) {            // wait for user input
    
  }

  colorChoice = Serial.readString();        // Assign user input to colorChoice variable

  if(colorChoice == "red") {
    digitalWrite(RedLEDPin, HIGH);
    digitalWrite(GreenLEDPin, LOW);
  }

  if(colorChoice == "green") {
    digitalWrite(GreenLEDPin, HIGH);
    digitalWrite(RedLEDPin, LOW);
  }

  if(colorChoice == "both") {
    digitalWrite(GreenLEDPin, HIGH);
    digitalWrite(RedLEDPin, HIGH);
  }

  if(colorChoice != "red" && colorChoice != "green" && colorChoice != "both") {
    Serial.println("Read the instructions and retry.");
  }
  

}
