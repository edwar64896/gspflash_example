#include <Arduino.h>
#include <gspflash.h>
#include <gspswitch.h>

void doSwitch1(uint8_t);

gspFlash led1(13);
gspSwitch switch1(12,4,doSwitch1,0);

void doSwitch1(uint8_t mode) {
    
    switch(mode){
        case 0:
            led1.turnOff();
        break;
        case 1:
            led1.flashSlow();
        break;
        case 2:
            led1.flashFast();
        break;
        case 3:
            led1.turnOn();
        break;
    }
}

void setup() {
    Serial.begin(115200);

    gspGrouped::register_instance(& led1    );
    gspGrouped::register_instance(& switch1 );

    gspFlash::startCheckAll();

}

void loop() {

    gspSwitch::checkAll();
}
