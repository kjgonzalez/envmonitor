/*
try to make an all-in-one single-plant monitoring device. 

planned operation: 
monitor various sensors, transmit data over wifi
stretch goal: power with solar / battery instead of wall power

desired components: 
* temperature / humidity sensor
* soil moisture sensor
* brightness sensor (photoresistor)
* wifi module
* MAYBE battery pack
* MAYBE solar panel (integrated)

TODO:
* achieve minimum possible current usage
* transmit data periodically (1/hr) on channel, another item needs to pick it up
* receive data from temp/humidity sensor
* protect soil moisture sensor with acryllic from water on sides
* receive data from soil moisture sensor
* 
general pinout: 
Tnsy | component
p_14 | ana_photoresistor
p_12 | dig_dht11



*/

#define pin_led 13
#define pin_bright 0 // analog 0, aka 14
#define pin_dht 12
#include "photoresistor.h"
#include "dht.h"
#include "led.h"
#include "passthrough.h"
#include "sensitive.h"

/* = THE SNOOZE LIBRARY =============
#include <Snooze.h>
SnoozeDigital digital;
SnoozeTimer timer;
Snoozelc5vBuffer lc5vBuffer;
SnoozeDigital digital;
SnoozeBlock config_teensyLC(lc5vBuffer,digital,timer);
*/

PhotoResistor pr(pin_bright);
DHT dht;
LED led;
PassThrough comm;
Sensitive help;
int val = 0;
void setup() {
    // led.setup(pin_led);
    comm.setup();
    // timer.setTimer(5000); // enable this to turn on sleeping for a set amount of time
    // pr.setup();
} // setup


void loop() {
    //led.blink();
    Serial.println(help.pw);
    delay(1000);
    // comm.relay();
    // while(Serial.available()>0){
        // Serial.print("BOARD: ");
        // Serial.println(Serial.readString());
    // }
    // delay(1000);
    

// ===================================================================
// past this line, functions that are disabled while individually debugging


//    int who = Snooze.deepSleep( config_teensyLC );// return module that woke processor
//    Serial.println(pr.read());
//    Serial.println("here");
//    dht.read11(pin_dht);
//    Serial.print("humid [%]:");
//    Serial.println(dht.humidity);
//    Serial.print("temp [C]:");
//    Serial.println(dht.temperature);

} // loop