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

Here we have a simple description image showing the main parts:

1. Power on / off
2. IoT Button: you can use as IoT button or anything else!
3. The loooovely OLED display: you can code turn on and off to save energy, sure thing!
4. ESP32: the core! and it's compatible with Amazon FreeRTOS and very cheap
5. GPIO: the place you can extend in a "maker way"
6. Reset Button
7. Solar panel connector: yesss! I can survive with Sun, at least in Brazil ahahah
8. External Battery Connector
9. USB C: you can use to charge the battery (nice!!!), to upload firmware hard-wire (but you can do it over-the-air!) or to debug your board
10. USB to Serial Controller: this is the CH340 chip, you may need or not to install a driver for it
11. You will find three additional connectors under the board and they are Grove compatible, so you can plug [200+ different sensors](https://www.seeedstudio.com/catalogsearch/result/index/?cat=890&q=grove).

![tutorial image](/img/playground-01.png)

To start playing with this device (or toy?!?) we have those main steps:
1. Install Playground4IoT usb driver
1. Install and setup Arduino IDE environment: install Arduino IDE itself and setup for E	SP32 development 
1. Install Arduino libraries for the Playground4IoT sensors
1. Create a thing to represent your board in AWS IoT Core
1. Setup the wifi credential, root-ca, device certificate and private key inside the Arduino C code
1. Upload the Arduino code to your board using an USB cable
1. Open AWS IoT Core console and start playing with your board
 

Now let's go deep in each step!

## 1. Install Playground4IoT usb driver

Our board uses a chip called CH340 to communicate throught the USB-C port, this chip is actualy a Serial - USB converter so once you have the driver installed you will see the Playground4IoT as a Serial port (windows: COM1, COM7, COMx - linux /dev/acm0 /dev/usb0 - macs /dev/cu.wchusbserial). 

> **_NOTE:_**  MacOS Mojave (and newer) already includes a CH34x driver from Apple. Do not install other versions as it may cause issues. Read more on https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver/pull/19.

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

6) Choose the "ESP32 Dev Module" in boards manager:

![tutorial image](/img/07.png)

7) Now it's time to find your USB port, don't plug your board in your computer and check which ports you have on the Tools -> Port menu:

![tutorial image](/img/08.png)

8) Now plug your Playground4IoT and check this menu again, you should see something new like here that COM7 is the choosen port:

![tutorial image](/img/09.png)


## 3. Install Arduino Libraries for our Sensors

The Playground for IoT uses some sensors that has specific C libraries to make it easy to use. All we need to do is copy the folders in /Playground4IoT/Arduino/Libraries to your $HOME/Documents/Arduino/Library.

![tutorial image](/img/libs.png)


## 4. AWS IoT Core Setup

1) Now we need to setup the cloud side of the moon... We will create a thing to represent our Playground4IoT board and also the certificate and security keys. Open your AWS IoT Core Console and click Manage -> Things -> Register a thing:

![tutorial image](/img/awsiot-01.png)

2) Let's choose "Create a single thing"

![tutorial image](/img/awsiot-02.png)

3) Now give a name to your thing and click next

![tutorial image](/img/awsiot-03.png)

4) Now choose "One-click certificate creation"

![tutorial image](/img/awsiot-04.png)

5) You can finally download your thing's certificate and private key

![tutorial image](/img/awsiot-05.png)

6) Click Activate to make your certicates valid

![tutorial image](/img/awsiot-06.png)

7) Download ROOT Certifica Authoroty clicking in "A root CA for AWS IoT Download"

![tutorial image](/img/awsiot-06.png)

8) You will be redirected to another page that you can choose some options:

![tutorial image](/img/awsiot-07.png)

9) Now we need to take note of our AWS IoT Core endpoint to use in the next step. Open AWS IoT Core Console and click settings

![tutorial image](/img/awsiot-08.png)

## 5. Let's code!

1) Clone Playground4IoT repo: git clone https://github.com/vsenger/Playground4IoT

2) Open your Arduino IDE and make sure you selected the right USB port and ESP32 board!

3) Open the Arduino Sketch with current the firmware located inside the folder you clone the github repo: Playground4IoT/arduino/Playground4IoTFirmware-V0/

![tutorial image](/img/arduino-firmware-01.png)

![tutorial image](/img/arduino-firmware-02.png)

4) Setup your SSID and password: scroll down to the line around 60 and change:

1. The host name to your AWS IoT Core Thing name
2. SSID and passsword
3. Optional: change the name of the topics we are going to use to communicate with our board 

![tutorial image](/img/arduino-firmware-03.png)

5) Let's configure our credentials: click in secrets.h tab and then update:

1. AWS IoT Core endpoint
2. ROOT CA certificate: open the downloaded file and copy and paste the content
3. Same things for Device Certificate and Private Key. 

![tutorial image](/img/arduino-firmware-04.png)


## 6. Upload and fingers crossed

Now click the Upload button and wait until it compile and upload to your board. Keep your eyes in the log message panel, it's "normal" to have warning messages :).

![tutorial image](/img/arduino-upload.png)


## 7. Let's Play! 

Time to have fun! Open your AWS IoT Core Console and click Test

![tutorial image](/img/aws-iot-result-01.png)

Type playground/sensors and click Subscribe

![tutorial image](/img/aws-iot-result-02.png)

Type playground/sensors and click Subscribe

Now you should start seeing the json results!

![tutorial image](/img/aws-iot-result-03.png)

## 8. Oppss, not working and now?

Chime Vini vsenger@ is now the first option but you can check the following:

1. Is your USB port ok?
2. Did you get any error message during the compile and upload process?
3. Did you choose the right Arduino Board setting to ESP32 Dev?
4. Can you open the Arduino Serial monitor?



## 9. More to come!

From here you can start changing the Arduino code to improve anything you want or do some local logic implementation reacting locally based on sensors data.

	
