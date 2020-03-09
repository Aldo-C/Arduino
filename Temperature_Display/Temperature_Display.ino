#include <LiquidCrystal.h>              //Loading LCD library

LiquidCrystal LCD(10, 9, 5, 4, 3, 2);    //Creating LCD object and telling it what pins we are hooked up to.

int Counter = 0;

const int sensorPin = A0;
int sensorVal;
float voltage;
float Celsius;
float Fahrenheit;

void setup() {

  Serial.begin(115200);

  //Use this to ask user for intial input to show on LCD
  //Serial.println("What would you like to show on the LCD? ");
  //while(Serial.available() == 0) {
  //}
  //words = Serial.readString();

  LCD.begin(16, 2);         //Tells Arduino our LCD has 16 columns and 2 rows.
  LCD.setCursor(0, 0);      //Set LCD cursor to 1st column and 1st row aka top left corner of the display
  LCD.print("Temperature is: ");  //Prints this where we set the cursor on the LCD

}

void loop() {

  analogRead(sensorPin);
  delay(10);
  sensorVal = analogRead(sensorPin);
  delay(10);
  Serial.print("Sensor value is: ");
  Serial.println(sensorVal);

  voltage = (sensorVal/1023.0) * 5.0;
  Serial.print("Volts: ");
  Serial.println(voltage);

  Celsius = (voltage * 100) - 50;
  Serial.print(Celsius);
  Serial.println(" C / ");

  Fahrenheit = (Celsius * 9.0/5.0) + 32;
  Serial.print(Fahrenheit);
  Serial.println(" F");
  delay(1000);

  //LCD.setCursor(9, 1);      //Sets cursor to column 10, row 2
  //LCD.print(" ");           //Clears extra S when the counter hits 10 and shifts " Seconds" to the right 1 column
    
  LCD.setCursor(0, 1);      //Setting cursor to 1st column and 2nd row aka bottom left corner of the display
  LCD.print(Celsius);
  LCD.print((char)223);     //(char)223 prints the degree symbol °
  LCD.print("C");

  LCD.print("/");
  LCD.print(Fahrenheit);
  LCD.print((char)223);
  LCD.print("F");

}
