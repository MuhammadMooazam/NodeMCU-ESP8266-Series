#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  WiFi.begin("Mooazam", "mooazam123");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("..");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected!");
  Serial.println(WiFi.localIP());
  
}

void loop() {
}
