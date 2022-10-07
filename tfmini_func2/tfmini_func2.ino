#include <SoftwareSerial.h>  //header file of software serial port

SoftwareSerial Serial1(2,3); //define software serial port name as Serial1 and define pin2 as RX and pin3 as TX
SoftwareSerial Serial2(11,12);
/* For Arduinoboards with multiple serial ports like DUEboard, interpret above two pieces of code and directly use Serial1 serial port*/
int dist1,dist2; //actual distance measurements of LiDAR
int check;  //save check value
int i;
int lidar1[9];  //save data measured by LiDAR
int lidar2[9];
const int HEADER=0x59;  //frame header of data package

void setup() {
  Serial.begin(9600); //set bit rate of serial port connecting Arduino with computer
  Serial1.begin(115200);  //set bit rate of serial port connecting LiDAR with Arduino
}
void lidarcheck1(int arr[9]){
  if (Serial1.available()) {  //check if serial port has data input
    if(Serial1.read() == HEADER) {  //assess data package frame HEAD 0x59
      arr[0]=HEADER;
      if (Serial1.read() == HEADER) { //assess data package frame header 0x59
        arr[1] = HEADER;
        for (i = 2; i < 9; i++) { //save data in array
          arr[i] = Serial1.read();
        }
        check = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] + arr[7];
        if (arr[8] == (check & 0xff)){ //verify the received data as per protocol
          dist1 = arr[2] + arr[3] * 256;     //calculate distance value
          Serial.print("dist1 = ");
          Serial.println(dist1); //output measure distance value of LiDAR
          
            
           
        }
      }
    }
  }
}
void lidarcheck2(int arr[9]){
  if (Serial2.available()) {  //check if serial port has data input
    if(Serial2.read() == HEADER) {  //assess data package frame HEAD 0x59
      arr[0]=HEADER;
      if (Serial2.read() == HEADER) { //assess data package frame header 0x59
        arr[1] = HEADER;
        for (i = 2; i < 9; i++) { //save data in array
          arr[i] = Serial2.read();
        }
        check = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] + arr[7];
        if (arr[8] == (check & 0xff)){ //verify the received data as per protocol
          dist2 = arr[2] + arr[3] * 256;     //calculate distance value
          Serial.print("dist2 = ");
          Serial.println(dist2); //output measure distance value of LiDAR
          
            
           
        }
      }
    }
  }
}

void loop() { 
  lidarcheck1(lidar1);
  lidarcheck2(lidar2);
}



 void left(){
 digitalWrite(1,LOW);
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
  
  }
 void right(){
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  }
 void forward(){
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  
  }
 void backward(){
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  }

  void stop(){
     analogWrite(1,0);
  analogWrite(2,0);
  analogWrite(3,0);
  analogWrite(4,0);
  }
