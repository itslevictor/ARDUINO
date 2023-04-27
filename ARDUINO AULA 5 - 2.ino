void setup(){
  Serial.begin(9600); 
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(13, 1);
}


void loop(){ 
  if(Serial.available() > 0){
    int rN = Serial.readStringUntil('R').toInt();
    Serial.println(rN);
    analogWrite(11, rN);
    int gN = Serial.readStringUntil('G').toInt();
    Serial.println(gN);
    analogWrite(10, gN);
    int bN = Serial.readStringUntil('B').toInt();
    Serial.println(bN);
    analogWrite(9, bN);
    delay(100);
  }
}
