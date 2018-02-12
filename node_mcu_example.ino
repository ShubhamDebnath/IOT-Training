void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(100);
  int w = analogRead(A0);
  digitalWrite(13,HIGH);
  Serial.println(w);
  delay(100);
  digitalWrite(13,LOW);
  
}


