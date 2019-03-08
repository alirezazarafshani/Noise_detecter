
int avg(int analogpin, int delaytime, int ledpin){ 
  if(ledpin != NULL){pinMode(ledpin,OUTPUT);digitalWrite(ledpin,1);}
  int avg= analogRead(analogpin);
  delay(delaytime/2);
  avg+= analogRead(analogpin);
  delay(delaytime/2);
  avg+= analogRead(analogpin);
  avg/=3;
  digitalWrite(ledpin,0);
  return(avg);
  
  }

void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
}

void loop() {
  
  static bool inputflag=0;
  static int sensevity = 0;
  static int analogpin = A0;
  static int mid = avg(analogpin,0,7);
  
  if ((mid+sensevity) < analogRead(A0)){digitalWrite(9,1);digitalWrite(8,0);Serial.println("Noise");delay(1000);}
  else {digitalWrite(9,0);digitalWrite(8,1);}

  if(inputflag == 0){
 
    inputflag=1;
    if(!digitalRead(2)){digitalWrite(8,0);digitalWrite(9,0);mid = avg(analogpin,1000,7);}
    if(!digitalRead(3)){if( sensevity < 6){sensevity++;} else {sensevity = 0 ;} }
    
    }


  
  if (inputflag == 1 && ( digitalRead(2)== 1 && digitalRead(3)== 1 && digitalRead(6)== 1 ) ){inputflag = 0;}
  
  
  
  

}
