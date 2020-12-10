#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "enter-host-name"
#define FIREBASE_AUTH "enter-auth"
#define WIFI_SSID "enter-wifi-ssid"
#define WIFI_PASSWORD "enter-wifi-passwd"
#define swch1 14 //D5
#define swch2 12 //D6
#define swch3 13 //D7
#define swch4 15 //D8
int sw1,sw2,sw3,sw4;

void setup() {
 Serial.begin(115200);
 pinMode(swch1,OUTPUT);
 pinMode(swch2,OUTPUT);
 pinMode(swch3,OUTPUT);
 pinMode(swch4,OUTPUT);
 digitalWrite(swch1,LOW);
 digitalWrite(swch2,LOW);
 digitalWrite(swch3,LOW);
 digitalWrite(swch4,LOW);
 WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
 Serial.print("connecting");
 while(WiFi.status()!=WL_CONNECTED){
   Serial.print(".");
   delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.SetInt("S1",0);
  Firebase.SetInt("S2",0);
  Firebase.SetInt("S3",0);
  Firebase.SetInt("S4",0);
 
 }

 
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }

void loop() {
  if(Firebase.failed())
  {
    Serial.print("setting number failed:");
    Serial.println(Firebase.error());
    firebasereconnect();
    return;
  }
   sw1=Firebase.getString("s1").toInt();
   sw2=Firebase.getString("s2").toInt();
   sw3=Firebase.getString("s3").toInt();
   sw4=Firebase.getString("s4").toInt();

    if(sw1==1){
      digitalWrite(swch1,HIGH);
      Serial.println("Switch 1 ON");
    }
    if(sw1==0){
      digitalWrite(swch1,LOW);
      Serial.println("Switch 1 OFF");
    }
     if(sw2==1){
      digitalWrite(swch2,HIGH);
      Serial.println("Switch 2 ON");
    }
    if(sw2==0){
      digitalWrite(swch2,LOW);
      Serial.println("Switch 2 OFF");
    }
     if(sw3==1){
      digitalWrite(swch3,HIGH);
      Serial.println("Switch 3 ON");
    }
    if(sw3==0){
      digitalWrite(swch3,LOW);
      Serial.println("Switch 3 OFF");
    }
     if(sw1==4){
      digitalWrite(swch4,HIGH);
      Serial.println("Switch 4 ON");
    }
    if(sw4==0){
      digitalWrite(swch4,LOW);
      Serial.println("Switch 4 OFF");
    }
