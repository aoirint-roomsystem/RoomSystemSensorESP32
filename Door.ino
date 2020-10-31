
void initDoor() {
  pinMode(18, INPUT_PULLUP);
}

void updateDoor() {
  int door = readDoorIsOpen();
  Serial.print("door: ");
  Serial.print(door);
  Serial.println();
}

int readDoorIsOpen() {
  return digitalRead(18) == HIGH;
}
