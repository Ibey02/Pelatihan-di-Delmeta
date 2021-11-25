int merah = PA0;
int kuning = PA1;
int hijau = PA2;
int sensorIR = PA3;
int sensorLDR = PA4;
int kunci1 = 0; 


void setup() {
Serial.begin(9600);
pinMode(PA0,OUTPUT);
pinMode(PA1,OUTPUT);
pinMode(PA2,OUTPUT);
pinMode(sensorIR,INPUT);
pinMode(sensorLDR,INPUT);
}


void loop() {
//BACA DATA
int bacasensorIR = digitalRead(sensorIR);
int bacasensorLDR = analogRead(sensorLDR);
    bacasensorLDR = map(bacasensorLDR,100,4095,0,255);

//SERIAL PRINT

//LOGIKA
if (bacasensorIR==0 && kunci1==0){
  
  Serial.print("SENSOR LDR AKTIF");
  Serial.println();
  Serial.print("BACA SENSOR LDR :");
  Serial.print(bacasensorLDR);
  kunci1=1;
  delay(200);
  
}
else if (bacasensorIR==0 && kunci1==1){
  digitalWrite(merah,LOW);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,LOW);
Serial.print("SENSOR LDR TIDAK AKTIF");
Serial.println();
delay(200);
kunci1=0;
}
  if(bacasensorLDR <=100 && kunci1==1){
    digitalWrite(merah,LOW);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,HIGH);
  Serial.print("BACA SENSOR LDR :");
  Serial.print(bacasensorLDR);
  Serial.println();
  }
  else if(bacasensorLDR >=101 && bacasensorLDR <=200 && kunci1==1){
    digitalWrite(kuning,HIGH);
    digitalWrite(merah,LOW);
    digitalWrite(hijau,LOW);
     Serial.print("BACA SENSOR LDR :");
  Serial.print(bacasensorLDR);
  Serial.println();
  }
  if(bacasensorLDR >=201 && bacasensorLDR <=255 && kunci1==1){
    digitalWrite(hijau,LOW);
    digitalWrite(kuning,LOW);
    digitalWrite(merah,HIGH);
     Serial.print("BACA SENSOR LDR :");
  Serial.print(bacasensorLDR);
  Serial.println();
  }




}
