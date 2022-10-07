#include <PS2X_lib.h>  //for v1.6
#define CHA_motor_1 3
#define CHB_motor_1 4
#define CHA_motor_2 2
#define CHB_motor_2 5
#define CHA_motor_3 21
#define CHB_motor_3 22
#define CHA_motor_4 19
#define CHB_motor_4 6
#define MD1_pwm_1 13 //motor_2
#define MD1_dir_1 52 //motor_2
#define MD1_pwm_2 12 //motor_1
#define MD1_dir_2 53 //motor_1
#define MD2_pwm_1 11 //motor_4
#define MD2_dir_1 48 //motor_4
#define MD2_pwm_2 10 //motor_3
#define MD2_dir_2 49 //motor_3
PS2X ps2x; // create PS2 Controller Class

int error = 0;
byte type = 0;
byte vibrate = 0;


void speed_50() {
  analogWrite(MD1_pwm_1, 50);
  analogWrite(MD1_pwm_2, 50);
  analogWrite(MD2_pwm_1, 50);
  analogWrite(MD2_pwm_2, 50);
}

void speed_100() {
  analogWrite(MD1_pwm_1, 200);
  analogWrite(MD1_pwm_2, 200);
  analogWrite(MD2_pwm_1, 200);
  analogWrite(MD2_pwm_2, 200);
}


void stop_0() {
  analogWrite(MD1_pwm_1, 0);
  analogWrite(MD1_pwm_2, 0);
  analogWrite(MD2_pwm_1, 0);
  analogWrite(MD2_pwm_2, 0);

}

void backward() {
  digitalWrite(MD1_dir_2, LOW);
  digitalWrite(MD2_dir_2, HIGH);
  digitalWrite(MD1_dir_1, HIGH);
  digitalWrite(MD2_dir_1, LOW);
}

void forward() {
  digitalWrite(MD1_dir_2, HIGH);
  digitalWrite(MD2_dir_2, LOW);
  digitalWrite(MD1_dir_1, LOW);
  digitalWrite(MD2_dir_1, HIGH);
}

void right() {
  digitalWrite(MD1_dir_2, HIGH);
  digitalWrite(MD2_dir_2, HIGH);
  digitalWrite(MD1_dir_1, HIGH);
  digitalWrite(MD2_dir_1, HIGH);
}

void left() {
  digitalWrite(MD1_dir_2, LOW);
  digitalWrite(MD2_dir_2, LOW);
  digitalWrite(MD1_dir_1, LOW);
  digitalWrite(MD2_dir_1, LOW);
}




void setup() {
  Serial.begin(57600);
  pinMode(MD1_dir_1, OUTPUT);
  pinMode(MD1_pwm_1, OUTPUT);
  pinMode(MD1_dir_2, OUTPUT);
  pinMode(MD1_pwm_2, OUTPUT);
  pinMode(MD2_dir_1, OUTPUT);
  pinMode(MD2_pwm_1, OUTPUT);
  pinMode(MD2_dir_2, OUTPUT);
  pinMode(MD2_pwm_2, OUTPUT);
  pinMode(CHA_motor_1, INPUT);
  pinMode(CHB_motor_1, INPUT);
  pinMode(CHA_motor_2, INPUT);
  pinMode(CHB_motor_2, INPUT);
  pinMode(CHA_motor_3, INPUT);
  pinMode(CHB_motor_3, INPUT);
  pinMode(CHA_motor_4, INPUT);
  pinMode(CHB_motor_4, INPUT);

  //CHANGES for v1.6 HERE!!! *****PAY ATTENTION****

  error = ps2x.config_gamepad(37, 39 , 36, 38, true, true); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error

  if (error == 0) {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }

  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  //Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
  }

}

void loop() {
  if (error == 1) //skip loop if no controller found
    return;
  ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
  vibrate = ps2x.Analog(PSAB_BLUE);        //this will set the large motor vibrate speed based on


  if (ps2x.Button(PSB_L2)) {
    
    
    if (ps2x.Analog(PSS_LY) == 0) {
      Serial.println(ps2x.Analog(PSS_LY), DEC);
      forward();
      speed_50();
    }
    if (ps2x.Analog(PSS_LY) == 255) {
      backward();
      speed_50();
    }

    if (ps2x.Analog(PSS_RX) == 0) {
      left();
      speed_50();
    }
    if (ps2x.Analog(PSS_RX) == 255) {
      right();
      speed_50();
    }
  }


  else if (ps2x.Button(PSB_R2)) {
    if (ps2x.Analog(PSS_LY) == 0) {
      Serial.println(ps2x.Analog(PSS_LY), DEC);
      forward();
      speed_100();
    }
    if (ps2x.Analog(PSS_LY) == 255) {
      backward();
      speed_100();
    }
    if (ps2x.Analog(PSS_RX) == 0) {
      left();
      speed_100();
    }
    if (ps2x.Analog(PSS_RX) == 255) {
      right();
      speed_100();
    }
  } else stop_0();


delay(50);

}
