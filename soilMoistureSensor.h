#ifndef SoilMoisture
#define SoilMoisture

const int soilSensor = A0;    // 토양습도센서
// const int waterPump = D5;     // 워터펌프
const int moistureLED = D6;   // 토양습도 LED

int getSoilMoisture();

int getSoilMoisture() {
  int soilValue = analogRead(soilSensor);              // 토양수분센서값 읽기
  int soilPercent = map(soilValue, 170, 1023, 100, 0); // 170 ~ 1023 에 대한 value 를 100 ~ 0% 로 매핑, 170에 가까울수록 수분 많음

  // 토양습도가 60% 이하일 경우 워터펌프 작동
  if(soilPercent < 60){
    Serial.print("토양습도 : ");
    Serial.print(soilPercent);
    Serial.println("%, 수분 공급이 필요합니다");
    digitalWrite(moistureLED, HIGH);
    // digitalWrite(waterPump, HIGH);
  }else{
    Serial.print("토양습도 : ");
    Serial.print(soilPercent);
    Serial.println("%");
    // Serial.println("수분 충분");
    // digitalWrite(waterPump,LOW);
    digitalWrite(moistureLED, LOW);
  }
  return soilPercent;
}

#endif