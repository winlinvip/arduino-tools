void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // wait 3s to sample again.
  digitalWrite(13, LOW);
  delay(3000);
}
