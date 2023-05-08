#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   
#include <ArduinoJson.h>
#include<Servo.h>

// Replace with your network credentials
const char* ssid = "Airtel-MyWiFi-AMF-311WW-6BAC";
const char* password = "1092ca62";

// Initialize Telegram BOT
#define BOTtoken "6030559283:AAHhCTEKPyEFetI5_Fes8cfCxfcH5m9aLmc"  // your Bot Token (Get from Botfather)

#define CHAT_ID "5281166334"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

Servo a;

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use the following commands to control your outputs.\n\n";
      welcome += "/on to on the Servo motor \n";
      welcome += "/off to off the Servo motor  \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/on") {
      bot.sendMessage(chat_id, "Servo Motor Is ON", "");
      
      for(int i=0;i<90;i++){
        a.write(i);
        delay(10);
      }
      
    }
    
    if (text == "/off") {
      bot.sendMessage(chat_id, "Servo Motor is OFF", "");
     for(int i=90;i>0;i--){
      a.write(i);
      delay(10);
     } 
     }
    
    
  }
}

void setup() {
  Serial.begin(9600);
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  a.attach(D0);
  
  
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected");
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
