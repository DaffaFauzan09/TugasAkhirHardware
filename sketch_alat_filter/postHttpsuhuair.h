#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpsuhuair() {
  Serial.println("Posting suhu air Data...");
  String url = "http://192.168.43.83:8080/suhuair/add";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  buff["suhuair"] = suhuairDataString.toFloat();
  
  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  String data = "suhuair=" + String(suhuairDataString.toFloat());
  Serial.println(data);


  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int statusCode = http.POST(data);
  response = http.getString();
  Serial.println(response);
}
