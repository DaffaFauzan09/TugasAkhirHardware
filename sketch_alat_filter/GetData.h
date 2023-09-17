//Variabel String
String phDataString, ppmDataString, suhuairDataString, suhuudaraDataString, NTUDataString;

void GetData() {
  //Data sensor
  voltage_pH = analogRead(PH_PIN) / ESPADC * ESPVOLTAGE;
  phData = ph.readPH(voltage_pH, suhuair)+2.0;
  //phData = slope*(voltage_pH-1500)/3.0+intercept;
  suhuudara = sensorUdara.getTempCByIndex(0);
  suhuair = sensorAir.getTempCByIndex(0);
  ppmData = gravityTds.getTdsValue()+40;
  ADCtur = analogRead(tur_pin);
  voltagetur = (ADCtur * 3.3 / 4095);
  tur = ((-565.61 * ( voltagetur * voltagetur)) + (1006.8 * voltagetur) + 2837.1); 
    
  //Convert to String
  phDataString = String(phData);
  ppmDataString = String(ppmData);
  suhuudaraDataString = String(suhuudara);
  suhuairDataString = String(suhuair);
  NTUDataString = String(tur); 

  
}
