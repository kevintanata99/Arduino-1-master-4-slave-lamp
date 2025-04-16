#include <Wire.h>

#define TOMBOL 2  // Pin tombol sesuai skema

int tombolStatus = 0;

void setup() {
  Wire.begin(8);
  pinMode(TOMBOL, INPUT);
  Serial.begin(9600);
}

void loop() {
  tombolStatus = digitalRead(TOMBOL);
  Wire.onRequest(requestEvent);
  delay(100);
}

void requestEvent() {
  if (tombolStatus == HIGH) {
    Wire.write('1');  // Kirim sinyal '1' ke Master jika tombol ditekan
  } else {
    Wire.write('0');  // Kirim sinyal '0' jika tombol tidak ditekan
  }
}
