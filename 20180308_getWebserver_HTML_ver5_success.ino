#include <SoftwareSerial.h>
#include <Nefry.h>
SoftwareSerial mySerial(10, 11); // RX, TX
char con[]={0x10,0x21,0x00,0x06,'M','Q','I','s','d','p',0x03,0x02,0x00,0x3c,0x00,0x13,
            'm','o','s','q','s','u','b','/','1','2','5','1','6','-','h','i','r','o','3'};
byte pub[]={  0x30,0x15,0x00,0x06,'s','e','r','v','e','r','/','s','a','m','p','l','e','/','h','e','l','l','o'};
void getResponse(int j){
  int i;
  for (i=0;i<j;i++){
      if (mySerial.available())
         Serial.write(mySerial.read());
      delay(1);
    }
  }
void setup(){
  int i,j;
  Serial.begin(9600);
  mySerial.begin(9600); 
  while(!Serial);
  mySerial.print("AT+RST\r\n");
  getResponse(5000);
  mySerial.print("AT+CIPSTART=\"TCP\",\"192.168.1.16\",1883\r\n");
  getResponse(1000);
  mySerial.print("AT+CIPSEND=35\r\n");
  getResponse(1000);
  for (i=0;i<35;i++)mySerial.write(con[i]);                  
  getResponse(1000); 
}
void loop(){
  mySerial.print("AT+CIPSEND=23\r\n");
  getResponse(1000);  
  for (i=0;i<23;i++)mySerial.write(pub[i]); 
  getResponse(1000);  
  }
