float moistureValue = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  moistureValue = analogRead(A0);
  moistureValue = map(moistureValue, 0, 1023, 100, 0);
  Serial.println("Moisture Value: " + String(moistureValue) + "%");
  
  if (moistureValue < 30) {
    Serial.println("Soil is dry, turning on water pump");
    digitalWrite(D1, HIGH);
    delay(5000);
    digitalWrite(D1, LOW);
    Serial.println("Water pump turned off");
  }
  
  delay(10000);
}
