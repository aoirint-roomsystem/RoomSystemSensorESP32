#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial speakerSerial(23, 22); // RX, TX
DFRobotDFPlayerMini dfPlayer;

void initSpeaker() {
  connectSpeaker();

  dfPlayer.setTimeOut(500);
  dfPlayer.pause();
  dfPlayer.volume(30); // [0, 30]
}

void playSound(int soundId) {
  dfPlayer.pause();
  dfPlayer.play(soundId);
}

void connectSpeaker() {
  speakerSerial.begin(9600);

  Serial.println("DFPlayer connecting");
  while (!dfPlayer.begin(speakerSerial)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  Serial.println("DFPlayer connected");
}

void updateSpeaker() {
  if (dfPlayer.waitAvailable(10)) {
    printDetail(dfPlayer.readType(), dfPlayer.read());
  }
}

void printDetail(uint8_t type, int value) {
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }

}
