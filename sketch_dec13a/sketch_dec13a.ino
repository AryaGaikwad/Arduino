int encoderValue;

void count(void); // code for counting the increasing values of encoder ticks 
void setup()
{

Serial.begin(9600);

//pinMode(21,INPUT);
pinMode(3,INPUT);
attachInterrupt(3,count,HIGH);

encoderValue=0;

}

void loop()

{
int a,b;
//a= digitalRead(21);
b= digitalRead(3);


Serial.print("Starting\n");

// to print encoder value on the screen
Serial.print("Encoder Value="); 
Serial.println(encoderValue);

//Serial.print(a);
//Serial.println("\n");
Serial.print(b);
Serial.println("\n");

}

void count()

{

encoderValue++;

}
