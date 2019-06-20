#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <string.h>
#define DELAY 1000                        // delay in ms

TinyGPS gps;
SoftwareSerial ss(3, 4);                  // Arduino TX, RX pins

void setup()
{
  //setup
}

 
void loop()
{
  unsigned char lonlat;                   // concatenated string of both longitude and latitude
  unsigned char ping = 0;

  while(!inttnping) {
    //check for ping from app/TTN
    if (/*ping*/ == 0x01) {
      ping = 1;
    }
    delay(DELAY)
  }

  while(!inmodping) {
    //send ping to module
    //check for gps lonlat
    if (/*gps*/ == /*valid*/) {
      inmodping = 1;
    }
    delay(DELAY)
  }

  //send acknowledgement

  while(!outttnping) {
    //send gps lonlat
    //check for acknowledgement
    if (/*ping*/ == 0x00) {
      outttnping = 1;
    }
    delay(DELAY)
  }
}
