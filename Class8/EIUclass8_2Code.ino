// Smart street light system (LDR + PIR sensor LED control)
// works like smart street lights (the light is dim at night periods but comes up more brightened when a person approaches it)

//ldr sensor
#define ldrPin A0
int ldrVal;
//pir motion sensor
#define pirPin 7
int motion;

//led
#define ledPin 6

void setup() {
  // put your setup code here, to run once:
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  ldrVal = analogRead(ldrPin); //reading the ldr value
  motion = digitalRead(pirPin); //reading the pir sensor value
  Serial.print("LDR: ");
  Serial.println(ldrVal);
  Serial.print("PIR MOTION: ");
  Serial.println(motion);
 //control logic
  if (ldrVal < 200) {
    if (motion == 1) {
      //full light
      digitalWrite(ledPin,HIGH);
      delay(3000);
    } 
    else {
      //dim light
      analogWrite(ledPin, 20);
      }
  }
  else {
    //light off
    digitalWrite(ledPin, LOW);
  }
}
