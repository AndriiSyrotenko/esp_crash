
#include <Arduino.h>

void causeCrash() {
    Serial.println("About to cause a crash...");
    Serial.flush();

    volatile uint32_t* badAddress =
        reinterpret_cast<volatile uint32_t*>(0x00000000);

    volatile uint32_t value = *badAddress;

    Serial.println(value);  // This line should not execute
}

void setup() {
    Serial.begin(115200);
    delay(1500);

    Serial.println();
    Serial.println("Crash test started");

    causeCrash();
}

void loop() {
    Serial.println("Loop is running");
    delay(1000);
}
