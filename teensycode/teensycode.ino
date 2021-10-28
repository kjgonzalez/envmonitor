/*
Environmental Monitor, running on teensy board.

TODO: make a header file for external functions
TODO: make a header file for solar_test
TODO: make a header file for uart_comm (talking to rpi)
TODO: try making a smarter UART function that checks various channels for incoming data
 */

void setup(){
  Serial.begin(115200);
  Serial.println("starting");
  Serial.setTimeout(10); // ms? TODO: check if milliseconds
  Serial1.begin(115200);
  Serial1.println("starting");
  Serial1.setTimeout(10); // ms? TODO: check if milliseconds
  pinMode(13,OUTPUT); // additional indication that message was received
  delay(1000);

}//setup

void loop(){
  while(Serial.available()>0){
    digitalWrite(13,HIGH);
    delay(300);
    digitalWrite(13,LOW);

    Serial.print("BOARD: ");
    Serial.println(Serial.readString());
  }//while data available
  while(Serial1.available()>0){
    digitalWrite(13,HIGH);
    delay(300);
    digitalWrite(13,LOW);

    Serial1.print("BOARD: ");
    Serial1.println(Serial.readString());
  }//while data available
}//loop
