/*
use teensy as relay to communicate with secondary device
notes: 
located for now in 
*/
class PassThrough{
public:
    int baud;
    void setup(int _baud=115200){
        baud=_baud;
        Serial.begin(baud);
        Serial.setTimeout(10);
        Serial1.begin(baud);
        Serial1.setTimeout(10);
    }
    void echo(){
        // only bounce back messages: pc-teensy-pc
        while(Serial.available()>0){
            // delay(50);
            Serial.print("BOARD2: ");
            Serial.println(Serial.readString());
        }
    }
    
    void relay(){
        // relay messages: pc-teensy-serial1-teensy-pc
        
        // pc->teensy->Serial1
        if(Serial.available()){Serial1.write(Serial.read());}
        
        // Serial1->teensy->pc
        if(Serial1.available()){Serial.write(Serial1.read());}
    }
    
};