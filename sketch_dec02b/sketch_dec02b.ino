int motorPin1=10;
int motorPin2=11;
int motorPin3=12;
int motorPin4=13;
int pingPin=6;
int echoPin=7;

void setup()
{
  Serial.begin(9600);
}
void loop()
//{  long dist;
//   dist=usensor();
//   if (dist>15)
//   {
    forward();
   }
   if (dist<15){
       turn();
   }
} 
//long usensor(){
//  long duration, inches,i;
//   pinMode(pingPin, OUTPUT);
//
//   digitalWrite(pingPin, LOW);
//   delayMicroseconds(2);
//   
//   digitalWrite(pingPin, HIGH);
//   delayMicroseconds(10);
//   
//   digitalWrite(pingPin, LOW);
//   pinMode(echoPin, INPUT);
//   
//   duration = pulseIn(echoPin, HIGH);
//   delay(100); 
//   i = duration/ 29 / 2;
//   Serial.print(i);
//   Serial.print("cm");
//   Serial.println();
//   return i;
//}

void forward()
{
    analogWrite(motorPin2,40);
    analogWrite(motorPin4,40);
}

void turn()
{
  analogWrite(motorPin1,69);
  analogWrite(motorPin4,69);
}
      
