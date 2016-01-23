void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // now data from serial, turn off the LED.
  if (Serial.available() <= 0) {
    digitalWrite(13, LOW);
    delay(100);
    return;
  }

  // echo the serial data.
  Serial.print((char)Serial.read());
  digitalWrite(13, HIGH);
  delay(100);
}
