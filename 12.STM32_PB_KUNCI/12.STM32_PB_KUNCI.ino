//INISIALISASI
int AgungPB_1 = PA0;
int AgungPB_2 = PA1;
int AgungPB_3 = PA2;

int merah = PA3;
int kuning = PA4;
int hijau = PA5;

int kunci0 =0;
int kunci1 =0;
int kunci2 =0;

void setup() {
  Serial.begin(9600);
  pinMode(AgungPB_1,INPUT);
  pinMode(AgungPB_2,INPUT);
  pinMode(AgungPB_3,INPUT);
  pinMode(merah, OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaAgungPB_1 = digitalRead (AgungPB_1);
  int bacaAgungPB_2 = digitalRead (AgungPB_2);
  int bacaAgungPB_3 = digitalRead (AgungPB_3);

  //SERIAL PRINT
  Serial.print("AgungPB_1 = " + String(bacaAgungPB_1));
  Serial.print("AgungPB_2 = " + String(bacaAgungPB_2));
  Serial.print("AgungPB_3 = " + String(bacaAgungPB_3));
  Serial.println();

  //LOGIKA
  if(bacaAgungPB_1==1 && kunci0==0){ //LOGIKA TOMBOL 1
    digitalWrite(merah,HIGH);
    kunci0=1;
    delay(200);
    
  
  }else if (bacaAgungPB_1==1 && kunci0==1){
    digitalWrite(merah,LOW);
    kunci0=0;
    delay(200);
  }

    if(bacaAgungPB_2==1 && kunci1==0){ //LOGIKA TOMBOL 2
    digitalWrite(kuning,HIGH);
    kunci1=1;
    delay(200);
  }else if(bacaAgungPB_2==1 && kunci1==1){
    digitalWrite(kuning,LOW);
    kunci1=0;
    delay(200);
  }

    if(bacaAgungPB_3==1 && kunci2==0){ //LOGIKA TOMBOL 3
    digitalWrite(hijau,HIGH);
    kunci2=1;
    delay(200);
  }else if(bacaAgungPB_3==1 && kunci2==1){
    digitalWrite(hijau,LOW);
    kunci2=0;
    delay(200);
  }
  }
  
