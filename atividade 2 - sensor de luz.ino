int valor;

void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode (13, OUTPUT);
  
}
void loop(){
  valor =  analogRead(A0);
  if (valor <=500){
  digitalWrite(13, 1);
  delay(200);
  Serial.println("tudo escuro");
  delay(100);
  }
  else {
    Serial.println("Luz luz!");
    delay(100);
    digitalWrite(13, 0);
    delay(10);
    }
}
