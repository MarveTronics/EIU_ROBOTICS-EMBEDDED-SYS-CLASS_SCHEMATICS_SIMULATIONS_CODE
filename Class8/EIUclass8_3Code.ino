// Working with ultrasonic sensor
//Proximity Alert

#define trigger 2 //pin assignment for trigger
#define echo 3 //pin assignment for echo

// variables to store time and distance
int reflectionTime;
int reflectionT1;
int reflectionT2;
float distance;

float soundSpeed = 0.0343; //speed of sound in centimeters per microsecond

#define buzzer 7 //active buzzer pin assignment

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //calculating time for the signal to go and come back
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  reflectionT1 = pulseIn(echo,HIGH);
  reflectionT2 = pulseIn(echo,LOW);
  reflectionTime = reflectionT1 - reflectionT2;
  //after time has been gotten, we calculate distance with the formula distance = (speed * time)/2
  distance = (soundSpeed*reflectionTime)/2;

  Serial.println(distance);
  //delay(2000);

  //since a negative distance is invalid or means sensor has excided it's range, we set it to automatically read it at the max range (400cm)
  if (distance < 0) {
    distance = 400;
  }

  //control logic (buzzer sound quickens as distance becomes closer and slowers as distance gets further)
  if (distance < 6) {
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    delay(50);
  }

  else if (distance < 10) {
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);
  }

  else if (distance < 16) {
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  }

  else if (distance < 20) {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }

  else {
    digitalWrite(buzzer, LOW);
  }

}
