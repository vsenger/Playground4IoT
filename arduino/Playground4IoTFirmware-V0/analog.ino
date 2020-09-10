void le_voltagem_painelSolar(){
  unsigned int ADC1=analogRead(35);
  Serial.print("ADC1:");
  Serial.println(ADC1);
  float leitura = (ADC1 * 3.3) / 4096.0;   
  Serial.print("leitura:");
  Serial.println(leitura);
  //float solarPanelVoltage = temp / (R17/(R18+R17));   
  solarPanelVoltage = ((leitura/(143000.0/(293000.0+143000.0))));  
  Serial.print("solarPanelVoltage:");
  Serial.println(String(solarPanelVoltage));
  solarPanelOled();
}


void le_voltagem_bateria(){
  unsigned int ADC1=analogRead(32);
  Serial.print("ADC1:");
  Serial.println(ADC1);
  float leitura = (ADC1 * 3.3) / 4096.0;   
  //float batteryVoltage = temp / (R22/(R21+R22));   
  batteryVoltage = leitura / (10000000.0/(4000000.0+10000000.0));   
  Serial.print("baterryVoltage:");
  Serial.println(String(batteryVoltage));
  batteryOled();
}

void le_battery_status(){
  batteryChargeStatus = (digitalRead(batteryStatusPin));
}

void le_battery_percent(){
  batteryStatusPerCent = map((batteryVoltage*100),280,420,0,100);
}
