#include<ESP8266WiFi.h>
#include<WiFiUdp.h>

WiFiUDP Udp;

char * ssid = "SudarshanMI";
char * pass = "12345678";
int port = 5655;
char message[50];
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  WiFi.begin(ssid, pass);

    if(WiFi.status() != WL_CONNECTED)
      {
        Serial.println("no onnection");
      delay(100);
      }
     
  
  Serial.println("Connected to wifi ");
  delay(100);
  Serial.println(WiFi.localIP());
  Udp.begin(port);
}

void loop() {
  // put your main code here, to run repeatedly:
  int packetSize = Udp.parsePacket();
  if(packetSize >0 )
   {
    IPAddress obj = Udp.remoteIP();
    int remote = Udp.remotePort();
    Udp.read(message, 10);
    String var = String(message);
    if (var.equals("ON"))
      digitalWrite(13, HIGH);
    else
      digitalWrite(13, LOW);
     for(int i=0;i<10;i++)
     message[i] = "";
   }
   else 
    Serial.println("bogus packet");
   delay(100);
}
