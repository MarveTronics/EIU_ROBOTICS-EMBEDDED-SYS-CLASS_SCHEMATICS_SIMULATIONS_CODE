//Pull up btn toggle on/off configuration

int ledPin = 7;
int btn = 6;
bool btnS;

bool lastBtnSt = true;
bool ledSt = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(btn, INPUT);

  digitalWrite(ledPin, LOW);

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  btnS = digitalRead(btn);

  if (btnS == 0 && lastBtnSt == 1) {
    ledSt = !ledSt;
    digitalWrite(ledPin, ledSt);

    delay(50);
  }

  lastBtnSt = btnS;

}
