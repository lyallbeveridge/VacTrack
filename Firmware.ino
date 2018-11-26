// Lyall 12/09/2018
// Basic firmware will print the temperature at a defined interval and debug messages into 2 separate variables

#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C

// Update to reflect current pressure at sea level
float seaLevelhPa = 1035.7;

// the delay function is in milliseconds (1min = 1000 ms/s * 60 s/min)
int delayTime = 45000;

void setup() {
    // send a debug message to signal the program is running
    Particle.publish("STATUS", "firmware started!");
    
    // check that the sensor is properly wired
    if (bmp.begin()) {
        Particle.publish("STATUS", "sensor started!");
    } else {
        Particle.publish("STATUS", "WARN: bad wiring");
    }
}

void loop() {
    // publish the stringified altitude data
    Particle.publish("ALTITUDE", String(bmp.readAltitude(seaLevelhPa)));
    
    // delay or sleep to conserve battery
    delay(delayTime);
}