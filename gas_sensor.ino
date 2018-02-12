int a;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  
  a=analogRead(A0);
  Serial.println(a);
  if(a>=260)
  {
  digitalWrite(13,HIGH);
  }
  else{
  digitalWrite(13,LOW);
  }
  delay(500);
  
  // put your main code here, to run repeatedly:

}
