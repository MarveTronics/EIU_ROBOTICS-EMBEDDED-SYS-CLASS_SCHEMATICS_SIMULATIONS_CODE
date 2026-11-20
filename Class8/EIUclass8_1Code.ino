//Temperature Monitoring with DHT11 sensor and RGB LED

//dht sensor library (download the Adafruit DHT sensor library before including this line of code)
#include "DHT.h"

#define DHTPIN 5 //DHT sensor pin assignment
#define DHTTYPE DHT11 //DHT sensor type selection (DHT11 or DHT22)
DHT tempHum(DHTPIN,DHTTYPE); //creating DHT sensor object

// variables to store temp & humidity values
float humidity;
float tempC;
float tempF;

#define rLed 4 //pin assignment for red of the RGB
#define gLed 3 //pin assignment for green of the RGB
#define bLed 2 //pin assignment for blue of the RGB

void setup() {
  // put your setup code here, to run once:

  //setting up the RGB LED
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);

  Serial.begin(9600);
  tempHum.begin(); // initializing/starting up the DHT sensor
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = tempHum.readHumidity(); //reading humidity
  tempC = tempHum.readTemperature(); //reading temp in celcius
  tempF = tempHum.readTemperature(true); //reading temp in farenheit

  //delay(2000);

  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Temperature in Celcius: ");
  Serial.print(tempC);
  Serial.println("°C ");
  Serial.print("Temperature in Farenhiet: ");
  Serial.print(tempF);
  Serial.println("°F");
  
  
  //logical control flow to control the RGB based on temp
  if (tempC <= 23) {
    rgb(0,255,0); //calling the RGB function to set color to green
  }
  else if (tempC < 30) {
    rgb(255,255,0); //calling the RGB function to set color to yellow
  }
  else if (tempC > 30) {
    rgb(255,0,0); //calling the RGB function to set color to red
  }
  

}

//custom RGB function declaration to control the colors of the RGB LED
int rgb(int red,int green,int blue) {
  analogWrite(rLed, red);
  analogWrite(gLed, green);
  analogWrite(bLed, blue);
}
