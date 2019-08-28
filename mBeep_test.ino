#include <M5Stack.h>
//by Armote Somboonkaew
//2019-08-28

//My Beep technique
//a solution for 
// -suitable loudness
// -cut a noise from a M5Stack speaker (แก้การมีเสียงคราง)

//Note-->SPEAKER_PIN = 25

void mInitBeep(void){
  //ให้มีการเริ่มต้น เพื่อเข้ามาให้ pin 25 เป็น 0 จะได้ไม่คราง
  dacWrite(SPEAKER_PIN, 0);///หาก 255 จะมีเสียงครางออกลำโพง
}

void mBeep(int n)
{
  /*
  //ของเดิมจะจบที่ pin25 เป็น 49 ทำให้เกิดเสียงครางออกลำโพง
  for(int j=0;j<n;j++){
      for(int i=0;i<50;i++){
        dacWrite(SPEAKER_PIN, i);
        delayMicroseconds(1);
      }
  }*/
  //code ใหม่ให้ code สุดท้ายของ loop สั่งให้เป็น 0
  for(int j=0;j<n;j++){
      for(int i=49;i>=0;i--){
        dacWrite(SPEAKER_PIN, i);
        delayMicroseconds(1);
      }//for i
  }//for j
}

void setup() {
  // Initialize the M5Stack object
  M5.begin();
  mInitBeep();
  M5.Lcd.printf("M5Stack mBeep test:\r\n");
  //mBeep(25);
  //mBeep(100);
  //mBeep(200);
}

void loop() {
  if(M5.BtnA.wasPressed()) {
    M5.Lcd.printf("A wasPressed \r\n");
    //old-->M5.Speaker.beep(); //beep
    mBeep(25);
  }

  if(M5.BtnB.wasPressed())
  {
    M5.Lcd.printf("B wasPressed \r\n");
    //old-->M5.Speaker.tone(NOTE_DH2, 200); //frequency 3000, with a duration of 200ms
    mBeep(100);
  }
  
  if(M5.BtnC.wasPressed())
  {
    M5.Lcd.printf("C wasPressed \r\n");
    //old-->M5.Speaker.tone(NOTE_DH2, 200); //frequency 3000, with a duration of 200ms
    mBeep(200);
  }
  
  M5.update();
}
