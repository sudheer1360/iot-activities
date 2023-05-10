#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
DHT dht(D3,DHT11);
float h;
float t;
int rainfall=A0;
char ssid[] = "POCO X4";    // your network SSID (name) 
char pass[] = "12345678";      // your network password
int keyIndex = 0;       // your network key Index number (needed only for WEP)
WiFiClient client;
unsigned long myChannelNumber = 2140845;
const char * myWriteAPIKey = "QGD9WCXZJARAEW69";
String myStatus = "";
void setup() {
Serial.begin(9600);
pinMode(rainfall,INPUT);
dht.begin();
WiFi.mode(WIFI_STA); 
ThingSpeak.begin(client);       // Initialize ThingSpeak
}
void loop() {
if(WiFi.status() != WL_CONNECTED){
Serial.print("Attempting to connect to SSID: ");
while(WiFi.status() != WL_CONNECTED){
WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
Serial.print(".");
delay(5000); 
} 
Serial.println("\nConnected.");
}
h=dht.readHumidity();
t=dht.readTemperature();
if (isnan(h) || isnan(t))
return;
float mp=(100.00-(analogRead(rainfall)/1023.00)*100.00);
Serial.print("Humidity: ");
Serial.print(h);
Serial.print(", Temp: ");
Serial.print(t);
Serial.print(", Rainfall: ");
Serial.print(mp);
// set the fields with the values
ThingSpeak.setField(1, h);
ThingSpeak.setField(2, t);
ThingSpeak.setField(3,mp);
// write to the ThingSpeak channel
int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
if(x == 200){
Serial.println("Channel update successful.");
}
else{
Serial.println("Problem updating channel. HTTP error code " + String(x));
}
delay(20000);  // Wait 20 seconds to update the channel again
}
