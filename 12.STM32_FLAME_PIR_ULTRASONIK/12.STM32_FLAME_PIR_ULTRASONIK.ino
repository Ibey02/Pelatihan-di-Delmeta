#include<NewPing.h>
//INISIALISASI
int sensorFlame = PA0;
int sensorPIR = PA1;
int merah = PA2;
int kuning = PA3;
int hijau = PA4;
int echo = PA5;
int triger = PA6;
int batas = 400;

NewPing cm(triger,echo,batas);

void setup() {
  Serial.begin(9600);
  pinMode(sensorFlame,INPUT);
  pinMode(sensorPIR,INPUT);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  
}

void loop() {
  //BACA DATA
  int bacaJarak = cm.ping_cm();
  int bacasensorFlame = analogRead(sensorFlame);
      bacasensorFlame = map(bacasensorFlame,4095,150,0,255);
  int bacasensorPIR = digitalRead(sensorPIR);
  //

  
  //SERIAL PRINT
  Serial.print("NILAI SENSOR FLAME :");
  Serial.print(bacasensorFlame);
  Serial.println();
  Serial.print("NILAI SENSOR PIR :");
  Serial.print(bacasensorPIR);
  Serial.println();
  Serial.print("DATA JARAK :");
  Serial.print(bacaJarak);
  Serial.print("cm");
  Serial.println();
  delay(200);

  //LOGIKA PIR
  if (bacasensorPIR == 1){
    digitalWrite(kuning,HIGH);
  }else{
    digitalWrite(kuning,LOW);
  }
  //LOGIKA FLAME
  if (bacasensorFlame<=100){
    noflame();
  }
  else if (bacasensorFlame>=101 && bacasensorFlame<=200){
    midleflame();
  }
  else if (bacasensorFlame>=201){
    strongflame();
  }
  //LOGIKA ULTRASONIK
  if (bacaJarak<=10 && bacaJarak!=0){
    jaraksangatdekat();
  }
  else if (bacaJarak>=11 && bacaJarak<=25){
    jarakdekat();
  }
  else if (bacaJarak>=25){
    jarakjauh();
  }
}

  void noflame(){
  digitalWrite(merah,HIGH);
  delay(200);
  }

  void midleflame(){
  digitalWrite(merah,HIGH);
  delay(200);
  digitalWrite(merah,LOW);
  delay(200);
  }

  void strongflame(){
  digitalWrite(merah,HIGH);
  delay(100);
  digitalWrite(merah,LOW);
  delay(100);
  }

  void jarakjauh(){
  digitalWrite(hijau,HIGH);
  delay(200);
  }

  void jarakdekat(){
  digitalWrite(hijau,HIGH);
  delay(200);
  digitalWrite(hijau,LOW);
  delay(200);
  }

  void jaraksangatdekat(){
  digitalWrite(hijau,HIGH);
  delay(100);
  digitalWrite(hijau,LOW);
  delay(100);
  }
