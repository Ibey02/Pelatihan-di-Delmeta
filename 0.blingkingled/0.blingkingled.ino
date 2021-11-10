int R=5; 
int Y=6; 
int G=7;
void setup() {
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
 
}

void loop() {
 digitalWrite(R,HIGH);
 digitalWrite(Y,HIGH);
 digitalWrite(G,HIGH);
 digitalWrite(R,HIGH);
 delay(100);
 digitalWrite(R,LOW);
 delay(100);
 digitalWrite(Y,HIGH);
 delay(100);
 digitalWrite(Y,LOW);
 delay(100);
 digitalWrite(G,HIGH);
 delay(100);
 digitalWrite(G,LOW);
 delay(1000);
 
 delay(100);
 
}
