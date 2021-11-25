#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>

int merah = 4;
int kuning= 5;
int hijau = 6;
int sensorLDR = A1;
int kunci=0;
char ssid[] = "Redmiqqqqqq"; // your network SSID (name)
char pass[] = "12345678"; // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status
unsigned long lastSend;

// Initialize the Ethernet client object
WiFiEspClient espClient;
PubSubClient client(espClient);

SoftwareSerial Serialx(2,3); // RX, TX   //ESP8266 RX,TX connected to these pins

void setup() {
// initialize serial for debugging
Serial.begin(115200);
// initialize serial for ESP module
Serialx.begin(9600);
// initialize ESP module
WiFi.init(&Serialx);

pinMode(merah,OUTPUT);
pinMode(kuning,OUTPUT);
pinMode(hijau,OUTPUT);
pinMode(sensorLDR,INPUT);

// check for the presence of the shield
if (WiFi.status() == WL_NO_SHIELD) {
Serial.println("WiFi shield not present");
// don't continue
while (true);
}

// attempt to connect to WiFi network
while ( status != WL_CONNECTED) {
Serial.print("Attempting to connect to WPA SSID: ");
Serial.println(ssid);
// Connect to WPA/WPA2 network
status = WiFi.begin(ssid, pass);
lastSend = 0;
}

// you're connected now, so print out the data
Serial.println("You're connected to the network");

//connect to MQTT server
client.setServer("test.mosquitto.org", 1883);
client.setCallback(callback);
}

//print any message received for subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Pesan diterima [");
  Serial.print(topic);
  Serial.println("] ");
  //==============================================================
  if (strcmp(topic, "ibey121102/lampu1") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(merah,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(merah,LOW);
    }
  }
  }
  //==============================================================

  //==============================================================
  if (strcmp(topic, "ibey121102/lampu2") == 0) //Membandingkan 2 buah String
  { 
    for (int c=0;c<length;c++) {
    char receivedChar1 = (char)payload[c];
    if (receivedChar1 == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       Serial.println("LAMPU FLIPFLOP ON");
       kunci=1;
       flipflop();
   
       
    }
    else if (receivedChar1 == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       Serial.println("LAMPU FLIPFLOP OFF");
       flipflopoff();
       kunci=0;
    }
  }
  }
  //==============================================================
  
}

void pushdata(){
  //Ambil Data / Baca Sensor
  //char msgBuffer[20];
  int bacaLDR = analogRead(sensorLDR);
  
  //POST TO SERIAL
  Serial.print("Sensor LDR :");Serial.print(bacaLDR);
  Serial.println();
  
  //POST TO MQTT
  //client.publish("ibey121102/datax", dtostrf(datax, 6, 2, msgBuffer)); //Convert to String 
  client.publish("ibey121102/bacaLDR", String(bacaLDR).c_str());
}

void loop() {
// put your main code here, to run repeatedly:

if (!client.connected()) {
reconnect();
}
if ( millis() - lastSend > 2000 ) { // Update and send only after 1 seconds
    pushdata();
    lastSend = millis();
 }
client.loop();

}

void flipflop() {
  if(kunci==1){
    for(int t=0; t>=0; t++){
  digitalWrite(merah,HIGH);
  digitalWrite(kuning,LOW);
  digitalWrite(hijau,LOW);
  delay(70);
  digitalWrite(kuning,HIGH);
  digitalWrite(merah,LOW);
  digitalWrite(hijau,LOW);
  delay(70);
  digitalWrite(hijau,HIGH);
  digitalWrite(kuning,LOW);
  digitalWrite(merah,LOW);
  delay(70);
  digitalWrite(kuning,HIGH);
  digitalWrite(merah,LOW);
  digitalWrite(hijau,LOW);
  delay(70);
  }
  }
}

void flipflopoff(){
  digitalWrite(kuning,LOW);
  digitalWrite(merah,LOW);
  digitalWrite(hijau,LOW);
}


void reconnect() {
// Loop until we're reconnected
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
// Attempt to connect, just a name to identify the client
if (client.connect("ibey121102")) {
Serial.println("connected");

//client.publish("outpic","Hello World");
client.subscribe("ibey121102/lampu1",0);
client.subscribe("ibey121102/lampu2",0);

} else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
}
}
}
