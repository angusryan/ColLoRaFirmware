//The transmitter code arduino for sending data packet lora radio module 433MHz ra02

/* UNO PINS:    MICRO PINS:
 * NSS = 10     NSS = 10
 * MOSI = 11    MOSI = MO 
 * MISO = 12    MISO = MI
 * SCK = 13     SCK = SCK
 * RST = 9      RST = 9
 * 3.3V = 3V    3.3V = 3V
 * GND = GND    GND = GND
 * D0 = D2      D0 = D2 
*/
 
#include <SPI.h> // arduino spi library
#include <LoRa.h> // arduino libraries ra02 lora

int counter = 0;
 
void setup() {
 
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Sender");
  
  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
 
 LoRa.setSpreadingFactor(7);
 LoRa.setSignalBandwidth(125E3);
 LoRa.setFrequency(915.6);
 LoRa.setSpreadingFactor(7);
 LoRa.setSignalBandwidth(125E3);
 LoRa.setCodingRate4(5);
 LoRa.setTxPower(20,false);
 LoRa.crc();
 
}
 
void loop() {
 
  LoRa.beginPacket();
  LoRa.print(counter);
  Serial.println(counter);
  LoRa.endPacket();
  counter++;
  delay(2000);
 
}
