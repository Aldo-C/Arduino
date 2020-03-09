int Red = 11;             //Red is on pin 11
int Blue = 10;           //Green is on pin 10
int Green = 6;             //Blue is on pin 6

int RedBrightness = 127;        //Brightness range from 0-255 (Because analog write is 0-255 and analog read is 0-1023)
int BlueBrightness = 0;         //Brightness range from 0-255 (Because analog write is 0-255 and analog read is 0-1023)
int GreenBrightness = 0;        //Brightness range from 0-255 (Because analog write is 0-255 and analog read is 0-1023)

int ColorTime;                  //Variable for time each LED color will be on

void setup() {

  Serial.begin(115200);
  
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

}

void loop() {

  analogWrite(Red, RedBrightness);
  analogWrite(Green, GreenBrightness);
  analogWrite(Blue, BlueBrightness);

}
