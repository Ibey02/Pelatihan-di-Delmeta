//INISIALISASI
int PB_1= PA3;
int PB_2= PA4;
int PB_3= PA5;
int R = PA0;
int y = PA1;
int G = PA2;

void setup() {
 Serial.begin(9600);
 pinMode(PB_1,INPUT);
 pinMode(PB_1,INPUT);
 pinMode(PB_1,INPUT);
 pinMode(R,OUTPUT);
 pinMode(y,OUTPUT);
 pinMode(G,OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaPB_1=digitalRead(PB_1);
  int bacaPB_2=digitalRead(PB_2);
  int bacaPB_3=digitalRead(PB_3);
  
  //SERIAL PRINT
  Serial.println("Kondisi PB_1:" +String(bacaPB_1));
  Serial.println("Kondisi PB_2:" +String(bacaPB_2));
  Serial.println("Kondisi PB_3:" +String(bacaPB_3));
  
  //LOGIKA
  if (bacaPB_1==1){
    digitalWrite(R,HIGH);
    delay(200);
  }
   else {
    digitalWrite(R,LOW);
   }
  if (bacaPB_2==1){
    digitalWrite(y,HIGH);
    delay(200);
  }
  else {
    digitalWrite(y,LOW);
   }
  if (bacaPB_3==1){
    digitalWrite(G,HIGH);
    delay(200);
  }
  else {
    digitalWrite(G,LOW);
   }
  
}
