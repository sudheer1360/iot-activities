int trig=D0;
int echo=D1;
int buzzer=D2;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  long duration = pulseIn(echo, 1);
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance > 120) {
    Serial.println("A big pot hole detected");
    digitalWrite(buzzer, 1);
    delay(2000);
 
  } else if (distance > 60) {
    digitalWrite(buzzer, 1);
    Serial.println("A small pot hole ditected");
    delay(500);
  }
  else {
    Serial.println("No pot hole detected");
    digitalWrite(buzzer,0);
  }
  delay(1000);
}
