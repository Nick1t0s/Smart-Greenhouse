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
  pinMode(BUZZERPIN, OUTPUT);

  pinMode(ISW,OUTPUT);
  pinMode(ISHOT,OUTPUT);
  pinMode(ISPUMP,OUTPUT);
  pinMode(ISLED,OUTPUT);

  // pin control example (i.e. turning on/off a light, a relay, etc)
  thing[TEENNAME] << digitalPin(TEENPIN);
  thing[WNAME] << digitalPin(WPIN);
  thing[HOTNAME] << digitalPin(HOTPIN);
  thing[PUMPNAME] << digitalPin(PUMPPIN);
  thing[LEDNAME] << digitalPin(LEDPIN);
  thing["AUTO"] << digitalPin(12);

  // resource output example (i.e. reading a sensor value, a variable, etc)
  thing["Humidity"] >> outputValue(dht.readHumidity());
  thing["Temperature"] >> outputValue(dht.readTemperature());

  thing["outHumidity1"] >> outputValue(outDht1.readHumidity());
  thing["outTemperature"] >> outputValue(outDht1.readTemperature());

  thing["outHumidity"] >> outputValue(outDht2.readHumidity());
  thing["outTemperature"] >> outputValue(outDht2.readTemperature());

  thing["Light"] >> outputValue(analogRead(LIGHTPIN));
  thing["WaterLevel"] >> outputValue(analogRead(WLPIN));
  thing["SoilHumidity"] >> outputValue(analogRead(SHPIN));

  thing["ISW"] >> outputValue(digitalgRead(ISW));
  thing["ISHOT"] >> outputValue(digitalRead(ISHOT));
  thing["ISPUMP"] >> outputValue(digitalRead(ISPUMP));
  thing["ISLED"] >> outputValue(digitalRead(ISLED));

  

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  if (digitalRead(12)==1){
    //Подогрев
    if (dht.readTemperature()<MINTEMP){
      digitalWrite(ISHOT,HIGH);
      dightalWrite(HOTPIN,HIGH);
    }
    else{
      digitalWrite(ISHOT,LOW);
      dightalWrite(HOTPIN,LOW);
    }
    // Автополив
    if (analogRead(SHPIN)>MINSH){
      digitalWrite(ISW,HIGH);
      dightalWrite(WPIN,HIGH);
      delay(WAITFORPUMP*1000);
      digitalWrite(ISW,LOW);
      dightalWrite(WPIN,LOW);
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
    if (dht.readHumidity()>MAXHUM && dht.readHumidity()>(outDht1.readHumidity()+outDht2.readHumidity())/2 || dht.readTemperature()()>MAXTEMP && dht.readTemperature()>(outDht1.readTemperature()+outDht2.readTemperature())/2 ){
      digitalWrite(ISW,HIGH);
      digitalWrite(WPIN,HIGH);
    }
    else{
      digitalWrite(ISW,LOW);
      digitalWrite(WPIN,LOW);
    }
    //Здесь должен быть код по времен

    if(analogRead(WLPIN)>MINWL){
      digitalWrite(ISBUZZ,LOW)
      digitalWrite(BUZZERPIN,HIGH);
    }
    else{
      digitalWrite(ISBUZZ,LOW)
      digitalWrite(BUZZERPIN,LOW);
    }
  }

  thing.handle();
}
