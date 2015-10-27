# Arduino BLE Shield (HM-10) Testing Sketch

## Requirements

The following are needed 

* [Arduino] (http://www.sixthlogic.com.au/index.php?main_page=product_info&cPath=65_67&products_id=247) Any Arduino UNO compatible board should work.
* [Arduino Bluetooth 4.0 BLE Shield] (http://www.sixthlogic.com.au/index.php?main_page=product_info&cPath=65_76&products_id=218)

## Installation 

For Arduino UNO, please use the following jumper configuration:

![BLE Shield Jumper Setting](http://www.monkeyboard.org/shop/images/BLE_Shield_Jumper.jpg)

For Arduino Mega 2560, please use the following jumper configuration:

![BLE Shield Arduino Mega 2560 Setting] (http://www.monkeyboard.org/shop/images/BLE_Shield_Mega2560.jpg)

1. Set power switch to 5V when using Arduino UNO.
2. Set HM-10 TX and RX to D2 and D3 respectively as shown.
3. Save HM_10_Test.ino to your local computer.
4. If you are using Arduino Mega 2560, change the code 

```
SoftwareSerial ble(2,3);				// For Uno, HM10 TX pin to Arduino Uno pin D2, HM10 RX pin to Arduino Uno pin D3
//SoftwareSerial ble(10,11);			// For Mega 2560, HM10 TX pin to Arduino Mega 2650 pin D10, HM10 RX pin to Arduino Mega 2560 pin D11
```

to 

```
//SoftwareSerial ble(2,3);				// For Uno, HM10 TX pin to Arduino Uno pin D2, HM10 RX pin to Arduino Uno pin D3
SoftwareSerial ble(10,11);				// For Mega 2560, HM10 TX pin to Arduino Mega 2650 pin D10, HM10 RX pin to Arduino Mega 2560 pin D11
```

## Arduino Sketch

Execute Arduino IDE, upload HM_10_Test.ino sketch.

## Testing

After the sketch has been successfully uploaded, open Serial Monitor in Arduino IDE using 9600 baud rate. The Serial Monitor will display results similar to the image below:

![BLE Shield Serial Monitor] (http://www.monkeyboard.org/shop/images/BLE_Shield_Serial_Monitor.png)

Using a BLE enabled phone, pair and connect to the BLE Shield.  The name and password for this example as seen from the result is **BLE Shield** and **000000** respectively. When the phone is connected to the BLE Shield, on the Serial Monitor, **OK+CONN** will be displayed. 

## Phone Tested

* Windows Phone 8.1 with [Bluetooth LE Explorer sample code.] (https://code.msdn.microsoft.com/Bluetooth-LE-Explorer-91669105)
* Asus Zenphone 2 Android 5.0 with [Nordic nRF Master Control Panel] (https://play.google.com/store/apps/details?id=no.nordicsemi.android.mcp&hl=en)


## Android Instruction

Step 1, execute nRF Master Control Panel, click connect on "BLE Shield", Shield's default name

![Connect to BLE](http://www.monkeyboard.org/images/android_ble/android_ble_01.png)

Step 2, once connected, click on "Unknown Service" UUID 0000ffe0-0000-1000-8000-00805f9b34fb

![Click Unknown Service] (http://www.monkeyboard.org/images/android_ble/android_ble_02.png)

Step 3, click WRITE, shown as UP ARROW BUTTON

![Click WRITE] (http://www.monkeyboard.org/images/android_ble/android_ble_03.png)

Step 4, select BYTE

![Select BYTE] (http://www.monkeyboard.org/images/android_ble/android_ble_04.png)

Step 5, type 31, (hex code 0x31 is ASCII 1), and click SEND

![Type 0x31] (http://www.monkeyboard.org/images/android_ble/android_ble_05.png)

Check for LED on D13 of Arduino turned on. Send 0x30 to turn off the LED.

## Contributors

Written by [JP Liew](http://jpliew.com)

Product home: [Arduino Bluetooth 4.0 BLE Shield] (http://www.sixthlogic.com.au/index.php?main_page=product_info&cPath=65_76&products_id=218)

*This software is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.*

*This software is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.*
