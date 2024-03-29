# Environment Monitor
Goal: collect and store sensor readings from a local environment

## Installation
* Clone repo
* Ensure all relevant modules installed (note: recommended venv is "venv/")
* Connect all wires as needed

## Sensors Used
* SHTC3: temperature / humidity over I2C

### Teensy Option
Since the RPI can't perform any true PWM / DAC / analog actions, will handle this here. there will be a core program that then has the option of enabling / disabling various functionalities, such as reading voltage / current from a solar panel

## Wire Connections
### RPI-SHTC3:
```
RPI0 | SHTC3
GP_1 | 3V  BLUE
GP_3 | SDA YELLOW
GP_5 | SCL ORANGE
GP_6 | GND GREEN
```

### Teensy-RPI Zero:
The teensy and rpi need to share data, and the teensy will receive 5V/GND from the rpi as well. thus, wiring needs to look like the below. KEEP IN MIND: THE TEENSY MUST NOT BE CONNECTED TO 5V POWER WHEN PLUGGING IN WITH USB; EITHER DISCONNECT OR USE A DATA-ONLY USB
```
RPI     | TEENSY          | COLOR
5V (2)  | Vin (top-right) | RED
GND (6) | GND (top-left)  | GREEN
TX (14) | RX (0)          | YELLOW
RX (15) | TX (1)          | BLUE
```

## TODO
* add support for solar panels
* communicate over UART with teensy
* store teensy code here as well
* add various ways to run program (which sensors to activate, what's talking to what)
* perform rpi-teensy echo test
* make simple request system for rpi-teensy data transfer

### Credits, External Libraries
* Snooze, https://github.com/duff2013/Snooze/
* DHTStable, https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTstable
* 


