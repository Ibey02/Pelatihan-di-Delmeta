//INISIALISASI
int pinLDR=A0;
int pinR=5;
int pinBuzzer=3;
int pinFlame=A1;
int kunci01=0;

void setup() {
Serial.begin(9600);
pinMode(pinR,OUTPUT);
pinMode(pinBuzzer,OUTPUT);
 
}

void loop() {
//BACA DATA
int bacaFlame=analogRead(pinFlame);
 bacaFlame=map(bacaFlame,1018,24,0,100);
 //1018,24

//SERIAL PRINT
Serial.print("Nilai FLAME:");
Serial.print(bacaFlame);
Serial.println();
delay(200);

//LOGIKA
  //analogWrite(pinBuzzer,bacaFlame);
  if(bacaFlame==0){
  Serial.print("AMAN KOMANDAN");
  Serial.println();
  delay(100);
  }
  if(bacaFlame>=25 && bacaFlame<=35 ){
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
  Serial.print("WARNING SILAHKAN PERIKSA");
  Serial.println();
  }
  else if(bacaFlame>=35){
  digitalWrite(pinBuzzer,HIGH);
  delay(25);
  digitalWrite(pinBuzzer,LOW);
  delay(25);
  Serial.print("WASPADA HARAP MENGUNGSI");
  Serial.println();
  kunci01=0;
  }
  
}
