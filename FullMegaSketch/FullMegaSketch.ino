#define THINGER_SERIAL_DEBUG

#include <ThingerEthernet.h>
#include "yourData.h"
#include <DHT.h>

ThingerEthernet thing(NIKNAME, DEVICEID, DEVICEPASS);

DHT dht(DHTPIN, DHTTYPE);
DHT outDht1(OUTDHT1PIN, OUTDHT1TYPE);
DHT outDht2(OUTDHT2PIN, OUTDHT2TYPE);

void setup() {
  // open serial for debugging
  Serial.begin(BAUDS);
  dht.begin();
  outDht1.begin();
  outDht2.begin();


  pinMode(WPIN, OUTPUT);
  pinMode(HOTPIN, OUTPUT);
  pinMode(PUMPPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(TEENPIN, OUTPUT);

  pinMode(ISA,OUTPUT);

  // pin control example (i.e. turning on/off a light, a relay, etc)
  thing["TestPin"] << digitalPin(TEENPIN);
  thing["WENT"] << digitalPin(WPIN);
  thing["HOT"] << digitalPin(HOTPIN);
  thing["PUMP"] << digitalPin(PUMPPIN);
  thing["LED"] << digitalPin(LEDPIN);
  thing["AUTO"] << digitalPin(ISA);

  // resource output example (i.e. reading a sensor value, a variable, etc)
  /*
  thing["Humidity"] >> outputValue(dht.readHumidity());
  thing["Temperature"] >> outputValue(dht.readTemperature());

  thing["outHumidity1"] >> outputValue(outDht1.readHumidity());
  thing["outTemperature"] >> outputValue(outDht1.readTemperature());

  thing["outHumidity"] >> outputValue(outDht2.readHumidity());
  thing["outTemperature"] >> outputValue(outDht2.readTemperature());

  thing["Light"] >> outputValue(analogRead(LIGHTPIN));
  thing["WaterLevel"] >> outputValue(analogRead(WLPIN));
  thing["SoilHumidity"] >> outputValue(analogRead(SHPIN));
*/
  thing["Went"] >> outputValue(digitalRead(2));
  thing["Hot"] >> outputValue(digitalRead(3));
  thing["Pump"] >> outputValue(digitalRead(4));
  thing["Led"] >> outputValue(digitalRead(5));
  thing["ISA"] >> outputValue(digitalRead(ISA));

  

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  /*if (digitalRead(12)==1){
    //Подогрев
    if (dht.readTemperature()<MINTEMP){
      digitalWrite(ISHOT,HIGH);
      digitalWrite(HOTPIN,HIGH);
    }
    else{
      digitalWrite(ISHOT,LOW);
      digitalWrite(HOTPIN,LOW);
    }
    // Автополив
    if (analogRead(SHPIN)>MINSH){
      digitalWrite(ISW,HIGH);
      digitalWrite(WPIN,HIGH);
      delay(WAITFORPUMP*1000);
      digitalWrite(ISW,LOW);
      digitalWrite(WPIN,LOW);
    }
  
    //Освещение
    if (analogRead(LIGHTPIN)>MINLIGHT){
      digitalWrite(ISLED,HIGH);
      digitalWrite(LEDPIN,HIGH);
    
    }
    else{
      digitalWrite(ISLED,LOW);
      digitalWrite(LEDPIN,LOW);
    }
    //Здесь должен быть код по времени

    //Вентиляция
//    if (dht.readHumidity()>MAXHUM && dht.readHumidity()>outDht1.readHumidity() || dht.readTemperature()>MAXTEMP && dht.readTemperature()(outDht1.readTemperature()){
    if (dht.readTemperature()>MAXTEMP){
      digitalWrite(ISW,HIGH);
      digitalWrite(WPIN,HIGH);
    }
    else{
      digitalWrite(ISW,LOW);
      digitalWrite(WPIN,LOW);
    }
    //Здесь должен быть код по времен

    if(analogRead(WLPIN)>MINWL){
      digitalWrite(ISBUZZ,HIGH);
      digitalWrite(BUZZERPIN,HIGH);
    }
    else{
      digitalWrite(ISBUZZ,LOW);
      digitalWrite(BUZZERPIN,LOW);
    }
  }*/
  thing.handle();
}
