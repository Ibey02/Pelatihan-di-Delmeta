//LIBRARY
#include <OneWire.h>
#include <DallasTemperature.h>

//INISIALISASI
int sensorSuhu=2;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);
int pinBuzzer=3;

 void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(pinBuzzer,OUTPUT);
  
}

void loop() {
//BACA DATA
sensors.requestTemperatures();
float bacaSuhu = sensors.getTempCByIndex(0);

//SERIAL PRINT
Serial.print ("SUHU :");
Serial.print (bacaSuhu);
Serial.print (" C");
Serial.println();
delay(200);

//LOGIKA
if(bacaSuhu>=30.28){
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
}
else{
  digitalWrite(pinBuzzer,LOW);
}

}
