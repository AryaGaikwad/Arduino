
int pin_a=2;//channel A
int pin_b=3;//channel B 

const byte pin_fwd = 12; //for H-bridge: run motor forward
const byte pin_bwd = 13; //for H-bridge: run motor backward
//const byte pin_pwm = 14; //for H-bridge: motor speed
int encoder_r = 0;//rising
int encoder_f = 0;//falling
//int position_pv = 0;
//int position_sv = 0;
int m_direction = 0;//constant for pin b

 

void setup() {
Serial.begin(9600);
 pinMode(pin_a,INPUT_PULLUP);//Initializing high
 pinMode(pin_b,INPUT_PULLUP);//Initializing high
// pinMode(pin_fwd,OUTPUT);
// pinMode(pin_bwd,OUTPUT);
// pinMode(pin_pwm,OUTPUT);
 attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_r, RISING);//Initialising Pin A to Rising
 
}

void loop() {
  
  Serial.println(encoder_r);
  Serial.println(encoder_f);
   

}
void detect_a_r() {
  m_direction = digitalRead(pin_b); //read direction of motor  which initially HIGH as per our declaration in code
  if(!m_direction){
    encoder_r += 1;   //increasing encoder at forward run // pin B LOW and pin A Rising = CLOCKWISE
  }
  else{
    encoder_r += -1;  //decreasing encoder at backward run //pin B HIGH and pin A Rising = Anticlockwise
  }
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_f, FALLING); //change interrupt to Falling edge
}
void detect_a_f() {
  m_direction = digitalRead(pin_b); //read direction of motor which initially HIGH as per our declaration in code
  if(m_direction){
    encoder_f += 1; //increasing encoder at forward run //pin B HIGH and pin A Falling = clockwise
  }
  else{
    encoder_f += -1; //decreasing encoder at backward run // pin B LOW and pin A Falling = ANTICLOCKWISE
  }
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_r, RISING);  //change interrupt to Rising edge
}
