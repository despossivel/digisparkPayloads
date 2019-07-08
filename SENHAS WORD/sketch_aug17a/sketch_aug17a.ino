#include "DigiKeyboard.h"
#define KEY_UP_ARROW     0x52
#define KEY_DOWN_ARROW   0x51
#define KEY_LEFT_ARROW   0x50
#define KEY_RIGHT_ARROW  0x4F
#define KEY_LEFT_GUI     0xE3
#define KEY_ESC          0x29
#define KEY_HOME         0x4A
#define KEY_INSERT       0x49
#define KEY_NUM_LOCK     0x53
#define KEY_SCROLL_LOCK  0x47
#define KEY_CAPS_LOCK  0x39
#define KEY_TAB          0x2B

void digiBegin() {
  DigiKeyboard.sendKeyStroke(0,0);
  DigiKeyboard.delay(50);
}

void digiEnd() {
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboard.delay(1000);
  }
}

void printText(fstr_t *txt) {
  DigiKeyboard.print(txt);
  DigiKeyboard.update();
}

void setup() {
  digiBegin();
  // Target: WINDOWS VISTA/7
  // Encoder V2.4
  // Using the run command for a broader OS base.
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  printText(F("cmd /Q /D /T:7F /F:OFF /V:ON /K"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(750);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT);
  DigiKeyBoard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW);
  DigiKeyBoard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(int i = 0; i < 100; i++) {
    DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);
  }

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digiEnd();
}

/* Unused endless loop */
void loop() {}
