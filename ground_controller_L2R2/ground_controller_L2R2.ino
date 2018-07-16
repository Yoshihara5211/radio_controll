#include "Arduino.h"
#include <string.h>
#include <stdio.h>
#include <PS3BT.h>
#include <usbhub.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif
USB Usb;
//USBHub Hub1(&Usb);
// Some dongles have a hub inside
BTD Btd(&Usb);
// You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd);
// This will just create the instance
//PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch
bool printTemperature, printAngle;


void setup() {  //初期化関数
  Serial.begin(9600);  //通信開始
  //ps3のコントローラーがBluetoothでつながるとPS3 Bluetooth Library Startedと表示される
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}

void loop() {  //ループ関数
  String l2;
  String r2;
  //  String ls;
  //  String rs;
  //  int module0=0;
  //  int module1=1;
  //  int module2=2;

  Usb.Task();  //USBからデータを
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {  //PS3コントローラーをBluetoothで検知
    //value アナログスティック↑0,アナログスティック↓255,アナログスティック真ん中128
    // if (PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117 || PS3.getAnalogHat(RightHatY) > 137 || PS3.getAnalogHat(RightHatY) < 117) {
    //||PS3.getAnalogButton(L2)==255||PS3.getAnalogButton(R2)==255) {
    l2 = PS3.getAnalogButton(L2);
    r2 = PS3.getAnalogButton(R2);
    //   left2=PS3.getAnalogButton(L2);
    //   right2=PS3.getAnalogButton(R2);
    //   module0=0;
    //   module1=1;
    //   module2=2;
    Serial.print(l2);
    Serial.print(",");
    Serial.print(r2);
    Serial.print(",");
    //    Serial.print(r3);
    //    Serial.print(",");
    //    Serial.print(left2);
    //    Serial.print(",");
    //    Serial.print(right2);
    //if (PS3.getButtonClick(L3)&&PS3.getButtonClick(R3)) {
    //    PS3.setRumbleOn(RumbleLow);
    //    Serial.print(module1);
    //    Serial.print("e");
    //    Serial.print("\n");
    //    Serial.print("0");
    //    Serial.print(",");
    //    Serial.print("0");
    //    Serial.print(",");
    //    Serial.print(module1);
    //    Serial.print("e");
    //    Serial.print("\n");
    //    delay(15000);
    //    }
    //else if(PS3.getButtonClick(TRIANGLE)&&PS3.getButtonClick(CROSS)){
    //    PS3.setRumbleOn(RumbleLow);
    //    Serial.print(module2);
    //    }
    //else{
    //      Serial.print(module0);
    Serial.print("e");
    Serial.print("\n");
    delay(5);
    //    }
  }
}
