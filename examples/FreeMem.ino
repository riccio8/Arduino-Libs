#include <Memory.hpp>

void setup() {
    Serial.begin(9600);
    Serial.print("Free memory: ");
    Serial.println(freeMemory());
}

void loop() {
    // Your code here
}
