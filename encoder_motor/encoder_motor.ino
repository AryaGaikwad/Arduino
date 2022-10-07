int pin_a=2;
int pin_b=3;

int pin_fwd = 12; //for H-bridge: run motor forward
int pin_bwd = 13; //for H-bridge: run motor backward
//const byte pin_pwm = 14; //for H-bridge: motor speed
int encoder_r = 0;
int encoder_f = 0;

int m_direction = 0;
int x,y;

void setup() {
Serial.begin(9600);
 pinMode(pin_a,INPUT_PULLUP);
 pinMode(pin_b,INPUT_PULLUP);
// pinMode(pin_fwd,OUTPUT);
// pinMode(pin_bwd,OUTPUT);
// pinMode(pin_pwm,OUTPUT);

 attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_r, RISING);
}

void loop() {
Serial.println(encoder_r);
Serial.println(encoder_f);
x= encoder_f + encoder_r;
y= encoder_f + encoder_r;
Serial.print("x:");
Serial.println(x);
Serial.print("y:");
Serial.println(y);
pos();

}
void detect_a_r() {
  m_direction = digitalRead(pin_b); //read direction of motor
  if(!m_direction){
    encoder_r += 1;   //increasing encoder at forward run
  }
  else{
    encoder_r += -1;  //decreasing encoder at backward run
  }
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_f, FALLING); //change interrupt to Falling edge
}
void detect_a_f() {
  m_direction = digitalRead(pin_b); //read direction of motor
  if(m_direction){
    encoder_f += 1; //increasing encoder at forward run
  }
  else{
    encoder_f += -1; //decreasing encoder at backward run
  }
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_r, RISING);  //change interrupt to Rising edge
}

int pos()
{
  forward();
  
  if(x=50){
       
      backward() ;     
    }   
}

void forward()
{
  while(x>0 && x<50)
  {
    digitalWrite(pin_fwd,1);
    digitalWrite(pin_bwd,0);
    
  }
}

void backward()
{ 
  x=0;
  do
  {
    digitalWrite(pin_fwd,0);
    digitalWrite(pin_bwd,1);
  }while(x>-25);
  forward();
}
