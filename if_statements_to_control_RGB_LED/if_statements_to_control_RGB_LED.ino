int Red = 11;     //Red LED pin is 11
int Blue = 10;    //Blue LED pin is 10
int Green = 6;    //Green LED pin is 6

int brightness = 255;     //Full brightness on analog write
int off = 0;              //Turn LED off

String ColorChoice;       //Variable for user to choose color

void setup() {
  
  Serial.begin(115200);
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);

}

void loop() {

  Serial.println("Please choose a color(red, green, blue, or purple): ");
  while(Serial.available() == 0) {
  }
  ColorChoice = Serial.readString();

  if(ColorChoice == "red") {
    analogWrite(Red, brightness);
    analogWrite(Blue, off);
    analogWrite(Green, off);
  }

  if(ColorChoice == "green") {
    analogWrite(Red, off);
    analogWrite(Blue, off);
    analogWrite(Green, brightness);
  }

  if(ColorChoice == "blue") {
    analogWrite(Red, off);
    analogWrite(Blue, brightness);
    analogWrite(Green, off);
  }

  if(ColorChoice == "purple") {
    analogWrite(Red, 255);
    analogWrite(Blue, 127);
    analogWrite(Green, 0);
  }

  if(ColorChoice != "red" && ColorChoice != "green" && ColorChoice != "blue" && ColorChoice != "purple") {
    Serial.println("That is not a valid entry, please choose red, green or blue");
    Serial.println(" ");
  }

}
