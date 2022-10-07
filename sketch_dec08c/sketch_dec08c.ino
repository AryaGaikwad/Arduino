int motorPin1=6;
int motorPin2=5;
int motorPin3=3;
int motorPin4=4;
void setup() {
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);

}

void loop() {
  digitalWrite(motorPin1,HIGH);
  digitalWrite(motorPin2,LOW);
 digitalWrite(motorPin3,HIGH);
 digitalWrite(motorPin4,LOW);
  
}
