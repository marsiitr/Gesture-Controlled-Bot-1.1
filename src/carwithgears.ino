#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>
int p1[5] = {0, 699, 799, 899, 999};
//speed levels are distributed such that their for both wheels on same ith gear will move on straight line 
 
int p2[5] = {0, 640, 740, 840, 940};
char ssid[] = "ssid name ";//both esp should be connected to same network 
char pass[] = "password";
int v1 = LOW;
int v2 = LOW;
int v3 = LOW;
int v4 = LOW;
ESP8266WebServer server(80);
void gearon() {
  Serial.println("h");
  String gr = server.arg("p");
  server.send(200, "text/plain", "This is response to client");
  Serial.println(gr);
  int g1 = (int)gr.charAt(0) - 48;
  int g2 = (int)gr.charAt(1) - 48;
  v1 = g1 > 4 ? 0 : 1;
  v2 = 1 - v1;
  v3 = g2 > 4 ? 0 : 1;
  v4 = 1 - v3;
  if (g1 == 0) {
    v1 = 0;
    v2 = 0;
  }
  if (g2 == 0) {
    v3 = 0;
    v4 = 0;
  }

  Serial.println((String)g1 + "+" + (String)g2);
  Serial.println(p1[!(g1 == 4 || g1 == 8) ? (g1 % 4) : 4]);
  Serial.println(p1[!(g2 == 4 || g2 == 8) ? (g2 % 4) : 4]);
  analogWrite(D0, p1[!(g1 == 4 || g1 == 8) ? (g1 % 4) : 4]);
  analogWrite(D1, p1[!(g2 == 4 || g2 == 8) ? (g2 % 4) : 4]);
  digitalWrite(D2, v1);
  digitalWrite(D3, v2);
  digitalWrite(D4, v3);
  digitalWrite(D5, v4);
}
void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.println(WiFi.status());
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  server.on("/hold", gearon);
  server.begin();
}
void loop() {
  server.handleClient();
}
