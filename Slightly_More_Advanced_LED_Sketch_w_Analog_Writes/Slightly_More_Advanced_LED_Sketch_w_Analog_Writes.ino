int RedLED = 9;
int GreenLED = 11;

int timeOff = 950;
int BurstOff = 50;
int timeOn = 50;
int LongDelay = 1000;
int RedBlinks = 2;
int GreenBlinks = 2;

String RedLight = "The Red LED is blinking!";
String GreenLight = "The Green LED is blinking!";

int RedBrightness;
int GreenBrightness;

void setup() {
  // Pigolon tits setup goes here
  Serial.begin(115200);
  pinMode(RedLED,OUTPUT);
  pinMode(GreenLED,OUTPUT);

  Serial.println("Choose a brightness for the red LED between 0-255: ");
  while(Serial.available()==0){ }
  RedBrightness = Serial.parseInt();

  Serial.println("Choose a brightness for the Green LED between 0-255: ");
  while(Serial.available()==0){ }
  GreenBrightness = Serial.parseInt();

}

void loop() {
  // looping titty tricks
  Serial.println(RedLight);

  for (int i = 1; i <= RedBlinks; i += 1) { //Starts a for loop (Begin, Run while this is true, Do this after one iteration)
    Serial.print("Blink #: ");
    Serial.println(i);
    analogWrite(RedLED, RedBrightness);
    delay(timeOn);
    analogWrite(RedLED, 0);
    delay(BurstOff);
    analogWrite(RedLED, RedBrightness);
    delay(timeOn);
    analogWrite(RedLED,0);
    delay(LongDelay);
  }

  Serial.println(" ");
  Serial.println(GreenLight);

  for (int i = 1; i <= GreenBlinks; i += 1) {
    Serial.print("Blink #: ");
    Serial.println(i);
    analogWrite(GreenLED, GreenBrightness);
    delay(timeOn);
    analogWrite(GreenLED, 0);
    delay(BurstOff);
    analogWrite(GreenLED, GreenBrightness);
    delay(timeOn);
    analogWrite(GreenLED, 0);
    delay(LongDelay);
  }
  
  Serial.println(" ");

}
