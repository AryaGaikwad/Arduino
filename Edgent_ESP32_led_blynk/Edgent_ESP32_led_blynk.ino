
// Fill-in information from your Blynk Template here
//#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
//#define BLYNK_DEVICE_NAME           "Device"
#include <math.h>
#define BLYNK_TEMPLATE_ID "TMPL9ZTNFXkW"
#define BLYNK_DEVICE_NAME "joy"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
//#define USE_ESP32C3_DEV_MODULE
//#define USE_ESP32S2_DEV_KIT

#include "BlynkEdgent.h"
BLYNK_WRITE(V0)    //x
{
  int pinValue_X = param.asInt();
  Serial.println(pinValue_X);
  digitalWrite(15,pinValue_X);//doubt
  
}
BLYNK_WRITE(V1)    //y
{
  int pinValue_Y = param.asInt();
  Serial.println(pinValue_Y);
  digitalWrite(13,pinValue_Y);//doubt
  
}

void setup()
{
  pinMode(15,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  
}
