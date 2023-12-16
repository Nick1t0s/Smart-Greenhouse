#include <ThingerEthernet.h>

#define USERNAME "Nick1t0s"
#define DEVICE_ID "ESP"
#define DEVICE_CREDENTIAL "ESP32!"

ThingerEthernet thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2,INPUT_PULLUP);

  // pin control example (i.e. turning on/off a light, a relay, etc)
  thing["led"] << digitalPin(13);

  // resource output example (i.e. reading a sensor value, a variable, etc)
  thing["millis"] >> outputValue(millis());
  digitalWrite(13,digitalRead(2));
  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  digitalWrite(13,digitalRead(2));
  thing.handle();
}
