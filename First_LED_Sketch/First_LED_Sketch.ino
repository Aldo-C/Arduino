int RedLED = 13;
int GreenLED = 11;

int timeOff = 950;
int BurstOff = 50;
int timeOn = 50;
int LongDelay = 1000;

void setup() {
  // Pigolon setup goes here
  pinMode(RedLED,OUTPUT);
  pinMode(GreenLED,OUTPUT);

}

void loop() {
  // looping pigolon tricks

for (int i = 1; i <= 2; i += 1) { //Starts a for loop (Begin, Run while this is true, Do this after one iteration)
  digitalWrite(RedLED,HIGH);
  delay(timeOn);
  digitalWrite(RedLED,LOW);
  delay(BurstOff);
  digitalWrite(RedLED,HIGH);
  delay(timeOn);
  digitalWrite(RedLED,LOW);
  delay(LongDelay);
}

for (int i = 1; i <= 2; i += 1) {
  digitalWrite(GreenLED,HIGH);
  delay(timeOn);
  digitalWrite(GreenLED,LOW);
  delay(BurstOff);
  digitalWrite(GreenLED,HIGH);
  delay(timeOn);
  digitalWrite(GreenLED,LOW);
  delay(LongDelay);
}

}
