#include <usbportability.h>
#include <usbdrv.h>
#include <scancode-ascii-table.h>
#include <osccal.h>
#include <usbconfig-prototype.h>
#include <oddebug.h>
#include <DigiKeyboard.h>
#include <osctune.h>
#include <usbconfig.h>

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
#define KEY_CAPS_LOCK	0x39
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
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  printText(F("notepad"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(750);
  printText(F("Hello World!!!"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digiEnd();
}

/* Unused endless loop */
void loop() {}
