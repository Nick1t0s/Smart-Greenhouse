#define THINGER_SERIAL_DEBUG

#include <ThingerEthernet.h>

ThingerEthernet thing("Nick1t0s", "ESP", "ESP32!");
int g;

void setup() {
  // open serial for debugging
  Serial.begin(115200);
  pinMode(13,OUTPUT);

  // pin control example (i.e. turning on/off a light, a relay, etc)
  thing["led"] << digitalPin(13);
  thing["hysteresis"] << [](pson& in){
    int g = in;
    Serial.println(g);
};
};


  // resource output example (i.e. reading a sensor value, a variable, etc)

  // more details at http://docs.thinger.io/arduino/

void loop() {
  thing.handle();

}
