// written by Marko Loncar, 10/13/2014
int latchPin = 4;
int clockPin = 3;
int dataPin = 2;

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for(int wait=150; wait>0; wait=wait-10){
  LED(8,1,1, wait);
  LED(8,128,0,wait);
  }
}
// function LED has inputs
// number - how many LEDs is there (works for <=8 for now, it would be easy fix to expand to more
// start - specify what number is written in first, and then is shifted by one bit left or right depending on the status of
// left=1, means shift bits left, left=0, shifts bits right
// wait - specifies the delay

void LED(int number, int start, int left, int hold){
  byte temp=start;
    for (int cc=0; cc<number; cc++){
     digitalWrite(latchPin, LOW);    // the LEDs don't change while you're sending in bits:  
    shiftOut(dataPin, clockPin, MSBFIRST, temp);  // most significant bit (MSB) goes out first;
    digitalWrite(latchPin, HIGH);
    delay(hold);
    if (left==1)
      {temp=temp<<1;}  // shifts bit in a byte one spot to the left 
    else 
      {temp=temp>>1;}  // shifts bit in a byte one spot to the right


  }
}
    
