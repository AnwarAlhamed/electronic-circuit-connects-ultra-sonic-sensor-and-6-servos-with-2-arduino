void setup()
{
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0){
  if(Serial.read() == '1')
    digitalWrite(10, HIGH);
    delay(3000);
    digitalWrite(10, LOW);
  }
}