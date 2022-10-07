int IRSensor1;
int IRSensor2;
int motorPin1=;
int motorPin2=;
int motorPin3=;
int motorPin4=;
void setup() {
  pinMode (IRSensor1, INPUT);
  pinMode (IRSensor2, INPUT);
  
}

void loop() {
  forward();
  left();
  right();
  
}
forward()
{
  if(s1==0 && s2==0){
    analogWrite(motorPin,20);
    analogWrite(motorPin,20);
  }
}

left()
{
  int s1=digitalRead(IRSensor1);
  if(s1==1)
  {
    analogWrite(motorPin,15);
    analogWrite(motorPin,15);
    
  }
  stop();
}

right()
{
  int s2=digitalRead(IRSensor2);
  if(s2==1)
  {
    analogWrite(motorPin,15);
    analogWrite(motorPin,15);
  }
  stop();
}


void stop()
{
  analogWrite(motorPin,0);
  analogWrite(motorPin,0);
  analogWrite(motorPin,0);
  analogWrite(motorPin,0);
}

}
