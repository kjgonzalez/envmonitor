/*
photoresistor library, assumes that a photo resistor is being read via a voltage divider. 

STAT | DESCRIPTION
TODO | static resistor value
TODO | whether photoresistor (pr) on high voltage or ground side


NOTES: 
* 'g' will prefix the value of a pin output

*/

class PhotoResistor{
public:
    int pin;
    PhotoResistor(int analog_pin){
      pin=analog_pin;
    }//constructor
  void setup(){
    // initialization routine, not necessarily anything important, just done for consistency
  }

  int read(){
    return analogRead(pin);
  }
  float read_brightness(){
    // TODO: implement conversion to approximate lux
    return -1.0;
  }
}; //class PhotoResistor

