#include <HijelHID_BLEKeyboard.h>
#include <BLEHIDMediaKeys.h>

HijelHID_BLEKeyboard keyboard("1290media");

// XIAO ESP32-C3 buttons
#define BTN_PREV      D0
#define BTN_VOL_DOWN  D1
#define BTN_NEXT      D2
#define BTN_PLAY      D3
#define BTN_VOL_UP    D4

void waitRelease(uint8_t pin) {
    while (digitalRead(pin) == LOW) {
        delay(10);
    }
}

void setup() {
    Serial.begin(115200);

    pinMode(BTN_PREV, INPUT_PULLUP);
    pinMode(BTN_VOL_DOWN, INPUT_PULLUP);
    pinMode(BTN_NEXT, INPUT_PULLUP);
    pinMode(BTN_PLAY, INPUT_PULLUP);
    pinMode(BTN_VOL_UP, INPUT_PULLUP);

    Serial.println("Starting BLE Media Controller");

    keyboard.begin();

    Serial.println("Advertising...");
}

void loop() {

    if (!keyboard.isConnected()) {
        delay(100);
        return;
    }

    if (digitalRead(BTN_PREV) == LOW) {
        Serial.println("Previous");
        keyboard.tap(MEDIA_PREV_TRACK);
        waitRelease(BTN_PREV);
    }

    if (digitalRead(BTN_NEXT) == LOW) {
        Serial.println("Next");
        keyboard.tap(MEDIA_NEXT_TRACK);
        waitRelease(BTN_NEXT);
    }

    if (digitalRead(BTN_PLAY) == LOW) {
        Serial.println("Play/Pause");
        keyboard.tap(MEDIA_PLAY_PAUSE);
        waitRelease(BTN_PLAY);
    }

    if (digitalRead(BTN_VOL_UP) == LOW) {
        Serial.println("Volume Up");
        keyboard.tap(MEDIA_VOLUME_UP);
        waitRelease(BTN_VOL_UP);
    }

    if (digitalRead(BTN_VOL_DOWN) == LOW) {
        Serial.println("Volume Down");
        keyboard.tap(MEDIA_VOLUME_DOWN);
        waitRelease(BTN_VOL_DOWN);
    }

    delay(10);
}
