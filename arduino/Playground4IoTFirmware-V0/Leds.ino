void testeLeds(){
  if (direcao == 1){
    digitalWrite(led1,HIGH);
    delay(delayLeds);
    digitalWrite(led2,HIGH);
    delay(delayLeds);
    digitalWrite(led3,HIGH);
    delay(delayLeds);
    digitalWrite(led4,HIGH);
    delay(delayLeds);
    digitalWrite(led1,LOW);
    delay(delayLeds);
    digitalWrite(led2,LOW);
    delay(delayLeds);
    digitalWrite(led3,LOW);
    delay(delayLeds);
    digitalWrite(led4,LOW);
    delay(delayLeds);
    direcao = !direcao;
  }else{
    digitalWrite(led4,HIGH);
    delay(delayLeds);
    digitalWrite(led3,HIGH);
    delay(delayLeds);
    digitalWrite(led2,HIGH);
    delay(delayLeds);
    digitalWrite(led1,HIGH);
    delay(delayLeds);
    digitalWrite(led4,LOW);
    delay(delayLeds);
    digitalWrite(led3,LOW);
    delay(delayLeds);
    digitalWrite(led2,LOW);
    delay(delayLeds);
    digitalWrite(led1,LOW);
    delay(delayLeds);
    direcao = !direcao;
  }
}
