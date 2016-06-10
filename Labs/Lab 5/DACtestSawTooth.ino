// this sketch generates sawtooth signal
// the idea is simple: we count from 0 to 2^M-1, where M is the size of
// the quantizer, and then output each of M bits to their corresponding
// digital outputs.
//NOTE: since our D/A converter hardware can handle only 6 bits for now, 
// M has to be smaller or equal to 6 (0<M<=6)

int del= 1;  // delay in milliseconds   
int M=6;      // the size of the quantizer, in bits.
int Max_number=pow(2,M)-1; // the max number that can be represented with M bits
int f=0;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(0, OUTPUT);  
  pinMode(1, OUTPUT);  
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {

  for (int f=0; f<=Max_number; f++){   // f counts from 0 to 2^M-1
 
// next, we output the binary representation of number f
//  to outputs D5 D4 D3 D2 D1 D0 of Arduino
// D/A converter will then convert these digital numbers back to 
// their decimal value.

   digitalWrite(5,bitRead(f,5));  //5th bit of f goes to D5
   digitalWrite(4,bitRead(f,4));  //4th bit of f goes to D4 
   digitalWrite(3,bitRead(f,3));  //3rd bit of f goes to D3
   digitalWrite(2,bitRead(f,2));  //2nd bit of f goes to D2 
   digitalWrite(1,bitRead(f,1));  //1st bit of f goes to D1
   digitalWrite(0,bitRead(f,0));  //0th bit of f goes to D0 

  }
   
}


