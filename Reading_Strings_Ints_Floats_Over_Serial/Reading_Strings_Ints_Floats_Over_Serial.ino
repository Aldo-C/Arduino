String Name;            //Declaring a string variable for name input later.
int age;                //Declaring an integer variable for age input later.
float height;           //Declaring a float variable for height input later.

void setup() {

  Serial.begin(115200);       //Turn Serial port on at 115200 baud

}

void loop() {

  Serial.println("What is your name? ");      //Prompting user for name
  while(Serial.available() == 0) {            //Waiting for user input
  }
  Name = Serial.readString();                 //Read user input as a string and assign it to Name variable

  Serial.println("How old are you? ");        //Prompting user for age
  while(Serial.available() == 0) {            //Waiting for user input
  }
  age = Serial.parseInt();                    //Read user input as an integer and assign it to age variable

  Serial.println("How tall are you in inches? ");     //Prompting user for height
  while(Serial.available() == 0) {                    //Waiting for user input
  }
  height = Serial.parseFloat();                       //Read user input as a float and assign it to the height variable
  Serial.println(" ");

  Serial.print("Hello ");
  Serial.println(Name);
  delay(1000);

  Serial.print("Your age is: ");
  Serial.println(age);
  delay(1000);

  Serial.print("You are ");
  Serial.print(height);
  Serial.println("\" tall");
  delay(1000);
  Serial.println(" ");

}
