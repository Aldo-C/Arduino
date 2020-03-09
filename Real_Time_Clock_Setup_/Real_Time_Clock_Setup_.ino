// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int LEDPin = 8;
String Request;

void setup () {

#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  Serial.begin(9600);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time THIS SKETCH WAS COMPILED!
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  pinMode(LEDPin, OUTPUT);
  
}

void loop () {
    DateTime now = rtc.now();

    // All these Serial.print lines are for testing and can be commented or deleted out
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    //This query is for testing purposes only, in reality the check will be for distance using the ultrasonic sensors.
    Serial.print("What would you like to do, turn LED 'on' or 'off'? ");
    while(Serial.available() == 0){
    }
    Request = Serial.readString();


    // The following code is a test of whether the relay can be prevented from turning on depending on what time it is. This prevents the LED string from
    // turning on during the day.
    if(Request == "on\n" && now.hour() >= 17 && now.hour() <= 6){        // This checks the request and then checks to see if the time is after 5pm or before 6am
      digitalWrite(LEDPin, HIGH);
    }
    else if(Request == "off\n" && now.hour() >= 17 && now.hour() <= 6){  // This checks the request and then checks to see if the time is after 5pm or before 6am
      digitalWrite(LEDPin, LOW);
    }
    
    Serial.println();
    delay(1000);
}
