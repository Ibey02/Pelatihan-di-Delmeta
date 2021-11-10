
#include <Servo.h>

int outServo=5; //Pin untuk Servo
Servo myservo;
void setup() {
 
 Serial.begin(9600); 
 myservo.attach(outServo); 
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 myservo.write(0); //0-180
 Serial.print(" 0 derajat");
 Serial.println();
 delay(1000); //Jeda waktu perulagan seama 500 mili detik
 myservo.write(90); //0-180
 Serial.print(" 90 derajat");
 Serial.println();
 delay(1000); //Jeda waktu perulagan seama 500 mili detik
}
