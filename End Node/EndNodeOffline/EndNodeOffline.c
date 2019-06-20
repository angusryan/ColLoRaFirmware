#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <string.h>
#define DELAY 1000                        // delay in ms

TinyGPS gps;
SoftwareSerial ss(3, 4);                  // Arduino TX, RX pins

void setup() {
                                          // initialize both serial ports:
  Serial.begin(9600);                     // Serial to print out GPS info in Arduino IDE
  ss.begin(9600);                         // SoftSerial port to get GPS data.
  while (!Serial) {                       // wait for setup to complete
    ;
  }
  Serial.println("Minitor Dragino LoRa GPS Shield Status");
  Serial.print("Testing TinyGPS library v. "); Serial.println(TinyGPS::library_version());
  Serial.println();
  Serial.println("Setup complete");       //print title lines to serial
} 

void loop()
{
  float flat, flon;                       // latitude and longitude variables
  unsigned long age = 0;
  unsigned char lonlat;                   // concatenated string of both longitude and latitude
  unsigned char inping, outping = 0;

  while(!inping) {
    //check for ping from gateway
    if (/*ping*/ == 0x01) {
      inping = 1;
    }
    delay(DELAY)
  }
  while(/*not successful*/) {
    gps.f_get_position(&flat,&flon,&age); // get longitude and latitude from gps
    delay(DELAY);
  }
  Serial.print(flat, 6) 
  Serial.print(flon, 6)                   // print long and lat to serial
  Serial.println();
  strcpy(lonlat, (char) flon);
  strcat(lonlat, (char) flat);            // insert values into string
  while(!outping) {
    //send lonlat
    //check for acknowledgement
    if (/*ping*/ == 0x00) {
      outping = 1;
    }
    delay(DELAY)
  }
}
