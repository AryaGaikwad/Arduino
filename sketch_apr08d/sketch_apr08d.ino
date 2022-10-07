#define BLYNK_TEMPLATE_ID "TMPLdCsTeYzY"
#define BLYNK_DEVICE_NAME "Try 2"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"

BLYNK_WRITE(V0){
  int pinValue=param.asInt();
  Serial.println(pinValue);
  digitalWrite(2,pinValue);
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
