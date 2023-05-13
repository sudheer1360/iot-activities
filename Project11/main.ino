int sensorPin = A0;  // Soil moisture sensor connected to analog pin A0
int threshold = 500;  // Moisture level threshold

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int moisture = analogRead(sensorPin);  // Read soil moisture level
  Serial.print("Moisture level: ");
  Serial.print(moisture);
  if (moisture < threshold) {
    Serial.println("Water needed!");  // Print message if moisture level is below threshold
  } else {
    Serial.println(" Water is not needed");  // Print newline character if moisture level is above threshold
  }
  delay(1000);  // Wait for 1 second
}
