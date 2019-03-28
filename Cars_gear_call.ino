
#include "MPU9250.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>
#include <ESP8266HTTPClient.h>
// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;
char ssid[]="ssid name";
char pass[]="password";
double x,y,z;
HTTPClient http;
void post(int gear1,int gear2){
  String  data=String(gear1)+String(gear2);//gear1 represents divisions for first wheel and gear 2 for second wheel since both wheels can be controlled
  if((WiFi.status()==WL_CONNECTED)){
  http.begin("http://192.168.43.116/hold");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");//content type is such that string can e passed through the http server you created
  Serial.println(data);
  int t= http.POST("p="+data);
  http.writeToStream(&Serial);
  Serial.println(t);  
  http.end();
  }    
}
void setup() {
  Serial.begin(9600);
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pass);
  while((WiFi.status()!=WL_CONNECTED)){
    Serial.println(".");
  delay(1000);
  }
  Serial.println("connected");
  while(!Serial) {}
IMU.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  status = IMU.begin();
  //Serial.println("write1");
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    status = IMU.begin();
    while(1) {}
  }
}
void loop() {
  IMU.readSensor();
  x=IMU.getAccelX_mss();
  y=IMU.getAccelY_mss();
  z=IMU.getAccelZ_mss();
  Serial.print(IMU.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getAccelZ_mss(),6);
  Serial.println("\t");
  //After  recieving data from IMU sensors we need to just focus on division in discrete speed levels  
  int v=(x<5)?0:4;
  x=x>0?x:-x;
  int gear1,gear2;
  if(x<5){
    gear1=0;
    gear2=0;
  }else{
  if((x>5)&&(x<6.5)){
    gear1=1+v;
    gear2=1+v;
    }
    if((x>6.5)&&(x<8)){
    gear1=2+v;
    gear2=2+v;
    }
    if((x>8)&&(x<9.0)){
    gear1=3+v;
    gear2=3+v;
    }
    if(x>9.0){
    gear1=4+v;
    gear2=4+v;
    }}
    //here speeds are divided to rigth left orientation
    //*divisions are to be done according to orientation of mpu sensor and the speed limits of motors
     
    int t;
    t=(y<5)?1:-1;
    y=y>0?y:-y;
    int s;
    if(y<5){
    s=0;
  }else{
  if((y>5)&&(y<6.5)){
    s=1*t;
    }
    if((y>6.5)&&(y<8)){
    s=2*t;
    }
    if((y>8)&&(y<9)){
    s=3*t;
    }
    if(y>9){
    s=4*t;
    }}
    if(gear1+s>v+4){
      gear1=v+4;
    }else if(gear1+s<v){
      gear1=4-(gear1+s);
    }else{
      gear1=gear1+s;
    }
    if(gear2-s>v+4){
      gear2=v+4;
    }else if(gear2-s<v){
      gear2=4-(gear2-s);
    }else{
      gear2=gear2-s;
    }
    post(gear1,gear2);
}
