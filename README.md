# HandleBar Bluetooth Media Controller

Bluetooth media control buttons for motorbike handlebars.
This is a project that turns an esp32 into media control buttons for a motorcycle (or anything else). It is paired with your pone or gps or what ever and it sends media control keys.

<img width="1500" height="2000" alt="20260922_141244(0)" src="https://github.com/user-attachments/assets/e4c3eeed-cbf1-4876-b7b5-1d02047e149c" />

## Hardware

- ESP32 Dev Module
- 5 push buttons
- KTM 1290 handlebar mount

## ESP32 connection

The buttons are connected directly to the XIAO ESP32-C3 GPIO pins. The ESP32-C3 communicates with the paired phone wirelessly over BLE.

       Physical Buttons
              │
              ▼
     ┌─────────────────┐
     │ XIAO ESP32-C3   │
     │                 │
     │ D0 ─ Previous   │
     │ D1 ─ Volume -   │
     │ D2 ─ Next       │
     │ D3 ─ Play/Pause │
     │ D4 ─ Volume +   │
     └────────┬────────┘
              │
             BLE
              │
              ▼
        ┌───────────┐
        │   Phone   │
        │  Media    │
        │  Player   │
        └───────────┘


## Arduino IDE

Tested with:

- Arduino IDE 2.3.6
- esp32 board package 3.2.1

## Board Configuration

Board:

    ESP32 Dev Module

Tools settings:

- USB CDC On Boot: Enabled
- CPU Frequency: 240MHz
- Flash Frequency: 80MHz
- Flash Mode: QIO
- Flash Size: 4MB
- Partition Scheme: Default

## Libraries

Install the following library using the Arduino Library Manager:

- NimBLE-Arduino 1.4.1

Library URL:

    https://github.com/h2zero/NimBLE-Arduino

## Project Structure

```text
HandleBarBluetoothMedia/
├── README.md
├── firmware/
│   └── bt_media_buttons.ino
├── hardware/
│   └── KTM 1290 BT Buttons.stl
└── docs/
    └── bt_media_buttons.jpg
```

## Build

1. Install the ESP32 board package version 3.2.1.
2. Install NimBLE-Arduino version 1.4.1.
3. Open:

       firmware/bt_media_buttons.ino

4. Select:

       Tools → Board → ESP32 Dev Module

5. Compile and upload to the ESP32.

## Alternative CLI

arduino-cli lib install "HijelHID_BLEKeyboard"
arduino-cli lib install "NimBLE-Arduino"
arduino-cli compile --fqbn esp32:esp32:XIAO_ESP32C3 .
arduino-cli upload -p /dev/ttyACM0 --fqbn esp32:esp32:XIAO_ESP32C3 .

## Notes

This project was developed and tested with:

- Arduino IDE 2.3.6
- esp32 by Espressif Systems 3.2.1
- NimBLE-Arduino 1.4.1

Future versions of the ESP32 board package or NimBLE-Arduino library may require code changes.


