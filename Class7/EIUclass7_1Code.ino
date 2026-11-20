//working with pushbuttons
//Pull up configuration

int ledPin = 7;
int btn = 6;
bool btnS; //variable to store the button state

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(btn, INPUT);

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  btnS = digitalRead(btn); // performing a digital read so as to read the pushbutton state

  Serial.println(btnS);
  
  //control logic to on/off the led when button is pressed or not
  if (btnS == 1) {
    digitalWrite(ledPin, !btnS);
  }
  else {
    digitalWrite(ledPin, !btnS);
  }

}
