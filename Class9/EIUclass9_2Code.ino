
// Using a 16x2 i2c LCD to display sensor value (temp and humd from a DHT11 sensor)
// I2C pins on arduino uno is A4 SDA, A5 SCL, for esp32 21 SDA, 22 SCL

//including needed library
#include <Wire.h>; // I2C wire library
#include <LiquidCrystal_I2C.h>; // LCD library (download LiquidCrystal I2C library by Frank from the library manager before using this line)
#include <DHT.h>; // DHT sensor library


//creating the lcd object
LiquidCrystal_I2C lcd(0x27,16,2); // object_name(address, column size, row size)

//dht11 object
#define DHTPIN 7
#define DHTTYPE DHT11
DHT tempHum(DHTPIN,DHTTYPE);

// variables to store temp & humd
float humidity;
float tempC;
float tempF;

void setup() {
  // put your setup code here, to run once:
  lcd.init(); // initializing/starting the lcd
  lcd.backlight(); // oning the backlight
  lcd.clear(); //erasing what was previously in the lcd

  //welcome message when screen comes on
  lcd.setCursor(4,0); //setting the write position (column (0-15),row (0-1)) hence 16x2
  lcd.print("Welcome!"); //writng on selected position
  lcd.setCursor(6,1);
  lcd.print("User");
  delay(4000);
  lcd.clear();

  //initializing/starting the dht11 sensor
  tempHum.begin();
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = tempHum.readHumidity();
  tempC = tempHum.readTemperature(); //temp in celcius

  lcd.setCursor(0,0);
  lcd.print("Temp (C):");
  lcd.setCursor(10,0);
  lcd.print(tempC);

  lcd.setCursor(0,1);
  lcd.print("Humd (%):");
  lcd.setCursor(10,1);
  lcd.print(humidity);

}
