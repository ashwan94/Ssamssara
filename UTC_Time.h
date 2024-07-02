#ifndef UTC
#define UTC

char curTime[20];

String getUtcTime();
String getUtcTime() {
  time_t now = time(nullptr);
  struct tm *t;
  t = localtime(&now);
 
  sprintf(curTime,"%04d-%02d-%02d %02d:%02d:%02d", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
  String liveTime = curTime;
  String year = liveTime.substring(0,4);     // year
  String month = liveTime.substring(5,7);    // month
  String day = liveTime.substring(8,10);     // day
  String hour = liveTime.substring(11,13);   // hour
  String minute = liveTime.substring(14,16); // minute
  String second = liveTime.substring(17,19); // second
  String utcTime = month + "." + day + " " + hour + ":" + minute + ":" + second; // LCD 에 짤려서 나오므로 우선 year 를 제외하고 출력함
  // Serial.println(year + "." + month + "." + day + " " + hour + ":" + minute + ":" + second);
  return utcTime;
}

#endif