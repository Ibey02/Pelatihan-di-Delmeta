#include<NewPing.h>

//LOGIKA
int sensorPIR = PA0;
int merah = PA1;
int kuning = PA2;
int hijau= PA3;
int echo = PA4;
int triger = PA5;
int sensorFlame = PA6;
int batas = 400;
int kunci = 0;
int kunci1=0;

NewPing cm(triger,echo,batas);

void setup() {
  Serial.begin(9600);
  pinMode(sensorPIR,INPUT);
  pinMode(sensorFlame,INPUT);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  
}

void loop() {
  //BACA DATA
  int bacajarak = cm.ping_cm();
  int bacasensorPIR = digitalRead(sensorPIR);
  int bacasensorFlame = digitalRead(sensorFlame);
      bacasensorFlame = map(bacasensorFlame,4095,150,0,255);

   Serial.print("sensorultrasonik :");
   Serial.print(bacajarak);
   Serial.println();
     Serial.print("KUNCI:");
    Serial.print(kunci);
    Serial.println();
    Serial.print("pir:");
    Serial.print(bacasensorPIR);
    Serial.println();
  
  //LOGIKA
  if (bacasensorPIR ==1 || bacasensorFlame>=200 && kunci==0){
    Serial.print("Sensor ULTRASONIK aktif");
    Serial.println();
    
    delay(1000);
    kunci=1;
  }
  else if (bacasensorPIR ==1 || bacasensorFlame>=200 && kunci==1){
    digitalWrite(merah,LOW);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,LOW);
    Serial.print("Sensor ULTRASONIK tidak aktif");
    Serial.println();
  }
 

  if (bacajarak>=40 && kunci==1){
    jarakjauh();
  }
  else if (bacajarak>=20 && bacajarak<=39 && kunci==1){
    jarakdekat();
  }
  else if (bacajarak<=20 && bacajarak!=0 && kunci==1){
    jaraksangatdekat();
  }
 
}

void jarakjauh(){
  digitalWrite(merah,HIGH);
  digitalWrite(kuning,LOW);
  digitalWrite(hijau,LOW);
  delay(100);
  digitalWrite(merah,LOW);
  digitalWrite(kuning,HIGH);
  digitalWrite(hijau,LOW);
  delay(100);
  digitalWrite(merah,LOW);
  digitalWrite(kuning,LOW);
  digitalWrite(hijau,HIGH);
  delay(100);
  digitalWrite(merah,LOW);
  digitalWrite(kuning,HIGH);
  digitalWrite(hijau,LOW);
}

void jarakdekat(){
  digitalWrite(merah,HIGH);
  digitalWrite(kuning,HIGH);
  digitalWrite(hijau,HIGH);
  delay(1000);
  digitalWrite(merah,LOW);
  digitalWrite(kuning,LOW);
  digitalWrite(hijau,LOW);
  delay(1000);
}

void jaraksangatdekat(){
  digitalWrite(merah,HIGH);
  digitalWrite(kuning,HIGH);
  digitalWrite(hijau,HIGH);
  delay(100);
  digitalWrite(merah,LOW);
  digitalWrite(kuning,LOW);
  digitalWrite(hijau,LOW);
  delay(100); 
}
