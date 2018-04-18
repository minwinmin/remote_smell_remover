#include<Nefry.h>
#include"esp32-hal-ledc.h"
#define PWM_BITWIDTH 16

void setup() {
  ledcSetup(1,50,PWM_BITWIDTH);;
  ledcAttachPin(A2,1);
  Nefry.enableSW();
}

void loop() {
  ledcWrite(1,deg2pw(0, PWM_BITWIDTH));

  if((Nefry.readSW())){
   for(int i=0; i<=90; i++){
      ledcWrite(1,deg2pw(i, PWM_BITWIDTH));
   }
  }
  delay(5000);
}

int deg2pw(int deg, int bit){
    double ms = ((double) deg - 90.0) * 0.95 / 90.0 + 1.45;
    return (int) (ms / 20.0 * pow(2, bit));
}
