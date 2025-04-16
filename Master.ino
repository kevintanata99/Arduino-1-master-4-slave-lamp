#include <Wire.h>

#define LED_KIRI 10
#define LED_TENGAH1 9
#define LED_TENGAH2 8
#define LED_KANAN 7

void setup() {
  Wire.begin(); //Identifikasi sebagai Master
  pinMode(LED_KIRI, OUTPUT);
  pinMode(LED_TENGAH1, OUTPUT);
  pinMode(LED_TENGAH2, OUTPUT);
  pinMode(LED_KANAN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Wire.requestFrom(10, 1);
  if (Wire.available()) {
    char tombolKiri = Wire.read();
    if (tombolKiri == '1') {
      digitalWrite(LED_KIRI, HIGH);
    } else {
      digitalWrite(LED_KIRI, LOW);
    }
  }

  Wire.requestFrom(9, 1);
  if (Wire.available()) {
    char tombolTengah1 = Wire.read();
    if (tombolTengah1 == '1') {
      digitalWrite(LED_TENGAH1, HIGH);
    } else {
      digitalWrite(LED_TENGAH1, LOW);
    }
  }

  Wire.requestFrom(8, 1);  
  if (Wire.available()) {
    char tombolTengah2 = Wire.read();
    if (tombolTengah2 == '1') {
      digitalWrite(LED_TENGAH2, HIGH);
    } else {
      digitalWrite(LED_TENGAH2, LOW);
    }
  }
  
  Wire.requestFrom(7, 1);
  if (Wire.available()) {
    char tombolKanan = Wire.read();
    if (tombolKanan == '1') {
      digitalWrite(LED_KANAN, HIGH);
    } else {
      digitalWrite(LED_KANAN, LOW);
    }
  }

  delay(100);  //delay untuk stabilitas
}
