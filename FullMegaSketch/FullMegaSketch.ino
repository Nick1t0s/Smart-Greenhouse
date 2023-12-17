#define THINGER_SERIAL_DEBUG

#include <ThingerEthernet.h>
#include "yourData.h"

ThingerEthernet thing(NIKNAME, DEVICEID, DEVICEPASS);

void setup() {
  // open serial for debugging
  Serial.begin(BAUDS);

  pinMode(WPIN, OUTPUT);
  pinMode(HOTPIN, OUTPUT);
  pinMode(PUMPPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);

  // pin control example (i.e. turning on/off a light, a relay, etc)
  thing["led"] << digitalPin(2);

  // resource output example (i.e. reading a sensor value, a variable, etc)
  thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
