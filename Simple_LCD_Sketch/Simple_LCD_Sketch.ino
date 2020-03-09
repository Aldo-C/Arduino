#include <LiquidCrystal.h>              //Loading LCD library

LiquidCrystal LCD(10, 9, 5, 4, 3, 2);    //Creating LCD object and telling it what pins we are hooked up to.

int Counter = 0;

String words;

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

  for(Counter = 1; Counter <= 10; Counter += 1) {   //For loop with (Begin, Condition, What to do after each iteration)

    LCD.setCursor(9, 1);      //Sets cursor to column 10, row 2
    LCD.print(" ");           //Clears extra S when the counter hits 10 and shifts " Seconds" to the right 1 column
    
    LCD.setCursor(0, 1);      //Setting cursor to 1st column and 2nd row aka bottom left corner of the display
    LCD.print(Counter);       //Print the value of the Counter variable
    LCD.print(" Seconds");    //Print units of measurement
    delay(1000);              //Delay by 1000ms because we want the counter to count in seconds
  }

  for(Counter = 10; Counter >= 0; Counter -= 1) {

    LCD.setCursor(9, 1);
    LCD.print(" ");

    LCD.setCursor(0, 1);
    LCD.print(Counter);
    LCD.print(" Seconds");
    delay(1000);
  }

}
