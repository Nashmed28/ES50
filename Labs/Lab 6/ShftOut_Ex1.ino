//Pin connected to ST_CP of 74HC595
int latchPin = 4;
//Pin connected to SH_CP of 74HC595
int clockPin = 3;
////Pin connected to DS of 74HC595
int dataPin = 2;


void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // writes the number (between 0 and 255) into the shift registrar and displays the binary representation on the LEDs

  numberToDisplay=175l

    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);

    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);  // most significant bit (MSB) goes out first;

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
 
    // pause before next value:
    delay(500);
}
