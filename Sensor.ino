#define TMPR_VOLT            3.3
#define TMPR_V_OFFSET        0.6
#define TMPR_DEGREE_PER_VOLT 0.01

long prevSensorRead = -100000;

void initSensor() {
  adc1_config_width(ADC_WIDTH_BIT_10);
  adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11); // Pin D32
  adc1_config_channel_atten(ADC1_CHANNEL_5, ADC_ATTEN_DB_11); // Pin D33
}

void updateSensor() {
  long timestamp = millis();
  if (!(timestamp - prevSensorRead > 5 * 60 * 1000)) {
    return;
  }
  
  int light = readLight();
  int temperatureRaw = readTemperatureRaw();
  float temperature = calcTemperature(temperatureRaw);

  pushSensorToFirebase(light, temperatureRaw, temperature);
  
  Serial.print("light: ");
  Serial.print(light);
  Serial.print(", temperatureRaw: ");
  Serial.print(temperatureRaw);
  Serial.print(", temperature: ");
  Serial.print(temperature);
  Serial.println();

  prevSensorRead = timestamp;
}

int readLight() {
  return adc1_get_raw(ADC1_CHANNEL_4);
}

int readTemperatureRaw() {
  return adc1_get_raw(ADC1_CHANNEL_5);
}

float calcTemperature(int temperatureRaw) {
  float v0 = (float)temperatureRaw / 1023 * TMPR_VOLT;
  float temperature = (v0 - TMPR_V_OFFSET) / TMPR_DEGREE_PER_VOLT;

  return temperature + 12.0f;
}
