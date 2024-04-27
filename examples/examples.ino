#include <Arduino.h>

#include "../src/SimpleDigitalFilter.h"

#define DI_PIN PA0


SimpleDigitalFilter simpleDigitalInput;

void setup() {

    // pinMode(DI_PIN, INPUT);
    pinMode(DI_PIN, INPUT_PULLDOWN);
    // pinMode(DI_PIN, INPUT_PULLUP);

    simpleDigitalInput.setDelayTime(5000);

    SerialUSB.begin(9600);

}

void loop() {

    static bool state = 0;
    state = digitalRead(DI_PIN);
    simpleDigitalInput.updateState(state);

    SerialUSB.print("Raw:" + String(state) + " ");
    SerialUSB.println("Out:" + String(simpleDigitalInput.getOutState()) + " ");
    delay(50);
}
