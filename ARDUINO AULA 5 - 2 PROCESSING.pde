import processing.serial.*;
String val;
Serial port;
void setup() {
  size(100, 100);
  colorMode(HSB, 100);
  for (int i = 0; i < 100; i++) {
  for (int j = 0; j < 100; j++) {
  stroke(i, j, 100);
  point(i, j);
 
}
}
port = new Serial(this, Serial.list()[1], 9600);
}

void draw(){
  if ( port.available() > 0) 
  {  // If data is available,
  val = port.readStringUntil('\n');         // read it and store it in val
  println(val);
  } 
  
}
void mouseReleased(){
  colorMode(RGB, 255);
  color cor = get(mouseX, mouseY);
  int vermelho = int(red(cor));
  int verde = int(green(cor));
  int azul = int(blue(cor));
  String mensagem = (vermelho + "R"
  + verde + "G"
  + azul + "B");
  port.write(mensagem); 
  port.readChar();
  println(mensagem);
}
