/*
Basic_I2C.ino
Brian R Taylor
brian.taylor@bolderflight.com

Copyright (c) 2017 Bolder Flight Systems

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, 
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or 
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "MPU9250.h"
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 14

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 5
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;

void setup() {
  
  // add LED strip
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  
  // serial to display data
  Serial.begin(115200);
  while(!Serial) {}

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
  
}

void loop() {
  // read the sensor
  IMU.readSensor();
  // display the data
//  Serial.print(IMU.getAccelX_mss(),6);
//  Serial.print("\t");
//  Serial.print(IMU.getAccelY_mss(),6);
//  Serial.print("\t");
//  Serial.print(IMU.getAccelZ_mss(),6);
//  Serial.print("\t");
//  Serial.print(IMU.getGyroX_rads(),6);
//  Serial.print("\t");
//  Serial.print(IMU.getGyroY_rads(),6);
//  Serial.print("\t");
//  Serial.print(IMU.getGyroZ_rads(),6);
//  Serial.print("\t");

  int accx = abs(IMU.getAccelX_mss());
  int accy = abs(IMU.getAccelY_mss());
  int accz = abs(IMU.getAccelZ_mss());
  
  int accTot = accx+ accy + accz -10;
  if (accTot < 5) {
    accTot = 1;
  };

  Serial.print(accTot);
  Serial.print("\t");

  int magx = IMU.getMagX_uT();
  int magy = IMU.getMagY_uT();
  int magz = IMU.getMagZ_uT();

//  Serial.print(magx);
//  Serial.print("\t");
//  Serial.print(magy);
//  Serial.print("\t");
//  Serial.print(magz);
//  Serial.print("\t");
    Serial.println();
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(magx*10,magy*9,magz*9);
    //leds[i] = CRGB(255,255,0);
  }
  int BRIGHTNESS = 128;
  FastLED.setBrightness(  accTot*3 );
  FastLED.show();

  delay(10);
}
