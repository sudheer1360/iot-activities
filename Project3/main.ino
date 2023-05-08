#include<ESP8266WiFi.h> 
#include<ThingSpeak.h>
int channel=2130376;
char* apikey="D16O6115IUCG1N22";
char* ssid="POCO X4";
char* password="12345678";
WiFiClient Client;
int alcohol=A0;
int threshold=50;
void setup() {
  pinMode(alcohol,INPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
    Serial.println("wifi connected");
    ThingSpeak.begin(Client);
}
void loop() {
  int m= analogRead(alcohol);
  Serial.println(m);
  ThingSpeak.setField(1,m);
  int status=ThingSpeak.writeFields(channel,apikey);
  if(m>threshold){
    Serial.println("Alcohol is detected");
  }
  else{
    Serial.println("normal");
  }

}
