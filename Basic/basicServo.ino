#include<Servo.h>
Servo sr;
void setup() {
  // put your setup code here, to run once:
  sr.attach(13);
}

void loop() {
  // put your main code here, to run repeatedly:
  sr.write(0);
  delay(500);
  sr.write(90);
  delay(3000);
  sr.write(180);
  delay(2000);
  for(int i=180; i>0; i=i-5){
    sr.write(i);
    delay(200);
  }
}
