#include <FirebaseESP32.h>
#include <FB_HTTPClient32.h>
#include <FirebaseJson.h>

#include <WiFi.h>
#include <driver/adc.h>

void blink(int count, int intervalMillis) {
  pinMode(13, OUTPUT);

  for (int i = 0; i < count; i++) {
    digitalWrite(13, HIGH);
    delay(intervalMillis / 2);
    digitalWrite(13, LOW);
    delay(intervalMillis / 2);
  }
}

void setup() {
  Serial.begin(115200);

  initWiFi();
  initFirebase();

  initSensor();
  // initDoor();
  initSpeaker();

  blink(3, 1000);
}


void loop() {
  updateSensor();
  updateSpeaker();
  // updateDoor();

  // delay(1*60*1000);
  delay(5 * 60 * 1000);
}
