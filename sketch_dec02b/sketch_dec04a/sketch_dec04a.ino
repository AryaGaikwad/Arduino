
#include <Firebird.h>
Firebird fb;
void setup()
{
  fb.configMotors();
  Serial2.begin(57600);
}

void loop()
{
  int wl1 = fb.readLine1();
  int wl2 = fb.readLine2();
  int wl3 = fb.readLine3();
  Serial2.print("White Line 1: ");
  Serial2.println(wl1);
  Serial2.print("White Line 2: ");
  Serial2.println(wl2);
  Serial2.print("White Line 3: ");
  Serial2.println(wl3);
  if (wl3>350)
  {
    lturn();
  }
  if(wl1>350)
  {
    rturn();
  }
  if(wl2>350)
  {
    fb.stopMotors();
  }
  else
  {
    forward();
  }
}


void forward()
{
  fb.moveForward(100,100);
}
void lturn()
 {
  fb.moveForwardR(40);
  fb.moveBackwardL(40);
 }
void rturn()
{
  fb.moveForwardL(40);
  fb.moveBackwardR(40);
}
