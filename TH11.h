#ifndef TH11
#define TH11

#include "DHT.h"

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int DHTSensingDelay = 2100;
// TODO
// 개발 완료되면 1분으로 해도 문제없을듯

float readTemp();
float readHum();

float readTemp(){
  return dht.readTemperature();
}

float readHum() {
  return dht.readHumidity();
}

#endif