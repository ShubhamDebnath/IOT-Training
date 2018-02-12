void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  light();
}

void loop()
{
}

void light()
{
  int i = 255;
  while(1)
  {
    analogWrite(2, i);
    i = ((i == 0)?255 : 0);
    delay(166);
  }
}
