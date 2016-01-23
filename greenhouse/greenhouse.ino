#include <SimpleDHT.h>

int pinDHT11 = 2;
int pinHeater = 3;
int baudrate = 115200;

void setup() {
  pinMode(pinHeater, OUTPUT);
  Serial.begin(115200);
}

void loop() {
}

