int IN1 = 3;
int IN2 = 5;
int IN3 = 6; 
int IN4 = 9;

void setup()
{
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
}
void loop()
{
  int i = 225;


  //forward
  for(i = 225; i <= 255; ++i)
  {
      analogWrite(IN2, i);
      analogWrite(IN3, i);
      delay(30);
  }
  delay(5000);
  
  //stop
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  delay(1000);
  
  //reverse
  for(i = 225; i <= 255; ++i)
  {
      analogWrite(IN1, i);
      analogWrite(IN4, i);
      delay(30);
  }
  delay(5000);
  
  //stop
  analogWrite(IN1, 0);
  analogWrite(IN4, 0);
  delay(1000);
  
  //rotate-right
  for(i = 225; i <= 255; ++i)
  {
      analogWrite(IN2, i);
      analogWrite(IN4, i);
      delay(30);
  }
  delay(5000);
  
  //stop
  analogWrite(IN2, 0);
  analogWrite(IN4, 0);
  delay(1000);
  
  //rotate-left
  for(i = 225; i <= 255; ++i)
  {
      analogWrite(IN1, i);
      analogWrite(IN3, i);
      delay(30);
  }
  delay(5000);
  
  analogWrite(IN1, 0);
  analogWrite(IN3, 0);
  delay(1000);

}

