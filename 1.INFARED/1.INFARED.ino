int PB_1= 2;
int sensorIR= 3;
int R = 5;
int Y = 6;
int G = 7;
int kunciIR = 0;

void setup() {
 Serial.begin(9600);
 pinMode(PB_1,INPUT);
 pinMode(sensorIR,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
}

void loop() {
  //baca data
  int bacaPB_1=digitalRead(PB_1);
  int bacaIR=digitalRead(sensorIR);

  //print serial
  Serial.println("SYSTEM START");
  Serial.println("Kondisi PB_1:" +String(bacaPB_1));
  Serial.println("Kondisi sensorIR:" +String(bacaIR));

  //logika
 
  if (bacaIR==1 && kunciIR==0 ){
    digitalWrite(R,HIGH);
    delay(200);
    kunciIR=1;
  }
   else if ( bacaPB_1==1 && kunciIR==1 ) {
    digitalWrite(R,LOW);
    delay(200);
   }
  if (bacaPB_1==1 ){
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    delay(500);
    digitalWrite(Y,LOW);
    delay(200);
    digitalWrite(G,HIGH);
  }
  else if ( bacaIR==0 ) {
    digitalWrite(G,LOW);
    kunciIR=0;
   }
}
