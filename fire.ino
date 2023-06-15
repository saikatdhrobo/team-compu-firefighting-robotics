//*------ Arduino Fire Fighting Robot ver 2.0 Code by hobby project---- */
 
#include <Servo.h>            //include servo.h library
#include <SoftwareSerial.h>  //include SoftwareSerial.h library


 
int pos = 0;    
boolean fire = false;

char val;



#define Left 9          // left sensor
#define Right 11         // right sensor
#define Forward 10       //front sensor

#define LM1 2           // left motor
#define LM2 3           // left motor
#define RM1 4          // right motor
#define RM2 5          // right motor
#define pump 7        //water pumb

int duration = 0;
int distance = 0;

const int trig = 12;
const int echo = 13;

void setup()
{
   
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);

  
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
 
  pinMode(6, OUTPUT); 


  

  Serial.begin(9600);
}
 
void put_off_fire()
{
  
 
 
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);

 
   digitalWrite(pump, HIGH); 
   delay(500); 

  digitalWrite(pump,LOW);

  fire=false;
}
 
void loop()
{

  
 
  
  if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1) 
    {
    
     while (Serial.available() > 0)
   {
   val = Serial.read();
   Serial.println(val);
   }

  if( val == 'F') // Forward
    {  
         analogWrite(6, 500);

     digitalWrite(LM1, LOW);
     digitalWrite(LM2, HIGH);
     digitalWrite(RM1, LOW);
     digitalWrite(RM2, HIGH);  
    }
   else if(val == 'B') // Backward
     {
      analogWrite(6, 500);

     digitalWrite(LM1, HIGH);
     digitalWrite(LM2, LOW);
     digitalWrite(RM1, HIGH);
     digitalWrite(RM2, LOW); 
    }
  
   else if(val == 'L') //Left
    {
      analogWrite(6, 500);

     digitalWrite(LM1, LOW);
     digitalWrite(LM2, HIGH);
     digitalWrite(RM1, HIGH);
     digitalWrite(RM2, LOW);
    }
    else if(val == 'R') //Right
    {
     analogWrite(6, 500);

     digitalWrite(LM1, HIGH);
     digitalWrite(LM2, LOW);
     digitalWrite(RM1, LOW);
     digitalWrite(RM2, HIGH); 
    }


  else if(val == 'S') //Stop
  {

      digitalWrite(trig , HIGH);
      delayMicroseconds(1000);
      digitalWrite(trig , LOW);


      duration = pulseIn(echo , HIGH);
      distance = (duration/2) / 28.5 ;
      Serial.println(distance);


    
     if ( distance < 25 )
     {
      
          analogWrite(6, 0); 

       digitalWrite(LM1, LOW);
       digitalWrite(LM2, LOW);
       digitalWrite(RM1, LOW);
       digitalWrite(RM2, LOW);

       delay(100);

          analogWrite(6, 300); 

       digitalWrite(LM1, LOW);
       digitalWrite(LM2, HIGH);
       digitalWrite(RM1, HIGH);
       digitalWrite(RM2, LOW);

       delay(100);
     }

     else
     {
         analogWrite(6, 200);

       digitalWrite(LM1, LOW);
       digitalWrite(LM2, HIGH);
       digitalWrite(RM1, LOW);
       digitalWrite(RM2, HIGH);
       }
     
  }
      else if(val == 'G' || 'I' || 'H' ||  'J'    ) 
     {
         analogWrite(6, 0);
      
       digitalWrite(LM1, LOW);
       digitalWrite(LM2, LOW);
       digitalWrite(RM1, LOW);
       digitalWrite(RM2, LOW);

      }
   }
  
    else if (digitalRead(Forward) ==0) 
    {
    analogWrite(6, 500);
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    fire = true;
    
    }
    
    else if (digitalRead(Left) ==0)
    {
    analogWrite(6, 230); 

    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);

    }
    
    else if (digitalRead(Right) ==0) 
    {
    analogWrite(6, 230); 

    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);




    }
    delay(50);//change this value to change the distance
      if (fire == true)
   {
     put_off_fire();
    }
  }