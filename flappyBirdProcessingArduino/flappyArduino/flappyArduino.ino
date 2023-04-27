const int buttonPin = 2;
const int ledPin = 13;
//Define as posições dos pinos no arduino

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  //abre a porta de comunicação
}

void loop() {
  // Lê o estado do botão
  int buttonState = digitalRead(buttonPin);
  
  // Se o botão está pressionado, envia uma mensagem pela porta serial
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("BUTTON_PRESSED");
    //envia o estado do botão para a porta 
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(50);
}
