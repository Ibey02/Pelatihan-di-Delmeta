int PB_1 = 2;
int PB_2 = 3;
int R = 5;
int Y = 6;


void setup() {
  Serial.begin(9600);
  pinMode(PB_1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
 
}

void loop() {
  int bacaPB_1=digitalRead(PB_1);
  int bacaPB_2=digitalRead(PB_2);
  Serial.println("Kondisi PB_1:" +String(bacaPB_1));
  Serial.println("Kondisi PB_2:" +String(bacaPB_2));

  if (bacaPB_1==1 || bacaPB_2==1){
    digitalWrite(R,HIGH);
    delay(200);
  }
  else {
    digitalWrite(R,LOW);
  }
  
}
