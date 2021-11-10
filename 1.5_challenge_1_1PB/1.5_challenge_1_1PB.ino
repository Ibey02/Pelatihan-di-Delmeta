int PB_1 = 2;
int PB_2 = 3;
int PB_3 = 4;
int R = 5;
int Y = 6;
int G = 7;
int m = 0;
void setup() {
  Serial.begin(9600);
  pinMode(PB_1,INPUT);
  pinMode(PB_2,INPUT);
  pinMode(PB_3,INPUT);
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

  if (bacaPB_1== 1 && m== 0){
   
    digitalWrite(R,HIGH);
    m = 1;
  }
  else if (bacaPB_1== 1 && m==1) {
    
    digitalWrite(R,LOW);
    m = 0; 
  }
  
}
