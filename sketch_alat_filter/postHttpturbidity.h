#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpturbidity() {
  Serial.println("Posting turbidity Data...");
  String url = "http://192.168.43.83:8080/turbidity/add";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  buff["NTU"] = NTUDataString.toFloat();
  
  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  String data = "ntu=" + String(NTUDataString.toFloat());
  Serial.println(data);

  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int statusCode = http.POST(data);
  response = http.getString();
  Serial.println(response);
}
