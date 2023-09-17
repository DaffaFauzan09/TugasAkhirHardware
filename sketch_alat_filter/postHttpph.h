#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpph() {
  Serial.println("Posting pH Data...");
  String url = "http://192.168.43.83:8080/ph/add";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  buff["pH"] = phDataString.toFloat();
  
  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);


  String data = "ph=" + String(phDataString.toFloat());
  Serial.println(data);

  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int statusCode = http.POST(data);
  response = http.getString();
  Serial.println(response);
}
