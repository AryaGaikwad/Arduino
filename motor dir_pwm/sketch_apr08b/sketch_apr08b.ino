#define dir1 D1
#define dir2 D2
#define dir3 D3
#define dir4 D4

#define pwm1 D5
#define pwm2 D6
#define pwm3 D7
#define pwm4 D8

void setup(){
  pinMode(2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
}

void left()
{
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,LOW);
}

void right(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
  
}

void forward(){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,LOW);
  
}
void backward(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,HIGH);
  
}


void velocity()
{
  analogWrite(pwm1,80);
  analogWrite(pwm2,80);
  analogWrite(pwm3,80);
  analogWrite(pwm4,80);
}
void loop(){
  velocity();
  forward();
  delay(5000);
  backward();
  delay(5000);
}
