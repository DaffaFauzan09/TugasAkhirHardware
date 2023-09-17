#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttptds() {
  Serial.println("Posting TDS Data...");
  String url = "http://192.168.43.83:8080/tds/add";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  //Convert String data to Float
  buff["ppm"] = ppmDataString.toFloat();

  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  String data = "tds=" + String(ppmDataString.toFloat());
  Serial.println(data);

  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int statusCode = http.POST(data);
  response = http.getString();
  Serial.println(response);
}
