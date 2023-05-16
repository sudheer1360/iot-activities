int ir1=D2;
int ir2=D3;
int count;
void setup(){
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  Serial.begin(9600);
}
void loop(){
  if(digitalRead(ir1)==0)
  {
    while(digitalRead(ir2)==1)
      delay(10);
    count++;
    delay(1000);
  }
  if(digitalRead(ir2)==0)
  {
    while(digitalRead(ir1)==1)
      delay(10);
    count--;
    delay(1000);
  }
Serial.println(count);
}
