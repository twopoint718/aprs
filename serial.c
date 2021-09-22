#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>
#include "serial.h"

// Adafruit MCP4725 12-bit DAC: https://www.adafruit.com/product/935
// Guide: https://learn.adafruit.com/mcp4725-12-bit-dac-tutorial
#define MCP4725_I2CADDR_DEFAULT (0x62)      // Default i2c address
#define MCP4725_CMD_WRITEDAC (0x40)         // Writes data to the DAC
#define SDA_PIN (2)
#define SCL_PIN (3)
#define NUM_SAMPLES (256)

int main() {
    stdio_init_all();

    i2c_init(i2c1, 400 * 1000);

    // Pinout Adafruit Feather RP2040: https://learn.adafruit.com/assets/100740
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C); // GPIO 02 / SDA
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C); // GPIO 03 / SCL

    // I2C wants line held high when inactive
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    uint8_t packet[3];

    uint8_t i = 0;
    while (true) {                        // Arrange upper and lower bytes
        packet[0] = MCP4725_CMD_WRITEDAC;
        packet[1] = buf_hi[i];            // D11 D10 D09 D08 D07 D06 D05 D04
        packet[2] = buf_lo[i];            // D03 D02 D01 D00 xxx xxx xxx xxx

        i2c_write_blocking(i2c1, MCP4725_I2CADDR_DEFAULT, packet, 3, true);
        i++;
    }
}
