//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>

String uidString;

int buzzer = 2;
int sensorIR = 3;
int kunci = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);


void setup() {
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(sensorIR, INPUT);
SPI.begin();
mfrc522.PCD_Init();
 
}

void loop() {
  //LOGIKA
  int bacaIR = digitalRead(sensorIR);
  
  if(mfrc522.PICC_IsNewCardPresent()&& kunci==0){
    readRFID();
    Serial.print("Tag UID = ");
    Serial.println(uidString);
    
    if(uidString=="74-81-110-174"){
      buzzertrue();
     Serial.print("BERHASIL");
     Serial.println();
    kunci=1;
    }
    else if(uidString!="74-81-110-174"){
    buzzerfalse();
    Serial.print("Kartu Tidak Terdaftar");
    Serial.println();
    }
  
  }
  if(bacaIR==0 && kunci==1){
    Serial.print("Palang Ditutup");
    delay(500);
    Serial.println();
    Serial.print("Selamat Datang");
    Serial.println();
    kunci=0;
  }
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  // Sound the Buzzer when a card read
  //pembatas sesuai keinginan + "-" +
  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
  uidString.toUpperCase();
}

void buzzertrue(){
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(100);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(100);
}

void buzzerfalse(){
digitalWrite(buzzer,HIGH);
delay(500);
digitalWrite(buzzer,LOW);
delay(500);
}
