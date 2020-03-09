int RedLED = 8;
int GreenLED = 11;

int timeOff = 950;
int BurstOff = 50;
int timeOn = 50;
int LongDelay = 1000;
int RedBlinks;
int GreenBlinks;

String RedLight = "The Red LED is blinking!";
String GreenLight = "The Green LED is blinking!";

void setup() {
  // Pigolon tits setup goes here
  Serial.begin(9600);
  pinMode(RedLED,OUTPUT);
  pinMode(GreenLED,OUTPUT);

  Serial.println("How many times do you want the red LED to blink? ");
  while(Serial.available()==0){ }
  RedBlinks = Serial.parseInt();

  Serial.println("How many times do you want the green LED to blink? ");
  while(Serial.available()==0){ }
  GreenBlinks = Serial.parseInt();

}

void loop() {
  // looping titty tricks
Serial.println(RedLight);

for (int i = 1; i <= RedBlinks; i += 1) { //Starts a for loop (Begin, Run while this is true, Do this after one iteration)
  Serial.print("Blink #: ");
  Serial.println(i);
  digitalWrite(RedLED,HIGH);
  delay(timeOn);
  digitalWrite(RedLED,LOW);
  delay(BurstOff);
  digitalWrite(RedLED,HIGH);
  delay(timeOn);
  digitalWrite(RedLED,LOW);
  delay(LongDelay);
}

Serial.println(" ");
Serial.println(GreenLight);

for (int i = 1; i <= GreenBlinks; i += 1) {
  Serial.print("Blink #: ");
  Serial.println(i);
  digitalWrite(GreenLED,HIGH);
  delay(timeOn);
  digitalWrite(GreenLED,LOW);
  delay(BurstOff);
  digitalWrite(GreenLED,HIGH);
  delay(timeOn);
  digitalWrite(GreenLED,LOW);
  delay(LongDelay);
}
Serial.println(" ");

}
