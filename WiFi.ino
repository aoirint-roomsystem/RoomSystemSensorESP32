#define _Q(x) #x
#define Q(x) _Q(x)

#ifdef SECRET_WIFI_SSID
  #define WIFI_SSID Q(SECRET_WIFI_SSID)
#else
  #define WIFI_SSID "WIFI-SSID"
#endif

#ifdef SECRET_WIFI_PW
  #define WIFI_PW Q(SECRET_WIFI_PW)
#else
  #define WIFI_PW "WIFI-PASSWORD"
#endif

void initWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PW);
  Serial.print("WiFi ");
  Serial.print(WIFI_SSID);
  Serial.println(" connecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println();
  Serial.print("WiFi connected: ");
  Serial.println(WiFi.localIP());
}
