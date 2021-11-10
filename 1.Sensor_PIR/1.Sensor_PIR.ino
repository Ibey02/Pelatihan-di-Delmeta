//INISIALISASI
int pinPIR=2;
int pinBuzzer=3;
int i=0;


void setup() {
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(pinBuzzer,OUTPUT);
  

}

void loop() {
  //BACA DATA
  int bacaPIR=digitalRead(pinPIR);

  //SERIAL PRINT
  Serial.print("Sensor PIR:");
  Serial.print(bacaPIR);
  Serial.println();
  delay(500);

  //LOGIKA
  if (bacaPIR==1){
    Serial.println("AWAS ADA MALING!!");
    for(i=700;i<800;i++){
    tone(3,i);
    delay(15);
    }
    for(i=800;i>700;i--){
    tone(3,i);
    delay(15);
    }
    }
  else{
    Serial.println("AMAN KOMANDAN");
    digitalWrite(pinBuzzer,LOW);
    delay(200);
  }
}
