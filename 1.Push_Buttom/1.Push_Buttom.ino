int PB_1= 2;
int PB_2= 3;
int PB_3= 4;
int R = 5;
int Y = 6;
int G = 7;

void setup() {
 Serial.begin(9600);
 pinMode(PB_1,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
}

void loop() {
  int bacaPB_1=digitalRead(PB_1);
  int bacaPB_2=digitalRead(PB_2);
  int bacaPB_3=digitalRead(PB_3);
  Serial.println("Kondisi PB_1:" +String(bacaPB_1));
  Serial.println("Kondisi PB_2:" +String(bacaPB_2));
  Serial.println("Kondisi PB_3:" +String(bacaPB_3));
  if (bacaPB_1==1){
    digitalWrite(R,HIGH);
    delay(200);
  }
   else {
    digitalWrite(R,LOW);
   }
  if (bacaPB_2==1){
    digitalWrite(Y,HIGH);
    delay(200);
  }
  else {
    digitalWrite(Y,LOW);
   }
  if (bacaPB_3==1){
    digitalWrite(G,HIGH);
    delay(200);
  }
  else {
    digitalWrite(G,LOW);
   }
  
}
