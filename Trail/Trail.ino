int dir1= 13;
//int pwm1= 15;

void setup() {
   Serial.begin(9600);
}


void right(){
  digitalWrite(dir1,HIGH);
}

//void velocity(){
// analogWrite(pwm1,50);
//}

void loop() {
  //velocity();
  right();
  }
