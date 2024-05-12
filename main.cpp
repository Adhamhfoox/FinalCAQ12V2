#include "mbed.h"
#include "FXOS8700CQ.h"

// Define accelerometer and RGB LED objects
FXOS8700CQ accel(PTE25, PTE24, FXOS8700CQ_SLAVE_ADDR1);
PwmOut redLED(LED_RED);
PwmOut greenLED(LED_GREEN);
PwmOut blueLED(LED_BLUE);

int main() {
    // Set PWM period for LED control
    redLED.period(0.01);
    greenLED.period(0.01);
    blueLED.period(0.01);

    // Main loop
    while(1) {
        // Read accelerometer data
        float x, y, z;
        accel.getAccXYZ(&x, &y, &z);

        // Map accelerometer data to LED brightness (0 to 1)
        float redBrightness = fabs(x) / 2.0;  // Range: 0 to 0.5
        float greenBrightness = fabs(y) / 2.0; // Range: 0 to 0.5
        float blueBrightness = fabs(z) / 2.0;  // Range: 0 to 0.5

        // Update LED colors
        redLED.write(redBrightness);
        greenLED.write(greenBrightness);
        blueLED.write(blueBrightness);

        // Optional delay to avoid rapid changes
        ThisThread::sleep_for(100ms);
    }
}
