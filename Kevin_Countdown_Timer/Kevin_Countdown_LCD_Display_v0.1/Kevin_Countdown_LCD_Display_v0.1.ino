#include <LiquidCrystal.h>
#include <Time.h>
#include <TimeLib.h>

LiquidCrystal LCD(10, 9, 5, 4, 3, 2);   //Creating the LiquidCrystal object and named it LCD, then assigned pins

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

// !!!!!!!! If power goes out adjust the time and date here!!
setTime(15,36,50,23,11,2016); //Sets time in a hr, min, sec, day, month, year format

LCD.begin(16, 2); //Amount of columns(16) and rows(2)
LCD.setCursor(0, 0); //Set LCD write cursor to top left of LCD
LCD.print("Kevin Returns In"); //Prints first line

}

void loop() {
  //In case scrolling is needed:
//  for (int posCounter = 0; posCounter < 4; posCounter++) {
//    LCD.scrollDisplayLeft();
//    delay(500);
//  }

//  for (int posCounter = 0; posCounter < 4; posCounter++) {
//    LCD.scrollDisplayRight();
//    delay(500);
//  }

  
int goalYear = 2018;
int goalMonth = 10;
int goalDay = 5;
int monthsLeft = goalMonth - month();
int yearsLeft = goalYear - year();
int daysLeft = goalDay - day();
  
  if (yearsLeft==2) {
    goalMonth = 22;
  }

  if (yearsLeft==1) {
    goalMonth = 22;
  }

  if (yearsLeft==0) {
    goalMonth = 10;
  }

  if (yearsLeft - 1<0) {
    goalYear = 2019;
  }

  if (monthsLeft > 12) {              //This is for months before month due back
    monthsLeft = monthsLeft - 12;
  }

  if (monthsLeft < 0) {               //This is for months after month due back
    monthsLeft = monthsLeft + 12;
    yearsLeft = yearsLeft - 1;        //Corrects months taking away from the year
  }

  if (daysLeft < 0) {
    daysLeft = daysLeft + 30;
    monthsLeft = monthsLeft - 1;      //Corrects for days taking away from the month
  }
  
  //All Serial.print below are for debugging in the Serial Monitor
  
  Serial.println("The time and date are:");
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.println(second());
  Serial.print(month());
  Serial.print("/");
  Serial.print(day());
  Serial.print("/");
  Serial.println(year());
  delay(1000);

  Serial.println();
  Serial.print("There is ");
  Serial.print(yearsLeft);
  Serial.print(" year ");
  Serial.print(monthsLeft);
  Serial.print(" months and ");
  Serial.print(daysLeft);
  Serial.println(" days left until Kevin gets home");

  //Display info on screen
  LCD.setCursor(0,1); //Sets cursor to second row for writing
  LCD.print(yearsLeft);
  LCD.print(" Yr ");
  LCD.print(monthsLeft);
  LCD.print(" Mo ");
  LCD.print(daysLeft);
  LCD.print(" D ");
  
}
