const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
int motorPin1=10;
int motorPin2=3;
int motorPin3=9;
int motorPin4=5;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, i;
   pinMode(pingPin, OUTPUT);

   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   
   duration = pulseIn(echoPin, HIGH);
   
   
   i = microsecondsToCentimeters(duration);
  
   Serial.print(i);
   Serial.print("cm");
   Serial.println();
   
   delay(100);
   
   if (i>15)
    {
      analogWrite(motorPin3,40);
      analogWrite(motorPin4,40);
      
    }
    else
    {
      analogWrite(motorPin1,69);
      analogWrite(motorPin4,69);
      
    }
    

   
}



long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
