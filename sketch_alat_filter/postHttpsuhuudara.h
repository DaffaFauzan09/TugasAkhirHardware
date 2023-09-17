#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpsuhuudara() {
  Serial.println("Posting suhu udara Data...");
  String url = "http://192.168.43.83:8080/suhuudara/add";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  buff["suhuudara"] = suhuudaraDataString.toFloat();
  
  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  String data = "suhuudara=" + String(suhuudaraDataString.toFloat());
  Serial.println(data);


  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int statusCode = http.POST(data);
  response = http.getString();
  Serial.println(response);
}
