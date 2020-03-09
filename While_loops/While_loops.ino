void setup() {
  Serial.begin(115200);
  
}

void loop() {
  int i = 2; //i is an int and it is equal to 1

  while(i <= 20){
    Serial.print("You are on #: ");
    Serial.println(i);
    delay(250);
    i += 2;
  }

  Serial.println(" ");
}
