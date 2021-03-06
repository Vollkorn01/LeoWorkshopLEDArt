# LeoWorkshopLEDArt

## Setup

1. Download and install Arduino IDE from https://www.arduino.cc/en/software
2. Clone or download this repository
3. Copy FastLED and MPU9250 into the Documents/Arduino/libraries folder
4. Copy Workshop-IMU_LED into the Documents/Arduino folder and open it up
5. If you have an Adafruit Feather Board (the black one), also install the Adafruit library: https://learn.adafruit.com/adafruit-feather-m0-adalogger/setup You may also need to install additional libraryies, if you have an Feather M0 (written on the Arduino)
6. Connect the Arduino to a USB Port and select the Board ![alt text](https://cdn-learn.adafruit.com/assets/assets/000/053/074/large1024/adafruit_products_availboards.png?1524019356)
7. Select the USB Port ![alt text](https://cdn-learn.adafruit.com/assets/assets/000/028/796/large1024/adafruit_products_comport.png?1448653712)
8. Upload the sketch 
9. Disconnect Arduino


## Connecting the LEDs

LED Schematic
![alt text](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2016/09/WS2812B-with-Arduino_bb.png?w=700&ssl=1)

## Connecting the MPU-9250

Connect SCL/SCA to SCL/SCA (or A4/A5 if you dont have an SCL/SCA) on the Arduino

Schematic
![alt text](https://forum.arduino.cc/index.php?action=dlattach;topic=363577.0;attach=145874)


Now you can connect the Arduino and it should light up and change colors when you move it.