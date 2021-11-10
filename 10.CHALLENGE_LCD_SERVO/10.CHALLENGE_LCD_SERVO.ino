//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String uidString;

int buzzer = 2;
int sensorIR = 3;
int kunci = 0;
int outServo=5;
Servo myservo;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);


void setup() {
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(sensorIR, INPUT);
SPI.begin();
lcd.begin();
mfrc522.PCD_Init();
myservo.attach(outServo); 

lcd.clear();
lcd.setCursor(0,0); lcd.print("SISTEM DIMULAI");
myservo.write(0);
delay(1000);
}

void loop() {
  //LOGIKA
  int bacaIR = digitalRead(sensorIR);
  
  if(mfrc522.PICC_IsNewCardPresent()&& kunci==0){
    readRFID();
    Serial.print("Tag UID = ");
    Serial.println(uidString);
    
    if(uidString=="74-81-110-174"){
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("     BERHASIL");
      lcd.setCursor(0,1); lcd.print(" PALANG TERBUKA");
      delay(200);
      buzzertrue();
      myservo.write(90); //0-180
      Serial.print(" 90 derajat");
      Serial.println();
      delay(800);
     Serial.print("BERHASIL");
     Serial.println();
    kunci=1;
    }
    else if(uidString!="74-81-110-174"){
    buzzerfalse();
    Serial.print("Kartu Tidak Terdaftar");
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("  KARTU TIDAK");
    lcd.setCursor(0,1); lcd.print("  TERDAFTAR");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("TEMPELKAN  KARTU");
    Serial.println();
    }
  
  }
  if(bacaIR==0 && kunci==1){
    Serial.print("Palang Ditutup");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("PALANG  TERTUTUP");
    myservo.write(0); //0-180
    Serial.print(" 0 derajat");
    Serial.println();
    delay(1000);
    lcd.clear();
    Serial.println();
    Serial.print("TEMPELKAN  KARTU");
    lcd.setCursor(0,0); lcd.print("TEMPELKAN  KARTU");
    delay(500);
    Serial.println();
    kunci=0;
  }
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  // Sound the Buzzer when a card read
  //pembatas sesuai keinginan + "-" +
  uidString = String(mfrc522.uid.uidByte[0]) + "-" +
              String(mfrc522.uid.uidByte[1]) + "-" +
              String(mfrc522.uid.uidByte[2]) + "-" +
              String(mfrc522.uid.uidByte[3]);

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
