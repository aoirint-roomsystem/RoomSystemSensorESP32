#define _Q(x) #x
#define Q(x) _Q(x)

#ifdef SECRET_FIREBASE_HOST
  #define FIREBASE_HOST Q(SECRET_FIREBASE_HOST)
#else
  #define FIREBASE_HOST "FIREBASE-PROJECT-ID.firebaseio.com"
#endif

#ifdef SECRET_FIREBASE_AUTH
  #define FIREBASE_AUTH Q(SECRET_FIREBASE_AUTH)
#else
  #define FIREBASE_AUTH "FIREBASE-DATABASE-SECRET"
#endif

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
