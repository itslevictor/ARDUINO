int inc = 5;

void setup(){
  pinMode(11,OUTPUT); //RED
  pinMode(10,OUTPUT); //GREEN
  pinMode(9,OUTPUT); //BLUE
  
}


void loop(){
  for(int i=0; i<256;i++){
    analogWrite(11,i);
    delay(25);
    }
    analogWrite(11,0);
    for(int i=0; i<256;i++){
    analogWrite(10,i);
    delay(25);
    }
    analogWrite(10,0);
    for(int i=0; i<256;i++){
    analogWrite(9,i);
    delay(25);
    }
    analogWrite(9,0);
  }
