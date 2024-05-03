#ifndef LiquidCrystalOn
#define LiquidCrystalOn

#include <LiquidCrystal_I2C.h>  // including header

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
// (주소값, 16x2 디스플레이)

String prevSoilTemp = ""; // 온도, 토양습도 이전 값

void onLiquidCrystal(float temp, int soilHum, String utcTime);

void onLiquidCrystal(float temp, int soilHum, String utcTime) {
  String strSoilHum = "S " + String(soilHum) + "%";              // 토양 습도
  String strTemp = "T " + String(temp) + "C" + " " + strSoilHum; // 대기 중 온도

  // 최초 실행 시 온도, 토양습도를 LCD 에 표시하도록 함
  if(prevSoilTemp == ""){
    prevSoilTemp = strTemp;
  }

  // 온도, 토양습도를 10초마다 갱신하기
  // 10초가 되기 전까진 이전 data 를 LCD 에 계속 출력해줌
  if(utcTime.substring(12,14).toInt() % 10 == 0){   // 온도, 습도는 10초마다 갱신
    lcd.setCursor(1,0);         // 커서 옮김. 1행에 0열
    lcd.print(strTemp);         // 대기 중 온도, 토양습도 수치 출력

    lcd.setCursor(1,1);         // Move cursor to character 2 on line 1	// 커서 옮김. 1행에 1열
    lcd.print(utcTime);         // UTC Time 출력
    prevSoilTemp = strTemp;     // 갱신되기 전까지 출력할 이전 data
  }else{
    lcd.setCursor(1,0);         
    lcd.print(prevSoilTemp);   

    lcd.setCursor(1,1);        
    lcd.print(utcTime);        
  }
  
}

#endif