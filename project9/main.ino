int ir=D0;
int buzzer=D3;
void setup(){
  pinMode(ir,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int m=digitalRead(ir);
  Serial.println(m);
  if(m==0){
    Serial.println("object is detected");
    digitalWrite(buzzer,1);
  }
  else{
    Serial.println("normal");
    digitalWrite(buzzer,0);
  }
  delay(100);
}
