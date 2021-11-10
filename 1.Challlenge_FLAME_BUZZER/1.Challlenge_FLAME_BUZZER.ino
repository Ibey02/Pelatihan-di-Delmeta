//INISIALISASI
int pinLDR=A0;
int pinFlame=A1;
int pinR=5;
int pinY=6;
int pinG=7;
int pinBuzzer=3;
int pinPIR=2;

void setup() {
Serial.begin(9600);
pinMode(pinR,OUTPUT);
pinMode(pinY,OUTPUT);
pinMode(pinG,OUTPUT);
pinMode(pinBuzzer,OUTPUT);
 
}

void loop() {
//BACA DATA
int bacaFlame=analogRead(pinFlame);
int bacaLDR=analogRead(pinLDR);
int bacaPIR=digitalRead(pinPIR);
bacaLDR=map(bacaLDR,10,800,0,100);
bacaFlame=map(bacaFlame,1018,24,0,100);
 //1018,24

//SERIAL PRINT
Serial.print("Sensor PIR:");
  Serial.print(bacaPIR);
  Serial.println();
  delay(500);
Serial.print("NILAI LDR:");
Serial.print(bacaLDR);
Serial.println();
Serial.print("Nilai FLAME:");
Serial.print(bacaFlame);
Serial.println();
delay(200);

//LOGIKA
  //analogWrite(pinBuzzer,bacaFlame);
  analogWrite(pinR,bacaLDR);
  
  if(bacaFlame<=15){
  digitalWrite(pinY,LOW);
  digitalWrite(pinG,LOW);
  Serial.print("Aman Banget");
  Serial.println();
  delay(100);
  }
  
  else if(bacaFlame>15 && bacaFlame<=35 ){
  digitalWrite(pinY,HIGH);
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
  Serial.print("WARNING SILAHKAN PERIKSA");
  Serial.println();
  }
  
  if(bacaFlame>=35){
  digitalWrite(pinY,HIGH);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinBuzzer,HIGH);
  delay(50);
  digitalWrite(pinBuzzer,LOW);
  delay(50);
  digitalWrite(pinBuzzer,HIGH);
  delay(50);
  digitalWrite(pinBuzzer,LOW);
  delay(50);
  Serial.print("WASPADA HARAP MENGUNGSI");
  Serial.println();
  }
}
