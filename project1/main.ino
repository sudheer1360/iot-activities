#include<ESP8266WiFi.h>
#include<WiFiClientSecure.h>
#include<UniversalTelegramBot.h>
#include<ArduinoJson.h>
#define botToken "6030559283:AAHhCTEKPyEFetI5_Fes8cfCxfcH5m9aLmc"
#define chat_id "5281166334"
char* ssid="Airtel-MyWiFi-AMF-311WW-6BAC";
char* password="1092ca62";
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(botToken,client);
int sensor=A0;
int threshold=100;
void setup()
{
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  configTime(0,0,"pool.ntg.org");
  client.setTrustAnchors(&cert);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("wifi connected");
}
void loop(){
  int m=analogRead(sensor);
  Serial.println(m);
  if(m>threshold)
{
bot.sendMessage(chat_id,"alert");
}
}
