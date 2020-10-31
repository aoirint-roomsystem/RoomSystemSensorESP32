
void initSensor() {
  adc1_config_width(ADC_WIDTH_BIT_10);
  adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11); // Pin D32
  adc1_config_channel_atten(ADC1_CHANNEL_5, ADC_ATTEN_DB_11); // Pin D33
}

void updateSensor() {
  int light = readLight();
  int temperature = readTemperature();

  pushSensorToFirebase(light, temperature);
  
  Serial.print("light: ");
  Serial.print(light);
  Serial.print(", temperature: ");
  Serial.print(temperature);
  Serial.println();
}

int readLight() {
  return adc1_get_raw(ADC1_CHANNEL_4);
}

int readTemperature() {
  return adc1_get_raw(ADC1_CHANNEL_5);
}
