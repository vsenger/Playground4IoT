/****** ESP32 GPIO MAP ******  

GPIO0 -> Firmware Upload Mode
GPIO1 -> TXD
GPIO3 -> RXD

GPIO13 -> Led 3
GPIO14 -> Led 4
GPIO18 -> Led 1
GPIO19 -> Led 2

GPIO16 -> Serial 2 (RX)
GPIO17 -> Serial 2 (TX)

GPIO21 -> I2C (SDA)
GPIO22 -> I2C (SCL)

GPIO23 -> User Button (0=pressed / 1=not pressed)

GPIO25 -> Battery State (0=Charging / 1=charged or not charging)
GPIO26 -> I2C sensors Interrupt Input (optional- must be configured conecting SJ1 or SJ5 or SJ7 or SJ8 or SJ9)

GPIO27 -> Sensors and Display Power control (0=Power OFF / 1=Power ON)

GPIO32 -> Battery voltage (Analog INPUT)
GPIO33 -> (External Analog INPUT)
GPIO34 -> (External Analog INPUT)
GPIO35 -> Solar Panel voltage (Analog INPUT)

GPIO6 a GPIO11 -> Do not Use (Flash Memory)

GPIO2 -> External GPIO
GPIO4 -> External GPIO
GPIO5 ->  External GPIO
GPI12 ->  External GPIO
GPI15 ->  External GPIO
GPI12 ->  External GPIO
SensorVP - >  External GPIO
SensorVN - >  External GPIO

*/
#include "secrets.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>


#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include "ssd1306.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include "ClosedCube_HDC1080.h"
ClosedCube_HDC1080 hdc1080;

// Include logo images
#include "Logo_AWS.h"


#define hostName "MyPlayground-NAMEHERE"

const char* ssid = "surfing-iot";
const char* password = "iotiotiot";

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC   "playground/sensors"
#define AWS_IOT_SUBSCRIBE_TOPIC "playground/command"

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
 
// I2C address of the TSL2571 0x39(57)
#define Addr 0x39
byte data[4];
double luminosidade ;

#define SSD1306_128_64


// MPL3115A2
#define STATUS     0x00
#define OUT_P_MSB  0x01
#define OUT_P_CSB  0x02
#define OUT_P_LSB  0x03
#define OUT_T_MSB  0x04
#define OUT_T_LSB  0x05
#define DR_STATUS  0x06
#define OUT_P_DELTA_MSB  0x07
#define OUT_P_DELTA_CSB  0x08
#define OUT_P_DELTA_LSB  0x09
#define OUT_T_DELTA_MSB  0x0A
#define OUT_T_DELTA_LSB  0x0B
#define WHO_AM_I   0x0C
#define F_STATUS   0x0D
#define F_DATA     0x0E
#define F_SETUP    0x0F
#define TIME_DLY   0x10
#define SYSMOD     0x11
#define INT_SOURCE 0x12
#define PT_DATA_CFG 0x13
#define BAR_IN_MSB 0x14
#define BAR_IN_LSB 0x15
#define P_TGT_MSB  0x16
#define P_TGT_LSB  0x17
#define T_TGT      0x18
#define P_WND_MSB  0x19
#define P_WND_LSB  0x1A
#define T_WND      0x1B
#define P_MIN_MSB  0x1C
#define P_MIN_CSB  0x1D
#define P_MIN_LSB  0x1E
#define T_MIN_MSB  0x1F
#define T_MIN_LSB  0x20
#define P_MAX_MSB  0x21
#define P_MAX_CSB  0x22
#define P_MAX_LSB  0x23
#define T_MAX_MSB  0x24
#define T_MAX_LSB  0x25
#define CTRL_REG1  0x26
#define CTRL_REG2  0x27
#define CTRL_REG3  0x28
#define CTRL_REG4  0x29
#define CTRL_REG5  0x2A
#define OFF_P      0x2B
#define OFF_T      0x2C
#define OFF_H      0x2D

#define MPL3115A2_ADDRESS 0x60 // 7-bit I2C address

long startTime;


#define led1 18
#define led2 19
#define led3 13
#define led4 14
#define delayLeds 50
bool direcao = false;
int userButtonState = 1;

float Temperatura;
float Umidade;
float Luminosidade;

float Altitude;
float Pressao;

double solarPanelVoltage;
double batteryVoltage;
bool batteryChargeStatus ;  //(1-CHARGED)
int batteryStatusPerCent;

#define batteryStatusPin 25

float Xacc;
float Yacc;
float Zacc;


#define SSD1306_128_32


WiFiClientSecure net = WiFiClientSecure();
MQTTClient client = MQTTClient(512);

#define SECRET
#define THINGNAME "play1"


void setup() {
  pinMode(27,OUTPUT);       //power ON sensors and OLED display
  digitalWrite(27,HIGH);
  pinMode(25,INPUT);        
  pinMode(23,INPUT_PULLUP);    //enable user button pull-up
  delay(2000);

  Wire.begin();  
  ssd1306_128x64_i2c_init();                     // Initialze SSD1306 OLED display
  ssd1306_clearScreen( );
  ssd1306_drawBitmap(0, 0, 128, 64, Logo_AWS);
  delay(3000);

  ssd1306_clearScreen( );
  ssd1306_setFixedFont(ssd1306xled_font5x7);            // Set font type (default 6x8)
  //oled.setTextXY(0,0);              // Set cursor position, start of line 0

  Serial.begin(115200);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

  inicializaAcelerometro();
  inicializaHDC1080();
  init_TSL2571();
  inicializa_MPL3115A2();

  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  inicializa_OTA();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  IPoled();
  connectAWS();
}

void loop() {
  ArduinoOTA.handle();
  testeLeds();
  leAcelerometro();
  le_HDC1080();
  le_MPL3115A2();
  le_voltagem_painelSolar();
  le_TSL2571();
  le_Altitude();
  le_voltagem_bateria();
  le_battery_status();
  userButtonState = digitalRead(23);
  buttonOled();
  publishSensors();  
  client.loop();
}








void connectAWS()
{
/*  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }*/

  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.begin(AWS_IOT_ENDPOINT, 8883, net);

  // Create a message handler
  client.onMessage(messageHandler);

  Serial.print("Connecting to AWS IOT");

  while (!client.connect(THINGNAME)) {
    Serial.print(".");
    delay(100);
  }

  if(!client.connected()){
    Serial.println("AWS IoT Timeout!");
    return;
  }

  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

  Serial.println("AWS IoT Connected!");
}




void publishSensors()
{
  Serial.println("publishing sensors to MQTT");
  StaticJsonDocument<200> doc;
  doc["time"] = millis();
  doc["humidity"] = Umidade;
  doc["temperature"] = Temperatura;
  doc["light"] = Luminosidade;
  doc["altitude"] = Altitude;
  doc["pressure"] = Pressao;
  doc["solarPanelVoltage"] = solarPanelVoltage;
  doc["batteryVoltage"] = batteryVoltage;
  doc["batteryChargeStatus"] = batteryChargeStatus;
  doc["batteryStatusPerCent"] = batteryStatusPerCent;
  doc["X"] = Xacc;
  doc["Y"] = Yacc;
  doc["Z"] = Zacc;

  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer); // print to client

  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void messageHandler(String &topic, String &payload) {
  Serial.println("receiving MQTT message");
  Serial.println("incoming: " + topic + " - " + payload);

//  StaticJsonDocument<200> doc;
//  deserializeJson(doc, payload);
//  const char* message = doc["message"];
}
