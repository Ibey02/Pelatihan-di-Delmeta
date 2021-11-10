#include<NewPing.h>

//INISIALISASI
int echo = 4;
int triger = 5;
int batas = 200;
int pinBuzzer = 3;
int pinR = 6;
int pinY = 7;
int pinG = 8;

NewPing cm(triger,echo,batas);


void setup() {
Serial.begin(9600);
pinMode(pinBuzzer,OUTPUT);
pinMode(pinR,OUTPUT);
pinMode(pinY,OUTPUT);
pinMode(pinG,OUTPUT);

}

void loop() {
//BACA DATA
int bacaJarak=cm.ping_cm();

//PRINT SERIAL
Serial.print("Data Jarak = ");
Serial.print(bacaJarak);
Serial.print(" cm");
Serial.println();
delay(500);

//LOGIKA
if (bacaJarak<=20 && bacaJarak!=0){
  Serial.print("BERHENTI");
  Serial.println();
  digitalWrite(pinR,HIGH);
  digitalWrite(pinY,LOW);
  digitalWrite(pinG,LOW);
  digitalWrite(pinBuzzer,HIGH);
  delay(50);
  digitalWrite(pinBuzzer,LOW);
  delay(50);
}
else if(bacaJarak>=21 && bacaJarak<=50){
  Serial.print("BAHAYA");
  Serial.println();
  digitalWrite(pinR,LOW);
  digitalWrite(pinY,HIGH);
  digitalWrite(pinG,LOW);
  digitalWrite(pinBuzzer,HIGH);
  delay(250);
  digitalWrite(pinBuzzer,LOW);
  delay(250);
}
if (bacaJarak>=51){
  Serial.print("AMAN");
  Serial.println();
  digitalWrite(pinY,LOW);
  digitalWrite(pinR,LOW);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinBuzzer,LOW);
}
}
