//Understanding Control flow (if statements)

int led1 = 6;
int led2 = 7;
int pot = A0;
int potRead;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //activating the serial monitor

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(pot,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  potRead = analogRead(pot); // performing an analog read so as to read the potentiometer value
  Serial.println(potRead); //reading from the serial monitor to confirm that we are getting accurate readings (best to comment afer use)

  // conditional statments that controls the logic/flow of the circuit
  if (potRead > 512) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else if (potRead <= 512) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }


}
