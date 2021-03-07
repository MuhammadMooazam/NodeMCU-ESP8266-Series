#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define led D5

void setup() 
{
  // put your setup code here, to run once:
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
  server.begin();
  pinMode(led, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.    
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledon HTTP/1.1")
    {
      digitalWrite(led, HIGH);
      Serial.println("LED is ON");
    }
    if(request == "GET /ledoff HTTP/1.1")
    {
      digitalWrite(led, LOW);
      Serial.println("LED is OFF");
    }
  }
}
