//4wd robot chassi control by serial

int IN1 = 3; //-----------------|
             //                 |---left motors = l_motors
int IN2 = 5; //-----------------|

int IN3 = 6; //-----------------|
             //                 |---right motors = r_motors
int IN4 = 9; //-----------------|

////DEFINE CONST
const int MAX = 235;  
const int MIN = 200;
const int pwm_run_step = 1;

///
boolean l_moving = false;
boolean r_moving = false;

void l_stop(){
            analogWrite(IN3, 0);
            analogWrite(IN4, 0);
}
void r_stop(){
            analogWrite(IN2, 0);
            analogWrite(IN1, 0);
}

void r_motors(boolean direct)
        {
          if (r_moving == true){
              r_stop();
              r_moving=false;
              r_motors(direct);
          } 
          else{
              for(int i = MAX; i >= MIN; --i)
              {
               if(direct)
                { 
                 analogWrite(IN2, i);
                }
                 else
                {
                 analogWrite(IN1, i);
                }
                
                delay(pwm_run_step);
                r_moving = true;
              }
          }  
        }
         
void l_motors(boolean direct)
        {
          if (l_moving == true){
              l_stop();
              l_moving=false;
              l_motors(direct);
          }
          else{
            for(int i = MAX; i >= MIN; --i)
            {
             if(direct)
              { 
               analogWrite(IN3, i);
              }
             else
              {
               analogWrite(IN4, i);
              }
              
             delay(pwm_run_step);
             l_moving = true;
            }
          }
        }  
        
void all_stop()
{
  l_stop();
  r_stop();
}

void setup()
{
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
 
 Serial.begin(9600);
}
void loop()
{
  int i;
  char val;
  while(Serial.available())
  {
    val = Serial.read(); 
    if(val!=-1)
       {
          switch(val)
           {
             case 'w'://Move ahead
                        r_motors(true);  
                        l_motors(true);  
                         break;
             case 'x'://move back
                        r_motors(false);  
                        l_motors(false);  
                         break;
             case 'a'://turn left
                        r_motors(false);  
                        l_motors(true);  
                         break;       
             case 'd'://turn right
                        r_motors(true);  
                        l_motors(false);  
                        break;   
             case 's'://stop
                        all_stop();
                        break;
                                   
           }     
         
       }
            
  }     
}
 
