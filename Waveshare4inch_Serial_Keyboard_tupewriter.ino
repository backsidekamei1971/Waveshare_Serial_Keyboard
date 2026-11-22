#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Waveshare4InchTftShield.h>

int incomingByte = 0; // for incoming serial data
int row=0;

namespace
{
    Waveshare4InchTftShield Waveshield;
}

void setup() 
{
	  Serial.begin(9600);
    randomSeed(analogRead(0));

    SPI.begin();
    Waveshield.begin();
    Waveshield.setRotation(3);
    Waveshield.print("Hello world!");  
}
int ddd=0;
void loop() {

  Waveshield.setRotation(3);
  if (Serial.available() > 0) {

    row=row+25;
    String ccc;
		ccc=Serial.readString();
    Serial.print(ccc);

  Waveshield.setTextSize(3);
  Waveshield.setCursor(0, row);
  Waveshield.println(ccc);

String str  = ccc;
unsigned int len =str.length();
//Waveshield.print(len);
  if (len>26){
    row=row+25;
  }
   
  }
	
}
