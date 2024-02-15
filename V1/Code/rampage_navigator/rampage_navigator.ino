#include <BleKeyboardBeta.h>

#define led 32

//PUSH BUTTONS
#define button1 25
#define button2 23
#define button3 33

//TOGGLE SWITCH BUTTONS
#define button4 18
#define button5 19

BleKeyboard bleKeyboard;

unsigned long debounce1;
unsigned long debounce2;
int lag = 300;

bool buttonOnePressed = false;
bool buttonTwoPressed = false;
bool buttonThreePressed = false;

void setup() {
  bleKeyboard.begin();
  delay(5000);
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  //Attachinterrupt
  setAttaches();
}

void loop() {
  if (millis() - debounce1 > lag) {
    if (digitalRead(button4) == LOW) {
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    }
    if (digitalRead(button5) == LOW) {
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    }
    debounce1 = millis();
  }
  if (buttonOnePressed) {
    bleKeyboard.print("c");
    buttonOnePressed = false;
  }
  if (buttonTwoPressed) {
    bleKeyboard.write(KEY_UP_ARROW);
    buttonTwoPressed = false;
  }
  if (buttonThreePressed) {
    bleKeyboard.write(KEY_DOWN_ARROW);
    buttonThreePressed = false;
  }
}
/*
When we flag a piece of code with the IRAM_ATTR attribute, 
the compiled code is placed in the ESP32’s Internal RAM (IRAM). 
Otherwise the code is kept in Flash. And Flash on ESP32 is much slower than internal RAM.
*/
void IRAM_ATTR buttonOne() {
  if (millis() - debounce2 > lag) {
    buttonOnePressed = true;
    debounce2 = millis();
  }
}
void IRAM_ATTR buttonTwo() {
  if (millis() - debounce2 > lag) {
    buttonTwoPressed = true;
    debounce2 = millis();
  }
}
void IRAM_ATTR buttonThree() {
  if (millis() - debounce2 > lag) {
    buttonThreePressed = true;
    debounce2 = millis();
  }
}
void setAttaches() {  //has to be after the functions, otherwise fails with not declared with the IRAM_ATTR
  attachInterrupt(digitalPinToInterrupt(button1), buttonOne, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2), buttonTwo, FALLING);
  attachInterrupt(digitalPinToInterrupt(button3), buttonThree, FALLING);
}
