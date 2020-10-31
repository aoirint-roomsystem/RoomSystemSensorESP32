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

void pushSensorToFirebase(int light, int temperatureRaw, float temperature) {
  String sensorRoot = "/sensor";
  String dataRoot = sensorRoot + "/environment";

  json.clear();
  json.add("light", light);
  json.add("temperature", temperature);
  json.add("temperatureRaw", temperatureRaw);
  
  FirebaseJson jsonTimestamp;
  jsonTimestamp.add(".sv", "timestamp");
  json.add("timestamp", jsonTimestamp);
  
  if (Firebase.pushJSON(firebaseData, dataRoot, json)) {
    Serial.println("Firebase PushSensorData OK");
    Serial.println(firebaseData.pushName());
    Serial.println(firebaseData.ETag());
  }
  else {
    Serial.println("Firebase PushSensorData Failed");
    Serial.println(firebaseData.errorReason());
  }
  
}

void updateDoorStateForFirebase(int doorIsOpen) {
  String sensorRoot = "/sensor";
  String dataRoot = sensorRoot + "/door";
  
  json.clear();
  json.add("isOpen", doorIsOpen);
  
  FirebaseJson jsonTimestamp;
  jsonTimestamp.add(".sv", "timestamp");
  json.add("timestamp", jsonTimestamp);
  
  if (Firebase.updateNode(firebaseData, dataRoot, json)) {
    Serial.println("Firebase UpdateDoorState OK");
  }
  else {
    Serial.println("Firebase UpdateDoorState Failed");
    Serial.println(firebaseData.errorReason());
  }
}

void updateNowButtonStateForFirebase(int buttonIsPressed) {
  String sensorRoot = "/sensor";
  String dataRoot = sensorRoot + "/button/now";
  
  json.clear();
  json.add("isPressed", buttonIsPressed);
  
  FirebaseJson jsonTimestamp;
  jsonTimestamp.add(".sv", "timestamp");
  json.add("timestamp", jsonTimestamp);
  
  if (Firebase.updateNode(firebaseData, dataRoot, json)) {
    Serial.println("Firebase UpdateNowButtonState OK");
  }
  else {
    Serial.println("Firebase UpdateNowButtonState Failed");
    Serial.println(firebaseData.errorReason());
  }
}

void updateWaitButtonStateForFirebase(int buttonIsPressed) {
  String sensorRoot = "/sensor";
  String dataRoot = sensorRoot + "/button/wait";
  
  json.clear();
  json.add("isPressed", buttonIsPressed);
  
  FirebaseJson jsonTimestamp;
  jsonTimestamp.add(".sv", "timestamp");
  json.add("timestamp", jsonTimestamp);
  
  if (Firebase.updateNode(firebaseData, dataRoot, json)) {
    Serial.println("Firebase UpdateWaitButtonState OK");
  }
  else {
    Serial.println("Firebase UpdateWaitButtonState Failed");
    Serial.println(firebaseData.errorReason());
  }
}
