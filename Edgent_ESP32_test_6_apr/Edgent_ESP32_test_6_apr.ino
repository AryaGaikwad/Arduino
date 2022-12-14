
// Fill-in information from your Blynk Template here
//#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
//#define BLYNK_DEVICE_NAME           "Device"

#define BLYNK_TEMPLATE_ID "TMPL9ZTNFXkW"
#define BLYNK_DEVICE_NAME "joy"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG
#include "BlynkEdgent.h"

BLYNK_WRITE(V0)
{
  int pinValue_X = param.asInt();
  Serial.println(pinValue_X);
  analogWrite(15,pinValue_X);//doubt 
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
