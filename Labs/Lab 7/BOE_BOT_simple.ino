/*
 *Basic Code to Test Functionality of the BOEBOT Servos
 *ES50 Lab 4 
 *Jason Smith and Demetrio Anaya 
 */
 
#include <Servo.h>                           // Include servo library
 
Servo servoLeft;                             // Declare left and right servos
Servo servoRight;
 
void setup()                                 // Built-in initialization block

{                             
  servoLeft.attach(11);                      // Attach left signal to pin 11
  servoRight.attach(12);                     // Attach right signal to pin 12
   Serial.begin(9600);
}  
 
void loop()                                  // Main loop auto-repeats
{

  maneuver(200,200,60);                      // Drive Straight
  
}


void maneuver(int speedLeft, int speedRight, int msTime) // Defines maneuver function
{
  // speedLeft, speedRight ranges: Backward  Linear  Stop  Linear   Forward
  //                               -200      -100......0......100       200
  servoLeft.writeMicroseconds(1500 + speedLeft);   // Set Left servo speed
  servoRight.writeMicroseconds(1500 - speedRight); // Set right servo speed
  if(msTime==-1)                                   // if msTime = -1
  {                                  
    servoLeft.detach();                            // Stop servo signals
    servoRight.detach();   
  }
  delay(msTime);                                   // Delay for msTime
}


