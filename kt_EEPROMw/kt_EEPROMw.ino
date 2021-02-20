#include <EEPROM.h>
#define LED   13        // Builtin LED on 13
#define ESIZE 1024      // size of EEPROM, ATmega328P:1024, ATtiny85:512
boolean WRITE = false;   // write flag
boolean ERASE = false;   // erase rest flag
boolean READ = true;    // whole read flag
unsigned int K0=0;      // 0 or 436
//unsigned int K0=436;      // 0 or 436

// split data with comment out and K0, 0-4:0 5-9::436
const byte *s[]= {
/**/
// 0
48,8,32,8,6,36,6,5,38,5,4,40,4,3,42,3,3,43,2,2,44,2,50,1,46,1,50,50,1,8,30,8,1,1,7,32,7,1,50,
1,8,30,8,1,1,46,1,50,2,45,1,2,44,2,50,3,42,3,4,41,3,4,40,4,6,37,5,7,34,7,10,28,10,48,
// 1
48,50,50,50,9,5,34,8,6,34,50,50,7,8,33,50,7,9,32,6,40,2,5,41,2,50,4,42,2,3,43,2,2,44,2,
50,50,50,50,50,50,48,50,50,50,50,
// 2
48,10,7,22,7,2,7,10,21,8,2,5,12,19,10,2,4,13,18,11,2,3,14,16,13,2,3,14,14,15,2,2,15,13,16,2,
2,15,11,18,2,1,16,9,20,2,1,16,7,22,2,1,9,13,23,2,1,8,12,25,2,1,7,11,27,2,1,7,9,20,1,8,2,
1,8,6,21,2,8,2,1,34,3,8,2,1,32,5,8,2,2,29,7,8,2,2,28,8,8,2,2,26,10,8,2,3,24,11,8,2,4,21,13,8,2,
4,19,15,8,2,5,16,17,8,2,7,12,19,8,2,10,6,32,48,
// 3
48,6,10,13,12,7,4,12,13,14,5,3,13,13,15,4,3,13,13,16,3,2,14,13,16,3,2,14,13,17,2,1,15,13,17,2,
1,15,13,18,1,1,15,3,6,4,18,1,50,1,15,3,7,3,18,1,1,7,11,7,14,7,1,50,1,7,10,9,13,7,1,1,9,6,13,9,9,1,
1,46,1,50,2,45,1,2,44,2,50,3,43,2,3,42,3,4,16,2,22,4,5,14,4,20,5,8,10,6,17,7,27,11,10,48,
// 4
29,9,10,26,12,10,23,15,10,20,18,10,17,21,10,14,24,10,11,27,10,8,30,10,5,25,1,7,10,2,24,5,7,10,
2,20,9,7,10,2,16,13,7,10,2,12,17,7,10,2,44,2,50,50,50,50,50,50,50,50,50,50,31,7,10,50,50,48,
/*
// 5
30,6,12,2,22,6,10,8,2,22,6,12,6,2,22,6,14,4,50,2,22,6,15,3,2,22,6,16,2,50,50,2,22,6,17,1,50,
2,7,7,7,14,10,1,2,7,6,6,19,7,1,2,7,6,5,20,7,1,2,7,5,7,19,7,1,2,7,5,8,17,8,1,2,7,5,33,1,2,7,4,34,1,
50,2,7,4,33,2,50,2,7,5,31,3,50,2,7,6,29,4,2,7,7,27,5,18,23,7,21,18,9,48,
// 6
10,27,11,8,33,7,6,36,6,5,39,4,4,40,4,3,42,3,3,43,2,2,44,2,50,2,45,1,1,46,1,1,25,11,10,1,
1,7,11,5,16,7,1,1,7,10,5,17,7,1,1,7,9,6,17,7,1,1,8,8,8,14,8,1,1,13,3,30,1,50,2,12,3,30,1,
2,12,3,29,2,50,3,11,3,29,2,3,11,4,27,3,4,10,4,26,4,5,9,5,24,5,6,8,6,22,6,9,5,9,16,9,48,
// 7
48,50,50,50,2,8,38,50,50,2,8,34,2,2,2,8,30,6,2,2,8,25,11,2,2,8,20,16,2,2,8,16,20,2,
2,8,11,25,2,2,8,7,29,2,2,8,2,34,2,2,44,2,50,50,2,42,4,2,37,9,2,32,14,2,27,19,2,22,24,
2,17,29,2,12,34,48,50,50,
// 8
29,8,11,8,9,7,17,7,6,13,4,20,5,4,16,2,22,4,3,42,3,50,2,44,2,50,1,46,1,50,50,1,27,11,8,1,
1,8,9,8,14,7,1,1,7,10,8,14,7,1,1,8,9,8,14,7,1,1,27,11,8,1,1,46,1,50,2,45,1,2,44,2,50,
3,43,2,3,18,1,23,3,4,16,2,22,4,5,14,4,20,5,8,10,6,18,6,28,9,11,48,
// 9
11,13,10,3,11,7,20,7,7,7,5,24,5,9,5,4,26,4,10,4,3,27,4,11,3,3,28,3,11,3,2,29,3,12,2,50,
2,30,2,12,2,1,31,2,13,1,50,50,1,7,16,7,9,7,1,1,7,17,6,9,7,1,1,7,16,6,10,7,1,1,8,14,6,10,8,1,
1,46,1,50,2,45,1,2,44,2,50,3,42,3,50,4,40,4,5,38,5,7,34,7,10,28,10,48,
// :
48,17,9,11,9,2,50,50,50,50,50,50,50,48,
/**/
};

void setup()
{
  int i;
  size_t maxi = sizeof(s)/sizeof(int);  // sizeofで*s[]を測ると2倍を返す？ s[0]が2など
  // serial setup and initial message
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println(F("START " __FILE__ " from " __DATE__ " " __TIME__));
  // set pinMode
  pinMode(LED, OUTPUT);
  // show size
  Serial.print(F("Count of write data: "));
  Serial.println(maxi);
/*
  for (i=0; i<maxi; i++) {
    int j=s[i];
    Serial.print("address=");
    Serial.print(K0+i);
    Serial.print(" s[");
    Serial.print(i);
    Serial.print("]=");
    Serial.println(j);
  }
/**/
  // write data
  if(WRITE) {
    Serial.println(F("Write font data to EEPROM"));
    for (i=0; i< maxi; i++) {
      Serial.print(i);
      digitalWrite(LED, HIGH); // ON
      EEPROM.write(i+K0, s[i]);
      Serial.print(F(" "));
      digitalWrite(LED, LOW);  // OFF
    }
      Serial.println();
  }
  if (ERASE) {
    Serial.println(F("Erase rest of EEPROM"));
    for (i=maxi; i<ESIZE; i++) {
      Serial.print(i);
      digitalWrite(LED, HIGH); // ON
      EEPROM.write(i, 0x00);
      Serial.print(F(" "));
      digitalWrite(LED, LOW);  // OFF
    }
    Serial.println();
  }
  if (READ) {
    Serial.println(F("Read whole data of EEPROM"));
    for (i=0; i<ESIZE; i++) {
      Serial.print(EEPROM.read(i));
      Serial.print(" ");
      if (i%20==0) Serial.println();
    }
  }
  Serial.println(F("===== finish ====="));
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH); // ON
  delay(1000);
  digitalWrite(LED, LOW);  // OFF
  delay(1000);
}

// end of program
