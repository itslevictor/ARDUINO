void setup(){
  Serial.begin(9600);
  pinMode(9,  OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, 1);
}

void loop() {

   /* analogWrite(9, 230);
    delay(1000); 
    analogWrite(9, 255);
    analogWrite(10, 230);
    analogWrite(10, 255);
    delay(1000);*/ 
    analogWrite(9, 230);
    analogWrite(10, 255);
    analogWrite(11, 255);
    delay(1000); 

    if(Serial.available() > 0) {
      int valor = Serial.readStringUntil('V').toInt();
      analogWrite(10, valor);
      delay(1000);
    }
   }
  
