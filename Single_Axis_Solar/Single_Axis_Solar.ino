#include <Servo.h> 
 
Servo tracker;         
int eastLDRPin = 0;   
int westLDRPin = 1;
int eastLDR = 0;      
int westLDR = 0;
int error = 0;
int calibration = 204;  
int trackerPos = 90;    
 
void setup() 
{ 
  tracker.attach(11);  
} 
 
 
void loop() 
{ 
  eastLDR = calibration + analogRead(eastLDRPin);    
  westLDR = analogRead(westLDRPin);
  if(eastLDR<350 && westLDR<350)  
  {
    while(trackerPos<=160)  
    {
      trackerPos++;
      tracker.write(trackerPos);
      delay(100);
    }
  }
  error = eastLDR - westLDR;         
  if(error>15)        
  {
    if(trackerPos<=160)  
    {
      trackerPos++;
      tracker.write(trackerPos);  
    }
  }
  else if(error<-15) 
  {
    if(trackerPos>20)  
    {
      trackerPos--;
      tracker.write(trackerPos);  
    }
  }
  delay(100);
} 
