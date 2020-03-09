int Red = 11;             //Red is on pin 11
int Blue = 10;           //Green is on pin 10
int Green = 6;             //Blue is on pin 6

int RedBrightness = 127;        //Brightness range from 0-255 (Because analog write is 0-255 and analog read is 0-1023)
int BlueBrightness = 127;       //Brightness range from 0-255 (Because analog write is 0-255 and analog read is 0-1023)
int GreenBrightness = 127;      //Brightness range from 0-255 (Because analog write is 0-255 and analog read is 0-1023)
int off = 0;                    //Turn off LED

int ColorTime;                  //Variable for time each LED color will be on in milliseconds
int TimesPerColor;              //How many times each color will blink before moving to the next color

void setup() {

  Serial.begin(115200);
  
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  Serial.println("How long should each color be up? ");
  while(Serial.available() == 0) {
  }
  ColorTime = Serial.parseInt();

  Serial.println("How many blinks per color? ");
  while(Serial.available() == 0) {
  }
  TimesPerColor = Serial.parseInt();

}

void loop() {

  for(int i = 1; i <= TimesPerColor; i += 1) {
    analogWrite(Red, RedBrightness);
    delay(ColorTime);
    analogWrite(Red, off);
    delay(ColorTime);
  }

  for(int i = 1; i <= TimesPerColor; i += 1) {
    analogWrite(Green, GreenBrightness);
    delay(ColorTime);
    analogWrite(Green, off);
    delay(ColorTime);
  }

  for(int i = 1; i <= TimesPerColor; i += 1) {
    analogWrite(Blue, BlueBrightness);
    delay(ColorTime);
    analogWrite(Blue, off);
    delay(ColorTime);
  }
  
}
