#include <DFRobot_ESP_PH_WITH_ADC.h>
#include <EEPROM.h>
#include <GravityTDS.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#define VREF 3.3
#define SCOUNT  30
#define TdsSensorPin 36
GravityTDS gravityTds ;
DFRobot_ESP_PH_WITH_ADC ph;
#define ESPADC 4096.0   //the esp Analog Digital Convertion value
#define ESPVOLTAGE 3300 //the esp voltage supply value
#define PH_PIN 39    //the esp gpio data pin number
OneWire oneWire1(32);
DallasTemperature sensorAir(&oneWire1);
OneWire oneWire2(33);
DallasTemperature sensorUdara(&oneWire2);
float voltage_pH, phData;
/*float acidVoltage = 1864;
float neutralVoltage = 1400;
float slope = (7.0-4.0)/((neutralVoltage-1500)/3.0 - (acidVoltage-1500)/3.0);
float intercept = 7.0 - slope*(neutralVoltage-1500)/3.0;*/
float tempC, suhuudara;
const int tur_pin = 35;
double ADCtur, voltagetur, tur;
float suhuair, ppmData;
