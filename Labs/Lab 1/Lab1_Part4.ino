/*

PHOTO RESISTOR or PRESSURE SENSOR

  Use a photoresistor (light sensor) or pressure sensitive resistor to control
  the brightness of a LED.

*/


// we'll create constants to name the pins we're using.
// This will make it easier to follow the code below.

const int sensorPin = 0;
const int ledPin = 9;  // pin 9 is capable of pulse-width modulation (PWM)

// We'll also set up some global variables for the sensor level:

int sensorLevel, high = 0, low = 1023;

  
void setup()
{
  // We'll set up the LED pin to be an output.
  // (We don't need to do anything special to use the analog input.)
  
  pinMode(ledPin, OUTPUT);

//  Serial.begin(9600);    // if needed, you can use Serial monitor to monitor 
                          //  the values read by the sensors
}


void loop()
{
  // we'll use the analogRead() function to measure the voltage 
  // coming from the voltage divider formed by our sensor (photoresistor or
  // pressure sensor) and 10kOhm resistor;
  // This number can range between 0 (0 Volts) and
  // 1023 (5 Volts), but in our case,  will have a smaller range determined by 
  // the resistor values - you calculated this  already :).

  sensorLevel = analogRead(sensorPin);


  // We now want to use this number to control the brightness of
  // the LED. But we have a problem: the analogRead() function
  // returns values between 0 and 1023, and the analogWrite()
  // function wants values from 0 to 255 - used for PWM.

  // We can solve this by using two handy functions called map()
  // and constrain(). Map will change one range of values into
  // another range. If we tell map() our "from" range is 0-1023,
  // and our "to" range is 0-255, map() will squeeze the larger
  // range into the smaller. (It can do this for any two ranges.)
  // in our case, minimum voltage value is approx 2V (with photocell covered)
  // as determined by voltage divider resistance values. Therefore, we will
  // map our levels as follows (this was determined empirically!) 
  
  sensorLevel = map(sensorLevel, 500, 1023, 0, 255);
 
  // Because map() could still return numbers outside the "to" 
  // range, (if they're outside the "from" range), we'll also use
  // a function called constrain() that will "clip" numbers into
  // a given range. If the number is above the range, it will reset
  // it to be the highest number in the range. If the number is
  // below the range, it will reset it to the lowest number.
  // If the number is within the range, it will stay the same.
  
  sensorLevel = constrain(sensorLevel, 0, 255);
  
 
// Serial.println(sensorLevel);  // you can use this to print  the values
                                // read by the sensor, if needed. This is very useful
                                // during the debugging. In fact, we used this commend after
                                // analogRead to figure out the sensor values. 
                                //If you want to use this feature, you need to uncomment 
                                // Serial.begin command in setup(),  as well as 
                                // open serial monitor (under Tools tab)
                                
  
  // Now we can adjust the brightness of the LED:

  analogWrite(ledPin, sensorLevel);
  
  // The above statement will brighten the LED along with the
  // light level. To do the opposite, replace "lightLevel" in the
  // above analogWrite() statement with "255-lightLevel".
  // Now you've created a night-light!
}




