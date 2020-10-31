#define WIFI_SSID "WIFI-SSID"
#define WIFI_PW "WIFI-PASSWORD"

void initWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PW);
  Serial.println("WiFi connecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println();
  Serial.print("WiFi connected: ");
  Serial.println(WiFi.localIP());
}
