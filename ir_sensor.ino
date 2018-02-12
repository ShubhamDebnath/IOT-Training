int a;
void setup() {
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //digitalWrite(13,HIGH);
  a=analogRead(A0);
  Serial.println(a);
  delay(500);

}
