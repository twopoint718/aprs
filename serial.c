#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>

// Adafruit MCP4725 12-bit DAC: https://www.adafruit.com/product/935
// Guide: https://learn.adafruit.com/mcp4725-12-bit-dac-tutorial
#define MCP4725_I2CADDR_DEFAULT (0x62)      // Default i2c address
#define MCP4725_CMD_WRITEDAC (0x40)         // Writes data to the DAC
#define MCP4725_CMD_WRITEDACEEPROM (0x60)   // Writes to DAC & EEPROM (persistent)

int main() {
    stdio_init_all();

    i2c_init(i2c0, 100 * 1000);

    // Pinout Adafruit Feather RP2040: https://learn.adafruit.com/assets/100740
    gpio_set_function(2, GPIO_FUNC_I2C); // GPIO 02 / SDA
    gpio_set_function(3, GPIO_FUNC_I2C); // GPIO 03 / SCL

    // I2C wants line held high when inactive
    gpio_pull_up(2);
    gpio_pull_up(3);

    while (true) {
        for (uint16_t output = 0; output < (1 << 12); output++) {
            // 0 through 4095 the "true" 12-bit value as a fraction of vref

            uint8_t packet[3];
            packet[0] = MCP4725_CMD_WRITEDAC;       // Arrange the upper and lower bytes
            packet[1] = output / 16;        // D11 D10 D09 D08 D07 D06 D05 D04
            packet[2] = (output % 16) << 4; // D03 D02 D01 D00 xxx xxx xxx xxx

            i2c_write_blocking(i2c0, MCP4725_I2CADDR_DEFAULT, packet, 3, false);
        }
        busy_wait_us(100000);
    }
}
