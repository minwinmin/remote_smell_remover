#include <Nefry.h>
#include"esp32-hal-ledc.h"

#define PWM_BITWIDTH 16

int deg2pw(int deg, int bit){
    double ms = ((double) deg - 90.0) * 0.95 / 90.0 + 1.45;
    return (int) (ms / 20.0 * pow(2, bit));
}

void setup() {
  Serial.begin(115200);
  ledcSetup(0,50,PWM_BITWIDTH);
  ledcSetup(1,50,PWM_BITWIDTH);
  ledcSetup(2,50,PWM_BITWIDTH);
  ledcSetup(3,50,PWM_BITWIDTH);
  ledcAttachPin(A0,0);
  ledcAttachPin(A1,1);
  ledcAttachPin(D0,2);
  ledcAttachPin(D1,3);

//スイッチ，右側on⇒サーボモータ，サーボホーンが上向き
  Nefry.getWebServer()->on("/on", [&]() {
    String content = F(
      "<!DOCTYPE HTML><html><head><meta charset=\"UTF-8\">"
      "<title>NefryLight Switch</title>"
      "</head><body><div><h1>On</h1>"
      "<a href=\"/\">Back to top</a></div></body></html>");
      
    for(int i=90; i<=115; i++){
      ledcWrite(0,deg2pw(i, PWM_BITWIDTH));
    }
    delay(800);
    ledcWrite(0,deg2pw(90, PWM_BITWIDTH));
    
    Nefry.getWebServer()->send(200, "text/html", content);
  });
  Nefry.setIndexLink("Light_on","/on");

  Nefry.getWebServer()->on("/off", [&]() {
    String content = F(
      "<!DOCTYPE HTML><html><head><meta charset=\"UTF-8\">"
      "<title>NefryLight Switch</title>"
      "</head><body><div><h1>off</h1>"
      "<a href=\"/\">Back to top</a></div></body></html>");
      
    for(int i=90; i>=65; --i){//0～180°の位置で考える，90度が基準点としてそこからどう動くかを考える
      ledcWrite(0,deg2pw(i, PWM_BITWIDTH));
    }
    delay(800);
    ledcWrite(0,deg2pw(90, PWM_BITWIDTH));
    
    Nefry.getWebServer()->send(200, "text/html", content);
  });
  Nefry.setIndexLink("Light_off","/off");

//////////////////////////////////////////////////////////////
  Nefry.getWebServer()->on("/on2", [&]() {
    String content = F(
      "<!DOCTYPE HTML><html><head><meta charset=\"UTF-8\">"
      "<title>NefryLight Switch</title>"
      "</head><body><div><h1>On</h1>"
      "<a href=\"/\">Back to top</a></div></body></html>");
      
    for(int i=90; i<=115; i++){
      ledcWrite(1,deg2pw(i, PWM_BITWIDTH));
    }
    delay(800);
    ledcWrite(1,deg2pw(90, PWM_BITWIDTH));
    
    Nefry.getWebServer()->send(200, "text/html", content);
  });
  Nefry.setIndexLink("Light_on_2","/on2");

  Nefry.getWebServer()->on("/off2", [&]() {
    String content = F(
      "<!DOCTYPE HTML><html><head><meta charset=\"UTF-8\">"
      "<title>NefryLight Switch</title>"
      "</head><body><div><h1>off</h1>"
      "<a href=\"/\">Back to top</a></div></body></html>");
      
    for(int i=90; i>=65; --i){//0～180°の位置で考える，90度が基準点としてそこからどう動くかを考える
      ledcWrite(1,deg2pw(i, PWM_BITWIDTH));
    }
    delay(800);
    ledcWrite(1,deg2pw(90, PWM_BITWIDTH));
    
    Nefry.getWebServer()->send(200, "text/html", content);
  });
  Nefry.setIndexLink("Light_off_2","/off2");

  //////////////////////////////////////////////////////////////
  Nefry.getWebServer()->on("/on3", [&]() {
    String content = F(
      "<!DOCTYPE HTML><html><head><meta charset=\"UTF-8\">"
      "<title>NefryLight Switch</title>"
      "</head><body><div><h1>On</h1>"
      "<a href=\"/\">Back to top</a></div></body></html>");
      
    for(int i=90; i<=115; i++){
      ledcWrite(2,deg2pw(i, PWM_BITWIDTH));
    }
    delay(800);
    ledcWrite(2,deg2pw(90, PWM_BITWIDTH));
    
    Nefry.getWebServer()->send(200, "text/html", content);
  });
  Nefry.setIndexLink("Light_on_3","/on3");

  Nefry.getWebServer()->on("/off3", [&]() {
    String content = F(
      "<!DOCTYPE HTML><html><head><meta charset=\"UTF-8\">"
      "<title>NefryLight Switch</title>"
      "</head><body><div><h1>off</h1>"
      "<a href=\"/\">Back to top</a></div></body></html>");
      
    for(int i=90; i>=65; --i){//0～180°の位置で考える，90度が基準点としてそこからどう動くかを考える
      ledcWrite(2,deg2pw(i, PWM_BITWIDTH));
    }
    delay(800);
    ledcWrite(2,deg2pw(90, PWM_BITWIDTH));
    
    Nefry.getWebServer()->send(200, "text/html", content);
  });
  Nefry.setIndexLink("Light_off_3","/off3");

  //////////////////////////////////////////////////////////////
  Nefry.getWebServer()->on("/on4", [&]() {
    String content = F(
      "<!DOCTYPE HTML><html><head><meta charset=\"UTF-8\">"
      "<title>NefryLight Switch</title>"
      "</head><body><div><h1>On</h1>"
      "<a href=\"/\">Back to top</a></div></body></html>");
      
    for(int i=90; i<=125; i++){
      ledcWrite(3,deg2pw(i, PWM_BITWIDTH));
    }
    delay(800);
    ledcWrite(3,deg2pw(90, PWM_BITWIDTH));
    
    Nefry.getWebServer()->send(200, "text/html", content);
  });
  Nefry.setIndexLink("Light_on_4","/on4");

  Nefry.getWebServer()->on("/off4", [&]() {
    String content = F(
      "<!DOCTYPE HTML><html><head><meta charset=\"UTF-8\">"
      "<title>NefryLight Switch</title>"
      "</head><body><div><h1>off</h1>"
      "<a href=\"/\">Back to top</a></div></body></html>");
      
    for(int i=90; i>=65; --i){//0～180°の位置で考える，90度が基準点としてそこからどう動くかを考える
      ledcWrite(3,deg2pw(i, PWM_BITWIDTH));
    }
    delay(800);
    ledcWrite(3,deg2pw(90, PWM_BITWIDTH));
    
    Nefry.getWebServer()->send(200, "text/html", content);
  });
  Nefry.setIndexLink("Light_off_4","/off4");
  
}

void loop() {
}
