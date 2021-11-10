int PB_1 = 2;
int PB_2 = 3;
int PB_3 = 4;
int R = 5;
int Y = 6;
int G = 7;
int m = 13;
void setup() {
  Serial.begin(9600);
  pinMode(PB_1,INPUT);
  pinMode(PB_2,INPUT);
  pinMode(PB_3,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(m,OUTPUT);
 
}

void loop() {
  int bacaPB_1=digitalRead(PB_1);
  int bacaPB_2=digitalRead(PB_2);
  int bacaPB_3=digitalRead(PB_3);
  int bacam=digitalRead(m);
  Serial.println("Kondisi PB_1:" +String(bacaPB_1));
  Serial.println("Kondisi PB_2:" +String(bacaPB_2));

  if (bacaPB_1== 1 && bacam== 0){
    digitalWrite(R,HIGH);
    digitalWrite(m,HIGH);
    delay(200);
  }
  else if (bacaPB_1== 1 && bacam==1) {
    digitalWrite(R,LOW);
    digitalWrite(m,LOW);
    delay(200);
  }
  if (bacaPB_2== 1 && bacam== 0){
    digitalWrite(Y,HIGH);
    digitalWrite(m,HIGH);
    delay(200);
  }
  else if (bacaPB_2== 1 && bacam==1) {
    digitalWrite(Y,LOW);
    digitalWrite(m,LOW);
    delay(200);
  }
  if (bacaPB_3== 1 && bacam== 0){
    digitalWrite(G,HIGH);
    digitalWrite(m,HIGH);
    delay(200);
  }
  else if (bacaPB_3== 1 && bacam==1) {
    digitalWrite(G,LOW);
    digitalWrite(m,LOW);
    delay(200);
  }
  
}
