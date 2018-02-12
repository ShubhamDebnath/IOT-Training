void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 255;
  analogWrite(A0, i);
  i = i- 20;
  delay(100);
  i = (i<0?255:0);
}
