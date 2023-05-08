

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
int threshold=1000; 
// Replace with your network credentials
const char* ssid = "aaa";
const char* password = "Vasu1234";
// Initialize Telegram BOT
#define BOTtoken "6131311679:AAFtFqObAGIQytyBfSB23_NPdVTc0kAm2vY" // your 

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "1349211181"
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
const int fireSensor = A0; // Fire Sensor
const int buzzer=D3;
void setup() {
 Serial.begin(115200);
 configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
 client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
 pinMode(fireSensor, INPUT);
 pinMode(buzzer,OUTPUT);
 // Attempt to connect to Wifi network:
 Serial.print("Connecting Wifi: ");
 Serial.println(ssid);
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 Serial.print(".");
 delay(500);
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.print("IP address: ");
 Serial.println(WiFi.localIP());
}
void loop() {
 int m=analogRead(fireSensor);
 Serial.print("Value: ");
 Serial.println(m);
 if(m<threshold) {
 bot.sendMessage(CHAT_ID,"FIRE DETECTED","");
 delay(5000);
 }
 delay(500);
}
