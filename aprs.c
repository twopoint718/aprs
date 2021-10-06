#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "aprs.h"

// Number of sine wave samples in the table
const uint16_t max_table_index = (sizeof(wav) / sizeof(uint8_t)) - 1;

// Which slice the selected PWM pin belongs to (global for ISR)
static uint16_t slice_num;

// Step (phase) in the wav table
uint16_t sample_index;

// DDS: Direct Digital Synthesis see:
// https://hackaday.com/2016/02/12/embed-with-elliot-audio-playback-with-direct-digital-synthesis/
volatile struct DDS space_symbol; // modified in interrupt, must be volatile

bool repeating_timer_callback(struct repeating_timer *t) {
	space_symbol.accumulator += space_symbol.increment;                       // accumulate phase steps
	space_symbol.position    += space_symbol.accumulator / ACCUMULATOR_STEPS; // advance sample if accumulator "overflows"
	space_symbol.accumulator  = space_symbol.accumulator % ACCUMULATOR_STEPS; // store residual for next interrupt

	if (space_symbol.position > max_table_index) {
		space_symbol.position = 0;
	}

	pwm_set_chan_level(slice_num, PWM_CHAN_B, (uint16_t)wav[space_symbol.position]); // Set output to current sample position
	return true;
}

int main() {
	// DDS struct for tracking sample playback
	space_symbol.increment = 2884;
	space_symbol.accumulator = 0;
	space_symbol.position = 0;

	// Storage for repeating timer
	repeating_timer_t timer_config;

	// Tell GPIO 13 to be allocated to the PWM (this is also onboard LED)
	gpio_set_function(13, GPIO_FUNC_PWM);

	// Find out which PWM slice is connected to GPIO 13 (Slice 6, pin B)
	slice_num = pwm_gpio_to_slice_num(13);

	// Free-running counting at rate dictated by fractional divider
	pwm_set_clkdiv_mode(slice_num, PWM_DIV_FREE_RUNNING);

	// Set counter TOP value
	pwm_set_wrap(slice_num, COUNTER_TOP);

	// Set divider to 1 (no division, ~125 MHz sys clock is used)
	pwm_set_clkdiv_int_frac(slice_num, 1, 0); // DIV_INT + DIV_FRAC/16

	// Set comparison level (when counter reaches this value, output goes low)
	pwm_set_chan_level(slice_num, PWM_CHAN_B, wav[sample_index]);

	// Set the PWM running
	pwm_set_enabled(slice_num, true);

	// Set up a repeated timer
	add_repeating_timer_us(CALLBACK_PERIOD, repeating_timer_callback, NULL, &timer_config);

	while (true) { }
}
