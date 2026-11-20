// Finding I2C address (used to find out the unique address of your I2C device)
// I2C pins on arduino uno is A4 SDA, A5 SCL, for esp32 21 SDA, 22 SCL


#include <Wire.h> // I2C wire library

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("I2C scanner, Scanning...");
  byte count = 0;

  Wire.begin();
  for (byte i = 8; i < 120; i++){
    Wire.beginTransmission(i);
    if (Wire.endTransmission () == 0){
      Serial.print("found address: ");
      Serial.print(i, DEC);
      Serial.print(" (0x");
      Serial.print(i, HEX);
      Serial.println(")");
      count++;
      delay(1);
    }
  }

  Serial.println("Done.");
  Serial.print("found ");
  Serial.print(count, DEC);
  Serial.println(" device(s).");

}

void loop() {
  // put your main code here, to run repeatedly:

}
