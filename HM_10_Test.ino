/*
	Arduino BLE Shield (HM-10) Sketch
	by JP Liew http://jpliew.com

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <SoftwareSerial.h>

#define DATALEN 100

SoftwareSerial ble(2,3);				// HM10 TX pin to Arduino D2, HM10 RX pin to Arduino D3
char buffer[DATALEN];					// Buffer to store response
int timeout=800; 						// Wait 800ms each time for BLE to response, depending on your application, adjust this value accordingly

boolean IsBLEReady() {
	// The problem with this BLE Shield is the HM-10 module does not response with CR LF at the end of the response,
	// so a timeout is required to prevent the loop locking up.
	ReadBLE(timeout, "AT" ,buffer);		// Send AT and store response to buffer 
	if (strcmp(buffer,"OK")==0){		
		return true;
	} else {
		return false;
	}  
}

boolean ReadBLE(long timeout, char* command, char* temp) {
	long endTime;
	boolean found=false;
	endTime=millis()+timeout;			// 
	memset(temp,0,100);					// clear buffer
	found=true;
	Serial.print("Arduino send=");
	Serial.println(command);
	ble.print(command);
	delay(1);
	// The loop below wait till either a response is received or timeout
	while(!ble.available()){
		if(millis()>endTime) {			// timeout, break
			found=false;
			break;
		}
	}  

	if (found) {						// response is available
		int i=0;
		while(ble.available()) {		// loop and read the data
			char a=ble.read();
			// Serial.print((char)a);	// Uncomment this to see raw data from BLE
			temp[i]=a;					// save data to buffer
			i++;
			if (i>DATALEN) break;   	// prevent buffer overflow, need to break
			delay(2);					// give it a 2ms delay before reading next character
		}
		Serial.print("BLE reply=");
		Serial.println(temp);
		return true;
	} else {
		Serial.println("BLE timeout!");
		return false;
	}
}

void setup() {
	ble.begin(9600);  // Iteaduino BLE Shield default 9600 Baud Rate
	Serial.begin(9600); 
	while(!IsBLEReady()){
		// Not doing anything until BLE is ready
		// This part will locked up until BLE is ready, no point to move forward if there is a problem with the BLE
		// If you see on Serial Monitor lots of BLE timeout, most likely your have a bad shield
		// Check if the shield JUMPER is correctly set to 
		// HM10 TX to D2
		// HM10 RX to D3
	} 
	
	// The following commands are just to demonstrate the shield is working properly,
	// in actual application, only call those that are needed by your application.
	// Check HM-10 datasheet for the description of the commands.
	ReadBLE(timeout,"AT+NAME?",buffer);
	ReadBLE(timeout,"AT+BAUD?",buffer);
	ReadBLE(timeout,"AT+MODE?",buffer);
	ReadBLE(timeout,"AT+PASS?",buffer);
	ReadBLE(timeout,"AT+VERS?",buffer);
	ReadBLE(timeout,"AT+RADD?",buffer);
	ReadBLE(timeout,"AT+ADDR?",buffer);
	ReadBLE(timeout,"AT+TYPE?",buffer);
	ReadBLE(timeout,"AT+POWE?",buffer);
	ReadBLE(timeout,"AT+NOTI1",buffer);
	Serial.println("----------------------");
	Serial.println("Waiting for remote connection...");
}

void loop() {
	if (ble.available()) {
		Serial.print((char)ble.read());
	}  

}
