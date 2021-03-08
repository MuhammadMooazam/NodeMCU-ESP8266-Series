#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>

DHT dht(D5, DHT11);

String host = "api.thingspeak.com";
int httpPort = 80;  
String url1 = "/update?api_key=MPPEO58HRZWRRUG9&field1=";
String url2 = "/update?api_key=MPPEO58HRZWRRUG9&field2=";

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
  dht.begin();
}

void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);

  url1 = url1 + (String) t;
  http.begin(host,httpPort,url1); 
  int httpCode = http.GET();
  Serial.println(httpCode);
  delay(2000);

  url2 = url2 + (String) h;
  http.begin(host,httpPort,url2); 
  httpCode = http.GET();
  Serial.println(httpCode);
  delay(2000);
}
