#include "global.h"
#include "GetData.h"
#include "connectWifi.h"
#include "postHttptds.h"
#include "postHttpph.h"
#include "postHttpturbidity.h"
#include "postHttpsuhuudara.h"
#include "postHttpsuhuair.h"

unsigned long ltsend, ltacq, ltkirim;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  EEPROM.begin(32);
  //pinMode(PH_PIN, INPUT);
  ph.begin();
  sensorAir.begin();
  sensorUdara.begin();
  pinMode(tur_pin,INPUT);
  gravityTds.setPin(TdsSensorPin);
  gravityTds.setAref(3.3);  //reference voltage on ADC, default 5.0V on Arduino UNO
  gravityTds.setAdcRange(4096);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.begin();  //initialization
  connectWifi();
 /* Serial.print("voltagepH:");
  Serial.println(voltage_pH, 4);
  Serial.print("temperatureph:");
  Serial.print(temperatureph, 1);
  Serial.println("ºC");
  Serial.print("pH:");
  Serial.println(phData, 4);
  Serial.println(voltagetur);
  Serial.print("Temperature: ");
  Serial.print(suhuudara);
  Serial.println("ºC");
  Serial.print(suhuair);
  Serial.println("ºC"); */
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-ltacq>5) {
    GetData();
    ltacq = millis();
    sensorUdara.requestTemperatures();
    sensorAir.requestTemperatures();
    gravityTds.setTemperature(suhuair);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate
  }
  
  if(millis()-ltkirim>3000) {
    postHttptds();
    postHttpph();
    postHttpturbidity();
    postHttpsuhuudara();
    postHttpsuhuair();
    ltkirim = millis();
  }
  ph.calibration(voltage_pH, suhuair); // calibration process by Serial CMD
}
