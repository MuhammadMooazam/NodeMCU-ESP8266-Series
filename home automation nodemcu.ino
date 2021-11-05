////*************************************************************
//  Download latest Blynk library here:
//    https://github.com/blynkkk/blynk-library/releases/latest
//
//  Blynk is a platform with iOS and Android apps to control
//  Arduino, Raspberry Pi and the likes over the Internet.
//  You can easily build graphic interfaces for all your
//  projects by simply dragging and dropping widgets.
//
//    Downloads, docs, tutorials: http://www.blynk.cc
//    Sketch generator:           http://examples.blynk.cc
//    Blynk community:            http://community.blynk.cc
//    Social networks:            http://www.fb.com/blynkapp
//                                http://twitter.com/blynk_app
//
//  This example code is in public domain.
//***********************************************************************
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "2umVnTL7kB3NK82mpK4BaQ-mNpiCTmJk"; // the auth code that you got on your gmail
char ssid[] = "Dreamnet (( Mooazam ))"; // username or ssid of your WI-FI
char pass[] = "Arham123"; // password of your Wi-Fi

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D1,OUTPUT); //extend these to D8 if you are using a 8 pin relay 
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);

  digitalWrite(D1,HIGH); // Make it low if you want everything to go off 
  digitalWrite(D2,HIGH); // in case of a power cut
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
  
  

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
