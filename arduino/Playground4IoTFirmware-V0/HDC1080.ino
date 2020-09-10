void inicializaHDC1080(){
  Serial.println("Inicializando HDC1080");
 
// Default settings:
// - Heater off
// - 14 bit Temperature and Humidity Measurement Resolutions
hdc1080.begin(0x40);
 
Serial.print("Manufacturer ID=0x");
Serial.println(hdc1080.readManufacturerId(), HEX); // 0x5449 ID of Texas Instruments
Serial.print("Device ID=0x");
Serial.println(hdc1080.readDeviceId(), HEX); // 0x1050 ID of the device

}

void le_HDC1080(){
  Serial.print("T=");
  Temperatura = hdc1080.readTemperature();
  Serial.print(String(Temperatura));
  Serial.print("oC, RH=");
  Umidade = hdc1080.readHumidity();
  Serial.print(Umidade);
  Serial.println("%");
  oledTempUmi();
}
