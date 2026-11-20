//Understanding variables, funcions, and loops

//setting up variables to store data
int led1 = 6;
int led2 = 7;
int dtime = 500;
int seqAmt = 10;

void setup() {
  // put your setup code here, to run once:

  // setting up used pins
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly

  //using for loop to loop through a blink sequence
  for(int i = 1; i <= seqAmt; i++) {
    //calling a function "seq1"
    seq1();
  }

  //using for loop to loop through a blink sequence
  for(int i = 1; i <= seqAmt; i++) {
    //calling a function "seq2"
    seq2();
  }

  //using for loop to loop through a blink sequence
  for(int i = 1; i <= seqAmt; i++) {
    //calling a function "seq3"
    seq3();
  }

}

// creating custom functions

// seq1 function
void seq1() {
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  delay(dtime);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  delay(dtime);
}
// seq2 function
void seq2() {
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(dtime);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  delay(dtime);
}
// seq3 function
void seq3() {
  //using for loop to create a blink sequence
  for (int i = 1; i <= 3; i++) {
    digitalWrite(led1,HIGH);
    delay(dtime);
    digitalWrite(led1,LOW);
    delay(dtime);
  }

  //using for loop to create a blink sequence
  for (int i = 1; i <= 3; i++) {
    digitalWrite(led2,HIGH);
    delay(dtime);
    digitalWrite(led2,LOW);
    delay(dtime);
  }
}
