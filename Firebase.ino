#define FIREBASE_HOST "FIREBASE-PROJECT-ID.firebaseio.com"
#define FIREBASE_AUTH "FIREBASE-DATABASE-SECRET"

FirebaseData firebaseData;
FirebaseJson json;

void initFirebase() {
  Serial.println("Firebase initialzing");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000*60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  Serial.println("Firebase initialzed");
}

void pushSensorToFirebase(int light, int temperature) {
  String sensorRoot = "/sensor";
  String dataRoot = sensorRoot + "/data";

  json.clear();
  json.add("light", light);
  json.add("temperature", temperature);
  
  FirebaseJson jsonTimestamp;
  jsonTimestamp.add(".sv", "timestamp");
  json.add("timestamp", jsonTimestamp);
  
  if (Firebase.pushJSON(firebaseData, dataRoot, json)) {
    Serial.println("Firebase PushData OK");
    Serial.println(firebaseData.pushName());
    Serial.println(firebaseData.ETag());
  }
  else {
    Serial.println("Firebase PushData Failed");
    Serial.println(firebaseData.errorReason());
  }
  
}
