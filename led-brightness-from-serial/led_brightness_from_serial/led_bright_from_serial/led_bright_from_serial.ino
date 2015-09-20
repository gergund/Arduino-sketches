//input LED example from serial
int brightness;
byte bytRead;
int led = 10;


void setup() {                
// Turn the Serial Protocol ON
  Serial.begin(9600);
}

void loop() {
   /*  check if data has been sent from the computer: */
  if (Serial.available()) {
    /* read the most recent byte */
    bytRead = Serial.read();
    
    switch (bytRead) {
    case 'a':    
      brightness = 50;
      break;
    case 'b':    
      brightness = 30;
      break;
    case 'c':    
      brightness = 20;
      break;
    case 'd':    
      brightness = 10;
      break;
    case 'e':    
      brightness = 0;
      break;
    default:
      brightness = 0;
    }  
    Serial.println(brightness);
    
    analogWrite(led, brightness);    
    delay(1);
  }
}
