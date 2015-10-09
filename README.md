# Arduino BLE Shield (HM-10) Sketch



## Requirements

The following are needed 

* [Arduino] (http://www.sixthlogic.com.au/index.php?main_page=product_info&cPath=65_67&products_id=247) Any Arduino UNO compatible board should work.
* [Arduino Bluetooth 4.0 BLE Shield] (http://www.sixthlogic.com.au/index.php?main_page=product_info&cPath=65_76&products_id=218)

## Installation 

![BLE Shield Jumper Setting](http://www.monkeyboard.org/shop/images/BLE_Shield_Jumper.jpg)

1. Set power switch to 5V when using Arduino UNO.
2. Set HM-10 TX and RX to D2 and D3 respectively as shown.
3. Save HM_10_Test.ino to your local computer.

## Arduino Sketch

Execute Arduino IDE, upload HM_10_Test.ino sketch.

## Testing

After the sketch has been successfully uploaded, open Serial Monitor in Arduino IDE using 9600 baud rate. The Serial Monitor will display as result similar to the image below:

![BLE Shield Serial Monitor] (http://www.monkeyboard.org/shop/images/BLE_Shield_Serial_Monitor.png)

Using a BLE enabled phone, pair and connect to the BLE Shield.  The name and password for this example as seen from the image is *BLE Shield* and *000000* respectively. When the phone is connected to the BLE Shield, on the Serial Monitor, *OK+CONN* will be displayed. 

## Contributors

Written by [JP Liew](http://jpliew.com)

Product home: [Arduino Bluetooth 4.0 BLE Shield] (http://www.sixthlogic.com.au/index.php?main_page=product_info&cPath=65_76&products_id=218)

*This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.*

*This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.*
