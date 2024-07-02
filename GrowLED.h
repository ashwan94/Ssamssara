#ifndef GrowLED
#define GrowLED

const int growLED = D7;        // 식물 생장 LED
const int growLEDRelay = D3;   // 식물 생장 LED 컨트롤하는 Relay

bool controllGrowLED();

// 식물 피로도를 감안해 생장 LED 를 14시간 쬐어주고, 밤이 될때 10시간은 쉬게 해줌
bool controllGrowLED(String getTime, bool ledRelayStatus) {
  String hour = getTime.substring(6,8);
  String minute = getTime.substring(9,11);
  String second = getTime.substring(12,14);

  // 매일 아침 8시마다 생장 LED 켜기
  if(hour == "08" && minute == "00" && second == "00"){
    digitalWrite(growLEDRelay, HIGH);
    ledRelayStatus = true;
    Serial.println("아침 8시가 되었으므로 식물 생장 LED 를 켭니다");
  }
  
  // 매일 밤 22시(10시)마다 LED 끄기
  if(hour == "22" && minute == "00" && second == "00"){
    digitalWrite(growLEDRelay, LOW);
    ledRelayStatus = false;
    Serial.println("밤 10시가 되었으므로 식물 생장 LED 를 끕니다");
  }

  return ledRelayStatus;
}

#endif