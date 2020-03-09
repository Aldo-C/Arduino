int RedLED = 9;                // Pin assignment for Red LED (int indicates variable is an integer)
int GreenLED = 10;             // Pin assignment for green LED
int DelayTimeLED = 500;        // Time delay between blinks in milliseconds
int numRedBlinks = 5;          // Number of times the red LED should blink
int numGreenBlinks;            // Number of times the green LED should blink, left empty for user input
int RedLEDBrightness;          // blank integer variable to set brightness of red variable
String wm1 = "Welcome to ";    // Declare a string variable
String wm2 = "my program!";
String wm3 = "I hope you ";
String wm4 = "enjoy it!";
String wm5;                   // Declare an empty string variable

void setup() {
  Serial.begin(9600);               // Enable serial monitor output
  Serial.println(wm1 + wm2);        // Difference methods of concatenation (addings strings together)
  Serial.println(wm5 = wm3 + wm4);  // another concatenation method
  pinMode(RedLED, OUTPUT);          // Sets the assigned pin mode (Pin #, INPUT/OUTPUT)
  pinMode(GreenLED, OUTPUT);        // See above

  Serial.println("How many times would you like the green LED to blink?");  // Create prompt leading to user input
  while(Serial.available() == 0) {    // Sets a loop that will continute until condition is met, here waiting for input "= 1"
  }
  numGreenBlinks = Serial.parseInt(); // Read user input and set variable equal to input
  Serial.print("The green LED will blink ");
  Serial.print(numGreenBlinks);
  Serial.println(" times.");
}

void loop() {
  Serial.println("How bright would you like the red LED to be (scale from 0-255)?");
  while(Serial.available() == 0) {
  }
  RedLEDBrightness = Serial.parseInt();
  
  for(int i=1; i <= numRedBlinks; i++) {      // set variable, condition for loop to continue, add 1 to variable (Can also use i += 1)
    Serial.print("Number of red blinks: ");   // print a line that says "Number of red blinks: " with no break
    Serial.println(i);                        // print the value of i with a line break
    analogWrite(RedLED, RedLEDBrightness);               // With analogWrite the voltage output is controllable
    delay(DelayTimeLED);
    analogWrite(RedLED, 0);                // Telling the pin what type of output we want, in this case "off"
    delay(DelayTimeLED);
  }

  int i = 1;                     // Create a local variable for use with while loop
  while(i <= numGreenBlinks) {   // Use a while loop instead of a for loop for the same effect
    Serial.print("Number of green blinks: ");
    Serial.println(i);
    digitalWrite(GreenLED, HIGH);   // With digitalWrite the voltage output is set to max or off only
    delay(DelayTimeLED);
    digitalWrite(GreenLED,LOW);
    delay(DelayTimeLED);
    i += 1;                     // Increase the value of i by 1
  }
  
}
