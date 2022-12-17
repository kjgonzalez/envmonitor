class LED{
public: 
    uint8_t ledpin;
    bool state;
    void setup(int led_pin){
        ledpin = led_pin;
        state=0;
        pinMode(ledpin,1);
    }
    
    void blink(int total_ms=100){
        on();
        delay(total_ms/2);
        off();
        delay(total_ms/2);
    }
    void analog(uint8_t bright_uint8){
        analogWrite(ledpin,bright_uint8);
        if(bright_uint8>0) {state=true;}
        else {state=false;}
    }
    void on(){
        digitalWrite(ledpin,1);
        state = true;
    }
    void off(){
        digitalWrite(ledpin,0);
        state=false;
    }
    void toggle(){
        
    }
};
