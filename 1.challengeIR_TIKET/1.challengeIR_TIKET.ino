//INISIASI
int PB_1= 2;
int sensorIR= 3;
int R = 5;
int Y = 6;
int G = 7;
int kunciIR = 0;
int kuncialur = 0;

void setup() {
 Serial.begin(9600);
 pinMode(PB_1,INPUT);
 pinMode(sensorIR,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
 Serial.print("SYSTEM START");
}

void loop() {
  //BACA DATA
  int bacaPB_1=digitalRead(PB_1);
  int bacaIR=digitalRead(sensorIR);

  //PRINT SERIAL
  Serial.print("Tombol:");
  Serial.print(bacaPB_1);
  Serial.print(" | sensorIR:");
  Serial.print(bacaIR);
  Serial.print(" | Flag:");
  Serial.print(kuncialur);
  Serial.println();
 

  //LOGIKA
 
  if (bacaIR==1 && kunciIR==0 ){
    digitalWrite(R,HIGH);
    Serial.println();
    Serial.print("Palang Tertutup");
    Serial.println();
    delay(200);
    kunciIR=1;
  }
   else if ( bacaPB_1==1 && kunciIR==1 ) {
    digitalWrite(R,LOW);
    delay(200);
   }
  if (bacaPB_1==1 && kuncialur==0 ){
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    delay(500);
    digitalWrite(Y,LOW);
    delay(200);
    digitalWrite(G,HIGH);
    Serial.print("silahkan ambil tiket");
    Serial.println();
    Serial.print("Palang terbuka");
    Serial.println();
    kuncialur=1;
  }
  else if ( bacaIR==0 && kuncialur==1) {
    digitalWrite(G,LOW);
    kunciIR=0;
    kuncialur=0;
   }
}
