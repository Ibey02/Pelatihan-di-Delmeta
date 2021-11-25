//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

String uidString;

int sensorIR = PA0;
int outServo = PA1;
int kunci = 0; 
#define SS_PIN PB1
#define RST_PIN PB0
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
Serial.begin(9600);
lcd.begin();
pinMode(sensorIR, INPUT);
SPI.begin();
mfrc522.PCD_Init();
myservo.attach(outServo);
 
}

void loop() {
  //LOGIKA
  int bacaIR = digitalRead(sensorIR);
  
  if(mfrc522.PICC_IsNewCardPresent()&& kunci==0){
    readRFID();
    Serial.print("Tag UID = ");
    Serial.println(uidString);
    
    if(uidString=="8A-B0-C1-15"){
    myservo.write(90);
    lcd.clear();
    lcd.setCursor(0,0);lcd.print("BERHASIL");
    delay(700);
    lcd.clear();
    lcd.setCursor(0,0);lcd.print("  HATI - HATI");
    lcd.setCursor(0,1);lcd.print("    DIJALAN  ");
    Serial.print("BERHASIL");
    Serial.println();
    kunci=1;
    }
    else if(uidString!="8A-B0-C1-15"){
    lcd.clear();
    lcd.setCursor(0,0);lcd.print("KARTU TIDAK");
    lcd.setCursor(0,1);lcd.print("TERDAFTAR");
    delay(300);
    lcd.clear();
    lcd.setCursor(0,0);lcd.print("TEMPELKAN  KARTU");
    Serial.print("Kartu Tidak Terdaftar");
    Serial.println();
    }
  
  }
  if(bacaIR==0 && kunci==1){
    myservo.write(0);
    delay(700);
    lcd.clear();
    lcd.setCursor(0,0);lcd.print("SELAMAT DATANG");
    lcd.setCursor(0,1);lcd.print("TEMPELKAN  KARTU");
    Serial.print("Palang Ditutup");
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
