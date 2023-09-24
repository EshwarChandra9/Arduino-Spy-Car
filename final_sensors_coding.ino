int x=0;
int sensorPin=0;
long duration=0;
int distance=0;
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
}
void loop()
{
x=digitalRead(2);
  if(x==HIGH)
  {
     Serial.println("Motion Detected");
  }
else
  {
     Serial.println("No Motions are present");
  }
      digitalWrite(10, LOW);
       delayMicroseconds(2);
    digitalWrite(10, HIGH);
      delayMicroseconds(10);
    digitalWrite(10, LOW);
      duration = pulseIn(9, HIGH);
    distance= duration*0.034/2;
    Serial.print("Distance: ");
    Serial.println(distance);
       if(distance >120 && distance<140)
        {
          Serial.println("We can move forward,there is no obstacle");
           delay(1000);
        }
        else
        {
          Serial.println("We cannot move forward,there is an obstacle");
          delay(1000);
        }
  int reading=analogRead(A0);
  float voltage=reading*5.0;
  voltage/=1024.0;
  Serial.print(voltage);
  Serial.println("Volts");
  float temperatureC=(voltage-0.5)*100;
  Serial.print(temperatureC);
  Serial.println("degrees C");
  delay(1000);
  if (temperatureC>-50 && temperatureC<=30)
  {
    Serial.println("There is a cool and moderate temperature");
  }
  else if(temperatureC>70)
  {
    Serial.println("There is hot temperature");
  }
}
