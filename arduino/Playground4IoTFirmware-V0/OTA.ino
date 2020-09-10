void inicializa_OTA(){
    // Port defaults to 3232
  // ArduinoOTA.setPort(3232);

  // Hostname defaults to esp3232-[MAC]
   ArduinoOTA.setHostname(hostName);

  // No authentication by default
   ArduinoOTA.setPassword("aws@2020");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
      ssd1306_128x64_i2c_init();                     // Initialze SSD1306 OLED display
      ssd1306_clearScreen( );
      ssd1306_setFixedFont(ssd1306xled_font6x8);            // Set font type (default 6x8)
      ssd1306_printFixed(10, 8, "Firmware Uploading", STYLE_BOLD);

    })
    .onEnd([]() {
      Serial.println("\nEnd");
      ssd1306_setFixedFont(ssd1306xled_font6x8);            // Set font type (default 6x8)
      ssd1306_printFixed(0, 48, "Completed", STYLE_BOLD);
      ssd1306_printFixed(0, 56, "Restarting ...", STYLE_BOLD);

    })
    .onProgress([](unsigned int progress, unsigned int total) {
      ssd1306_setFixedFont(ssd1306xled_font8x16);            // Set font type (default 6x8)
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));

      ssd1306_printFixed(50, 24, String(progress / (total / 100)).c_str(), STYLE_BOLD);

      ssd1306_printFixed(78, 24, "%", STYLE_NORMAL);
      
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();
}
