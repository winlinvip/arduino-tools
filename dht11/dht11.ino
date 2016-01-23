#include <SimpleDHT.h>

int pinDHT11 = 2;
int pinLED = 13;

void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(115200);
}

void example_without_raw_bits() {
  int ret = 0;
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  if ((ret = simple_dht11_read(pinDHT11, &temperature, &humidity, NULL)) != 0) {
    Serial.print("Read DHT11 failed. ret=");
    Serial.println(ret);
    return;
  }
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  
  // DHT11 sampling rate is 1HZ.
  delay(1000);
}

void example_with_raw_bits() {
  int ret = 0;
  
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if ((ret = simple_dht11_read(pinDHT11, &temperature, &humidity, data)) != 0) {
    Serial.print("Read DHT11 failed. ret=");
    Serial.println(ret);
    return;
  }
  Serial.print("Sample RAW: ");
  simple_dht11_serial_print(data);
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  
  // DHT11 sampling rate is 1HZ.
  delay(1000);
}

void loop() {
  digitalWrite(pinLED, LOW);
  delay(3000);
  
  // start working...
  Serial.println("=================================");
  digitalWrite(pinLED, HIGH);
  Serial.println("Sample DHT11...");

  example_without_raw_bits();
  example_with_raw_bits();
}
