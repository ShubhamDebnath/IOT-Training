#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int led;
const char* ssid = "Santu";        
const char* pass = "7001968842";
const char* mqtt_server = "iot.iandwe.in";
//WiFiServer server(80);
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
 pinMode(BUILTIN_LED, OUTPUT);
 Serial.begin(115200);
 void setup_wifi();
 client.setServer(mqtt_server, 1883);
 client.setCallback(callback); 
}

void setup_wifi(){
 Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  //server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  
  //server.begin();                         // starts the server
// Serial.println("Connected to wifi");
//  Serial.print("Status: "); Serial.println(WiFi.status());  // some parameters from the network
//  Serial.print("IP: ");     Serial.println(WiFi.localIP());
//  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
//  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
//  Serial.print("SSID: "); Serial.println(WiFi.SSID());
//  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
//  Serial.print("Networks: "); Serial.println(WiFi.scanNetworks());
  pinMode(led, OUTPUT);

}
// callback: a pointer to a message callback funtion called when a meassage
// for
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Msg Arrived [");
  Serial.print(topic);
  Serial.print("]");
  for (int i=1; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  // Switch on the led if a i was recieved as first charecter
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, HIGH);
  }
}
void reconnect() {
while (!client.connected()) {
  Serial.print("Attempting MQTT Connection...");
  if (client.connect("ESP8266Client")) {
    Serial.println("Connected");
    // Once connected , pulish a annuncement
    client.publish("santarpan/sit", "Hello World");
    // ... and resubscribe
    client.subscribe("santarpan/sit");
   }  else {
    Serial.print("Faild, re=");
    Serial.print(client.state());
    Serial.println("Try again in 5 Second");
    // wait 5 sec
    delay(5000); 
  }
 }
}

void loop() {

   if (!client.connected()) {
      reconnect();
   }
   client.loop();
//   long now = millis();
//   if (now - lastMsg >2000) {
//    lastMsg = now;
//    ++value;
      //snprintf

    snprintf (msg, 75, "hello world %1d", value);
    Serial.print("Publish Message: ");
    Serial.println(msg);
    client.publish("santarpan/sit", msg);
}
