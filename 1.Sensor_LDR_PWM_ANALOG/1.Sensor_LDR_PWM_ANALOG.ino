//INISIALISASI
int pinLDR=A0;
int pinR=5;
int pinBuzzer=3;
int pinFlame=A1;


void setup() {
Serial.begin(9600);
pinMode(pinR,OUTPUT);
 
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
  //analogWrite(pinR,bacaLDR);
  
}
