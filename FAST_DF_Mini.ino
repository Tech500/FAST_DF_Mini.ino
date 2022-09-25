/*
 *  "FAST_DF_Mini.ino"  William Lucid 09/24/2022
 *  
 *  Mode of Operation:
 *  
 *  Mode # 2
 *  01 Folder in root of SD card
 *  001 filename.mp3
 *  002 filename.mp3
 *  003 filename.mp3
 *  
 *  Single space is required after 3 digit number and filename.
 *  
 *  Coded using ESP32 Devkitv1
 *  
 */

#include <DFPlayerMini_Fast.h>   // https://github.com/PowerBroker2/DFPlayerMini_Fast

HardwareSerial mySoftwareSerial(1);

DFPlayerMini_Fast DF;

int PIN = 19;   //Pin assigned to read DF Mini Player, BUSY pin.
int VALUE;

int reward;

void setup()
{

  mySoftwareSerial.begin(9600, SERIAL_8N1, 16, 17);  // speed, type, RX, TX

  Serial.begin(115200);

  if (!DF.begin(mySoftwareSerial)) {} //Use softwareSerial to communicate with mp3.

  pinMode(PIN, INPUT);

  Serial.println("Setting volume");   //0-30 range
  DF.volume(10);

  delay(500);

}

void loop()
{

  reward = 2;   //DF.playFolder(1, 2)

  if (reward == 1) {
    DF.playFolder(1, 1);  //play specific mp3 in SD:/1/001.mp3; Folder Name(1~99); File Name(1~255)
    VALUE = digitalRead(PIN);
    while (VALUE == 0) {  //Playing
      VALUE = digitalRead(PIN);
      if(VALUE == 1){   //Finished
        exit;
      }
    }
  }
 

  if (reward == 2) {
    DF.playFolder(1, 2);  //play specific mp3 in SD:/1/002.mp3; Folder Name(1~99); File Name(1~255)
    VALUE = digitalRead(PIN);
    while (VALUE == 0) {
      VALUE = digitalRead(PIN);
      if(VALUE == 1){
        exit;
      }
    }
  }

  if (reward == 3) {
    DF.playFolder(1, 3);  //play specific mp3 in SD:/1/003.mp3; Folder Name(1~99); File Name(1~255)
    VALUE = digitalRead(PIN);
    while (VALUE == 0) {
      VALUE = digitalRead(PIN);
      if(VALUE == 1){
        exit;
      }
    }
  }

  delay(2000);

}
