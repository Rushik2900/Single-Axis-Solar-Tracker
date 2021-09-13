#include <Servo.h> 
 
Servo tracker;         //Create servo object to control a servo 
int eastLDRPin = 0;    //Assigning analogue pins
int westLDRPin = 1;
int eastLDR = 0;       //Variables for the east and west sensor values
int westLDR = 0;
int error = 0;
int calibration = 204;  //Calibration offset to set error to zero when both sensors receive an equal amount of light
int trackerPos = 90;    //Variable to store the servo position
 
void setup() 
{ 
  tracker.attach(11);   // attaches the servo on pin 11 to the servo object
} 
 
 
void loop() 
{ 
  eastLDR = calibration + analogRead(eastLDRPin);    //Read the value of each of the east and west sensors
  westLDR = analogRead(westLDRPin);
  if(eastLDR<350 && westLDR<350)        //Check if both sensors detect light
  {
    while(trackerPos<=160)      //Move the tracker to face sunlight
    {
      trackerPos++;
      tracker.write(trackerPos);
      delay(100);
    }
  }
  error = eastLDR - westLDR;       //Determine the difference between the two sensors.
  if(error>15)                     //If the error is positive and greater than 15 then move the tracker in the east direction
  {
    if(trackerPos<=160)  
    {
      trackerPos++;
      tracker.write(trackerPos);   //Move the tracker to the east
    }
  }
  else if(error<-15)               //If the error is negative and less than -15 then move the tracker in the west direction
  {
    if(trackerPos>20)  
    {
      trackerPos--;
      tracker.write(trackerPos);   //Move the tracker to the west
    }
  }
  delay(100);
} 
