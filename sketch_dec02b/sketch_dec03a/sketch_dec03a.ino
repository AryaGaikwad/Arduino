int IRSensor = 3; // connect ir sensor to arduino pin 2




void setup() 
{



  pinMode (IRSensor, INPUT); // sensor pin INPUT
  
  Serial.begin(9600);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 1)
    {
      
      
    }
  else
  {
    
  }
  Serial.println(statusSensor);
  
}
