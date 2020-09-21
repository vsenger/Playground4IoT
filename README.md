# Playground4IoT

*"There are three states of being: Not knowing, action and completion"*
Cult of Done Manifesto, Bre Pettis

Welcome Playgrounder to our repository where you can find libraries, firmwares, Arduino Sketch, tutorials and more for Playground4IoT development board. Playground4IoT is a development board that make easy and fun to start playing, prototyping and deploying connected devices projects using AWS Services like AWS IoT Core and Amazon FreeRTOS with security for adults, deployment over-the-air and management of big fleets of devices in production.

This project was done by AWS Developer Relations Team but is open-source, don't hesitate to clone it, produce, have fun, make money, change the world or anything else you dream. Developer Relations Team exist to help you to make it happen, count on us.. ALWAYS!

## Technical Resume

*"Accept that everything is a draft. It helps to get it done."*
The Cult of Done Manifesto, Bre Pettis

This board is based on ESP32, a powerful SoC that can run in low-energy with solar panel and simple battery forever and you can program using Arduino IDE, libraries and frameworks or you can go deeper and programa with Amazon FreeRTOS for industry ready devices.

* Based on ESP32 SoC (System-on-chip) with WIFI and Bluetooth
* Accelerometer Sensor
* Temperature, Humidity and Pressure sensor
* Light sensor
* Battery voltage sensor
* Solar panel sensor
* Groovy connectors
* External Solar Panel Connector
* External Battery Connector
* Battery charger system (cable / solar panel)
* And a lot of love!

## Let's Play!

*"People without dirty hands are wrong, doing something makes you right!"*
The Cult of Done Manifesto, Bre Pettis

To start playing with this device (or toy?!?) we have those main steps:
1. Install Playground4IoT usb driver
1. Install and setup Arduino IDE environment: install Arduino IDE itself, setup for E	SP32 development and then add libraries.
1. Create a thing to represent your board in AWS IoT Core
1. Setup the wifi credential, root-ca, device certificate and private key inside the Arduino C code
1. Upload the Arduino code to your board using an USB cable
1. Open AWS IoT Core console and start playing with your board

Now let's go deep in each step!

## 1. Install Playground4IoT usb driver

Our board uses a chip called CH340 to communicate throught the USB-C port, this chip is actualy a Serial - USB converter so once you have the driver installed you will see the Playground4IoT as a Serial port (windows: COM1, COM7, COMx - linux /dev/acm0 /dev/usb0 - macs /dev/cu.wchusbserial).

Follow this nice sparkfun.com tutorial to install the driver: https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/all

## 2. Arduino IDE

We have different ways to start programming our Playground4IoT that is based on ESP32 SoC and the simple way to do it is using Arduino IDE. It's a very popular IDE / tool for writing firmwares they call sketches using a simplified C sintax with many libraries to abstract all the hardware and C complex code.

To install Arduino IDE go to Arduino Web Site, download and install it, it's quite simlpe. Here is the link: https://www.arduino.cc/en/Main/Software

After installing the Arduino IDE we must add the ESP32 support. 

1) Open your Arduino IDE

2) Go to File -> Preferences

![tutorial image](/img/01.png)

3) Enter https://dl.espressif.com/dl/package_esp32_index.json into the “Additional Board Manager URLs” field as shown in the figure below. Then, click the “OK” button:

![tutorial image](/img/02.png)

4) Open the Boards Manager. Go to Tools > Board > Boards Manager…

![tutorial image](/img/03.png)

5) Search for ESP32 and press install button for the “ESP32 by Espressif Systems“:

![tutorial image](/img/04.png)

Now wait until it finish the downlaod and install

![tutorial image](/img/05.png)

All done with ESP32 support for Arduino IDE:

![tutorial image](/img/06.png)

## 3. AWS IoT Core Setup


## 4. Let's code!

## 5. Upload and fingers crossed

## 6. LEt's Play! 

	