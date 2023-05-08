int soil=D0;
int alcohol=A0;
int threshold=1;
void setup(){
  pinMode(soil,INPUT);
  pinMode(alcohol,INPUT);
  Serial.begin(9600);
}
void loop(){
  int m= digitalRead(soil);
  Serial.println(m);
  if(m==threshold){
    Serial.println("dry soil");
  }
  else{
    Serial.println("wet soil");
  }
  int s= analogRead(alcohol);
  Serial.println(s);
  if(s>400){
  Serial.println("less");
  }
  else{
  Serial.println("Drunk");
  }
  delay(1000);
}
