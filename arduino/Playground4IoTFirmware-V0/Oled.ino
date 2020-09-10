//    ssd1306_printFixed(0,  8, "Normal text", STYLE_NORMAL);
//    ssd1306_printFixed(0, 16, "Bold text", STYLE_BOLD);
//    ssd1306_printFixed(0, 24, "Italic text", STYLE_ITALIC);



void IPoled(){
  ssd1306_printFixed(0, 8, "IP:", STYLE_BOLD);
  ssd1306_printFixed(18,  8,(IPAddress2String(WiFi.localIP()).c_str()) , STYLE_NORMAL);
}



void oledAccelerometer(){
    ssd1306_printFixed(0, 16, "X:", STYLE_BOLD);
    ssd1306_printFixed(12,  16, String(Xacc).c_str(), STYLE_NORMAL);

    ssd1306_printFixed(45, 16, "Y:", STYLE_BOLD);
    ssd1306_printFixed(57,  16, String(Yacc).c_str(), STYLE_NORMAL);

    ssd1306_printFixed(90, 16, "Z:", STYLE_BOLD);
    ssd1306_printFixed(102,  16, String(Zacc).c_str(), STYLE_NORMAL);
}

void oledTempUmi(){
    ssd1306_printFixed(0, 24, "Temp:", STYLE_BOLD);
    ssd1306_printFixed(30,  24, String(Temperatura).c_str(), STYLE_NORMAL);
    ssd1306_printFixed(58,  24, "oC", STYLE_NORMAL);
  
    ssd1306_printFixed(76, 24, "Umi:", STYLE_BOLD);
    ssd1306_printFixed(100,  24, String(Umidade).c_str(), STYLE_NORMAL);
    ssd1306_printFixed(122,  24, "%", STYLE_NORMAL);
}

void oledLuminosidade(){
    ssd1306_printFixed(0, 32, "Luminosidade:", STYLE_BOLD);
    ssd1306_printFixed(72,  32, String(Luminosidade).c_str(), STYLE_NORMAL);
    ssd1306_printFixed(106,  32, "Lux", STYLE_NORMAL);  
}

void oledAltitude(){
    ssd1306_printFixed(0, 40, "Altitude:", STYLE_BOLD);
    ssd1306_printFixed(52,  40, String(Altitude).c_str(), STYLE_NORMAL);
    ssd1306_printFixed(88,  40, "m", STYLE_NORMAL);
}

void oledPressao(){
    ssd1306_printFixed(0, 48, "Pressao:", STYLE_BOLD);
    ssd1306_printFixed(52,  48, String(Pressao).c_str(), STYLE_NORMAL);
    ssd1306_printFixed(100,  48, "Pa", STYLE_NORMAL);
}

void solarPanelOled(){
    ssd1306_printFixed(66, 56, "VpSol:", STYLE_BOLD);
    ssd1306_printFixed(100,  56, String(solarPanelVoltage).c_str(), STYLE_NORMAL);
    ssd1306_printFixed(122,  56, "V", STYLE_NORMAL);
}

void batteryOled(){
    ssd1306_printFixed(0, 56, "Vbat:", STYLE_BOLD);
    ssd1306_printFixed(30,  56, String(batteryVoltage).c_str(), STYLE_NORMAL);
    ssd1306_printFixed(52,  56, "V", STYLE_NORMAL);

  if (batteryChargeStatus == true){
    ssd1306_printFixed(107,  8, "FULL", STYLE_NORMAL);
  }else{
    ssd1306_printFixed(107,  8, "    ", STYLE_NORMAL);
  }
  
}

void buttonOled(){
  if(userButtonState == 0){
    ssd1306_printFixed(107,  8, "USER", STYLE_NORMAL);
  }else{
    ssd1306_printFixed(107,  8, "    ", STYLE_NORMAL);
  }
}


String IPAddress2String(IPAddress address){
 return String(address[0]) + "." + 
        String(address[1]) + "." + 
        String(address[2]) + "." + 
        String(address[3]);
}
