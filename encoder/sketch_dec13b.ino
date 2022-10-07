int rotation_value; //value of rotation from local web
//-----------------------position control
const byte pin_a = 5;   //for encoder pulse A
const byte pin_b = 6;   //for encoder pulse B
const byte pin_fwd = 12; //for H-bridge: run motor forward
const byte pin_bwd = 13; //for H-bridge: run motor backward
const byte pin_pwm = 14; //for H-bridge: motor speed
int encoder_r = 0;
int encoder_f = 0;
int position_pv = 0;
int position_sv = 0;
int m_direction = 0;


void setup(){
  Serial.begin(9600);
  //---------declaration for position control
  pinMode(pin_a,INPUT_PULLUP);
  pinMode(pin_b,INPUT_PULLUP);
  pinMode(pin_fwd,OUTPUT);
  pinMode(pin_bwd,OUTPUT);
  pinMode(pin_pwm,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_r, RISING);

  digitalWrite(pin_fwd,0);  //stop motor
  digitalWrite(pin_bwd,0);  //stop motor
  
  // Serial port for debugging purposes
  
 

}
//String ROTATION = request->getParam("rotation")->value();
//    rotation_value = 1024 - (ROTATION.toInt())*10;
 
void loop(){
  analogWrite(pin_pwm,650); //set motor speed = 650/1024
  position_sv = (1024 - rotation_value)/10; //unit: % (e.g. 0% ~ 0dg; 100% ~ 360dg)
  position_pv = ((encoder_r+encoder_f)/2); //unit: %; encoder pulse per revolution: 200ppr
  if(position_pv-position_sv < 0){
      digitalWrite(pin_fwd,1);
      digitalWrite(pin_bwd,0);
    }
    else{
      if(position_pv-position_sv > 0){
        digitalWrite(pin_fwd,0);
        digitalWrite(pin_bwd,1);
      }
      else{
        //stop motor if position between +0 ~ -0
        digitalWrite(pin_fwd,0);  //stop motor
        digitalWrite(pin_bwd,0);  //stop motor
      }
    }
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
