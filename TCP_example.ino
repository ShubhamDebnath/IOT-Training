#include<ESP8266WiFi.h>
char * ssid = "Redmi";
char * pass = "qwertyuiop";
int led_pin = 4;
#define HIGH 1
#define LOW 0
int value = 0;

WiFiServer server(80); 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
     delay(500);
  }
  Serial.print("Connected to local ip : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();

  if(!client)
    return;

  Serial.println("new client");
  while(!client.available())
    delay(1);

  String message = client.readStringUntil('\r');
  Serial.println(message);
  client.flush();
  if(message.indexOf("/LED=ON") != -1)
  {
     digitalWrite(led_pin, HIGH);
     value = HIGH;
  }

  if(message.indexOf("/LED=OFF") != -1)
  {
     digitalWrite(led_pin, LOW);
     value = LOW;
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type:text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>TEST PAGE</head>");
  
   client.print("<body>pin is now : ");

   if(value == HIGH)
    client.print("ON");
   
   if(value == LOW)
    client.print("OFF");
 
  client.println("<a href=\"LED=ON\"\"><button> Turn On </button></a>");
  client.println("<a href=\"LED=OFF\"\"><button> Turn Off </button></a>");
  client.println("</body></html>");

  Serial.println("client disconnected ");
  delay(1);

}
