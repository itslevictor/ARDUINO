import processing.serial.*;
Serial port;

void setup() {
  port = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  port.write("0V");
  delay(1000);
}
