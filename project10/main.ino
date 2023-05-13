#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

#define TRIGGER_PIN D1  // Trigger pin of the ultrasonic sensor
#define ECHO_PIN D2     // Echo pin of the ultrasonic sensor

// WiFi settings
const char* ssid = "Redmi";
const char* password = "123456789";
WiFiClient client;
int channelid=2144908;
// ThingSpeak settings
const char* apiKey = "VFY25ALY0R6WE0TT";

void setup() {
  Serial.begin(9600); // Start the serial communication
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); // Connect to WiFi network
  while(WiFi.status()!=WL_CONNECTED){//wait until wifi is connected
    Serial.print(".");
    delay(1000);
  }
  ThingSpeak.begin(client);   // Initialize ThingSpeak client
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // Calculate the distance in cm
  
  if (distance < 20) { // If the dustbin is full
    // Upload data to ThingSpeak
    ThingSpeak.setField(1, 1); // Field 1 for dustbin status (1=full, 0=empty)
    int status = ThingSpeak.writeFields(channelid,apiKey);

    if (status == 200) {
      Serial.println("Data uploaded to ThingSpeak!");
    } else {
      Serial.println("Failed to upload data to ThingSpeak!");
    }
  }
  
  delay(20000); // Wait for next upload interval
}
