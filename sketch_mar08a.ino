
int avg(int analogpin, int delaytime){ 
  
  int avg= analogRead(analogpin);
  delay(delaytime);
  avg+= analogRead(analogpin);
  avg/=2;
  return(avg);
  
  }

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int sensevity = 4;
  static int analogpin = A0;
  static int mid =avg(analogpin,1000);
  if ((mid+sensevity) < analogRead(A0)){Serial.println("shut up");delay(500);}
   
  
  
  

}
