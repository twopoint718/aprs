#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "serial.h"

// PWM runs at about 488 kHz with COUNTER_TOP == 255
//                   5MHz         COUNTER_TOP == 24
#define COUNTER_TOP 49

// Number of steps in the accumulator (should be a power of 2)
#define ACCUMULATOR_STEPS 2048

// Time in us between timer interrupts (sample updates) 2us == 500kHz
#define CALLBACK_PERIOD 2

// Initial PWM setting 50% duty cycle
static uint16_t pwm_level = COUNTER_TOP/2;

// Which slice the selected PWM pin belongs to (global for ISR)
static uint16_t slice_num;

// Step (phase) in the wav table
static uint8_t sample_index;

// Storage for repeating timer
static repeating_timer_t timer_config;

volatile struct DDS sound = {
	.increment = ACCUMULATOR_STEPS,
	.position = 0,
	.accumulator = 0
};

bool repeating_timer_callback(struct repeating_timer *t) {
	if (sample_index > COUNTER_TOP) {
		sample_index = 0;
	}
	pwm_set_chan_level(slice_num, PWM_CHAN_B, wav[sample_index++]);
	return true;
}

int main() {
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
	pwm_set_chan_level(slice_num, PWM_CHAN_B, pwm_level); // 50% duty cycle

	// Set the PWM running
	pwm_set_enabled(slice_num, true);

	// Set up a repeated timer
	add_repeating_timer_us(CALLBACK_PERIOD, repeating_timer_callback, NULL, &timer_config);
}
