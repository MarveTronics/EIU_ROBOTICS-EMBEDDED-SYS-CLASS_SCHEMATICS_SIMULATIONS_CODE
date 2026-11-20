//First practice (Hello World of hardware)

void setup() {
  // put your setup code here, to run once:
  
  // setting up used pins
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(6,HIGH); // setting led1 on
  digitalWrite(7,LOW); // setting led2 off
  delay(200); //delay of 2secs
  digitalWrite(6,LOW); // setting led1 off
  digitalWrite(7,HIGH); // setting led2 on
  delay(200); //delay of 2secs

}
