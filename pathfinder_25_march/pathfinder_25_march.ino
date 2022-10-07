#include<Servo.h>
Servo Myservo;

int pos;
int dir1= 48;
int dir2= 52;
int dir3= 49;
int dir4= 53;
int pwm1= 11;
int pwm2= 13;
int pwm3= 10;
int pwm4= 12;

const int pingPin = 8;
const int echoPin = 9;

bool turn_left;
bool turn_right;
bool forward_move=true;

bool LT=false;
bool RT=false;

void setup() {
   Serial.begin(9600);
   Myservo.attach(7);
}

void right(){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,LOW);
}
void left(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
}
void forward(){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,HIGH);
  
}
void backward(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,LOW);
}

void wait(){
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
}
void velocity(){
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
}


long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
void servo_left()
{
  Myservo.write(180);
}
void servo_forward()
{
  Myservo.write(90);
}
void servo_right()
{
  Myservo.write(0);
}
int ultradistance(){
  long duration;
  int distance;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = microsecondsToCentimeters(duration);
//  Serial.print(distance);
//  Serial.print("cm");
//  Serial.println();
  return distance;
}

void loop() {
  servo_forward();
  delay(1000);
  int distanceF=ultradistance();
  int leftDist, rightDist;
  velocity();
  if ((distanceF>30)&&(forward_move==true))
  {
    servo_forward();
    forward(); 
    RT=false;
    LT=false; 
  }
  else if (RT){right();}
  else if (LT){left();}
  else{
    if (forward_move){
    wait();
    delay(1000);
    servo_left();
    delay(2000);
    leftDist=ultradistance();
    delay(1000);
    servo_right();
    delay(2000);
    rightDist=ultradistance();
    delay(1000);
    servo_forward();
    delay(1000);
    forward_move=false;
    }
    

    if ((leftDist>rightDist) && (leftDist>30))
    {
      LT=true;

      forward_move=true;
    }
    else if((leftDist<rightDist) && (rightDist>30))
    {
      RT=true;

      forward_move=true;
    }
