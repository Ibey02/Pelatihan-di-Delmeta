int R=PA0; 
int Y=PA1; 
int G=PA2;
void setup() {
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
 
}

void loop() {
 digitalWrite(R,HIGH);
 delay(1000);
 digitalWrite(R,LOW);
 delay(100);
 digitalWrite(Y,HIGH);
 delay(1500);
 digitalWrite(Y,LOW);
 delay(100);
 digitalWrite(G,HIGH);
 delay(2000);
 digitalWrite(G,LOW);
 delay(100);
 digitalWrite(Y,HIGH);
 delay(500);
 digitalWrite(Y,LOW);
 delay(100);

 
}
