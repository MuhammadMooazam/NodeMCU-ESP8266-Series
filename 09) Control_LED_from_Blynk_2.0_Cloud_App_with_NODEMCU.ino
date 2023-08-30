#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6qU6tJ-t2"
#define BLYNK_TEMPLATE_NAME "ESP8266Testing"
#define BLYNK_AUTH_TOKEN "uJJbIo1oWHhEP2TM65Ek1BkuVjNkmlVW"

#define LED_PIN D5

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Mooazam";
char pass[] = "mooazam123";

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  Blynk.run();
}

// Blynk button widget callback
BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(LED_PIN, value);
  Serial.println("Value of LED V0 is " + String(value));
}
