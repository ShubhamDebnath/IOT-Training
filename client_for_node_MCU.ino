#include <WiFiManager.h>
#include <SPI.h>
#include <ESP8266WiFi.h>

int led = D4;
//char ssid[] = "HTTPS";           // SSID of your home WiFi
//char pass[] = "kuchbhiiee";            // password of your home WiFi

//unsigned long askTimer = 0;

IPAddress server(192,168,0,7);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);               // only for debug
 // Connect to WiFi network
  //Serial.println();
  //Serial.println();
  //Serial.print("Connecting to ");
 // Serial.println(ssid);
 
  //WiFi.begin(ssid, pass);
 
  //while (WiFi.status() != WL_CONNECTED) {
   // delay(500);
   // Serial.print(".");
  //}
  //Serial.println("");
  //Serial.println("WiFi connected");
  
  pinMode(led, OUTPUT);
  WiFiManager wifimanager;
  wifimanager.autoConnect("NodeMCU");  
}

void loop () {
  client.connect(server, 80);   // Connection to the server
  digitalWrite(led, LOW);    // to show the communication only (inverted logic)
  Serial.println(".");
  Serial.println("Hello server! Are you sleeping?\r");  // sends the message to the server
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: ");
  Serial.println(answer);
  client.flush();
  digitalWrite(led, HIGH);
  delay(1000);                  // client will trigger the communication after ome seconds
}
