//INISIALISASI
int pinLDR=A0;
int pinR=5;


void setup() {
Serial.begin(9600);
pinMode(pinR,OUTPUT);
 
}

void loop() {
//BACA DATA
int bacaLDR=analogRead(pinLDR);
  bacaLDR=map(bacaLDR,12,800,0,255);

//SERIAL PRINT
Serial.print("Nilai LDR:");
Serial.print(bacaLDR);
Serial.println();
delay(200);

//LOGIKA
  analogWrite(pinR,bacaLDR);
  
}
