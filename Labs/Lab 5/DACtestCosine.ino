// this sketch generates digital numbers that correspond to sampled and quantized
// values of the function f=1/2*(1+cos(2*pi*f*t)  

int M=6;     // the size of the quantizer, in bits.
int N=100;   // number of samples that function is calculated in 

float c1=(pow(2,M)-1)/2;  // constants needed to calculate cosine 
float c2=2*3.14/N;        // constants needed to calculate cosine 
int f;                    // quantized sample value 

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
for (int n=0; n<=N-1; n++){
  f=round(c1*(1+cos(c2*n)));  // quantized sample value
  digitalWrite(5,bitRead(f,5));  //5th bit of f goes to D5
  digitalWrite(4,bitRead(f,4));  //4th bit of f goes to D4 
  digitalWrite(3,bitRead(f,3));  //3rd bit of f goes to D3
  digitalWrite(2,bitRead(f,2));  //2nd bit of f goes to D2 
  digitalWrite(1,bitRead(f,1));  //1st bit of f goes to D1
  digitalWrite(0,bitRead(f,0));  //0th bit of f goes to D0 
  }
   
}


