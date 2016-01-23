void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(115200);
}

char v;
void loop() {
  // read from serial, 
  // when got nothing, delay 1s and retry, write S to serial(Standby).
  // when 30s got nothing, close heater, write C to serial(Close).
  // when got H means open heater, write H to serial(Heating).
  // when got C means close heater, write C to serial(Close).
  v = -1;

  // got nothing.
  for (int i = 0; i < 30; i++) {
    if (Serial.available() <= 0) {
      Serial.print('S');
      delay(1000);
      continue;
    }
    v = Serial.read();
    break;
  }

  // close when retry exceed.
  if (v == -1) {
    Serial.print('C');
    digitalWrite(3, LOW);
    return;
  }

  // got specified command.
  if (v == 'H') {
    Serial.print('H');
    digitalWrite(3, HIGH);
    return;
  }
  Serial.print('C');
  digitalWrite(3, LOW);
}
