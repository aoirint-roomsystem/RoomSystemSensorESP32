
int btnNowPrev = 0;
int btnWaitPrev = 0;

void initResponseButton() {
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  
  btnNowPrev = readNowIsPressed();
  updateNowButtonStateForFirebase(btnNowPrev);

  btnWaitPrev = readWaitIsPressed();
  updateWaitButtonStateForFirebase(btnWaitPrev);
  
}

void onNowPressed() {
  playSound(1);
}
void onWaitPressed() {
  playSound(2);
}

void updateResponseButton() {
  int btnNow = readNowIsPressed();
  int btnWait = readWaitIsPressed();
  
  // Serial.print("btn now: ");
  // Serial.print(btnNow);
  // Serial.print(", wait: ");
  // Serial.print(btnWait);
  // Serial.println();

  if (btnNow != btnNowPrev) {
    updateNowButtonStateForFirebase(btnNow);
    Serial.print("Button Now: ");
    Serial.println(btnNow);

    if (btnNow) {
      onNowPressed();
    }
  }

  if (btnWait != btnWaitPrev) {
    updateWaitButtonStateForFirebase(btnWait);
    Serial.print("Button Wait: ");
    Serial.println(btnWait);
    
    if (btnWait) {
      onWaitPressed();
    }
  }
  
  btnNowPrev = btnNow;
  btnWaitPrev = btnWait;
}

int readNowIsPressed() {
  return digitalRead(18) == LOW;
}

int readWaitIsPressed() {
  return digitalRead(19) == LOW;
}
