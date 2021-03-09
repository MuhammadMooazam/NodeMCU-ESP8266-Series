#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

String host = "api.thingspeak.com";
int httpPort = 80;  
String url = "/apps/thingtweet/1/statuses/update";

HTTPClient http; 

void setup() 
{
  Serial.begin(9600);
  WiFi.begin("Mooazam", "mooazam123");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  http.begin(host,httpPort,url); 
  String RequestBody = "api_key=DYC0F0ZSCY854UHN&status=I just posted this from my NodeMCU!";
  int httpCode = http.POST(RequestBody);
  Serial.println(httpCode);
  delay(2000);
}

void loop() 
{
  
}
