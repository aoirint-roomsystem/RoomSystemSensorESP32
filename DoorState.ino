int doorIsOpenPrev = 0;

void initDoorState() {
  pinMode(21, INPUT_PULLUP);

  doorIsOpenPrev = readDoorIsOpen();
  updateDoorStateForFirebase(doorIsOpenPrev);
}

void onDoorOpened() {
}
void onDoorClosed() {
}

void updateDoorState() {
  int doorIsOpen = readDoorIsOpen();
  // Serial.print("doorIsOpen: ");
  // Serial.print(doorIsOpen);
  // Serial.println();

  if (doorIsOpen != doorIsOpenPrev) {
    updateDoorStateForFirebase(doorIsOpen);
    Serial.print("Door: ");
    Serial.println(doorIsOpen);
    
    if (doorIsOpen) {
      onDoorOpened();
    }
    else {
      onDoorClosed();
    }
  }

  doorIsOpenPrev = doorIsOpen;
}

int readDoorIsOpen() {
  return digitalRead(21) == HIGH;
}
