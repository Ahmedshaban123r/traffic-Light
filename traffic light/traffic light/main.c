#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"  // Use your existing LCD functions

#define F_CPU 8000000UL

// Common cathode 7-segment encoding (0-9)
uint8_t seg_code[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// LED pins on PORTA
#define GREEN_LED  PA7
#define YELLOW_LED PA6
#define RED_LED    PA5

// ---------- 7-Segment Display ----------
void display_number(uint8_t num) {
	uint8_t tens = num / 10;
	uint8_t ones = num % 10;

	PORTB = seg_code[ones]; // Ones digit
	PORTD = seg_code[tens]; // Tens digit
}

// ---------- Traffic Light Function ----------
void traffic_light(uint8_t seconds, uint8_t led_pin, const char *lcd_msg) {
	// Turn off all LEDs
	PORTA &= ~((1 << GREEN_LED) | (1 << YELLOW_LED) | (1 << RED_LED));
	
	
	// Turn on the selected LED
	PORTA |= (1 << led_pin);

	
	
	// LCD message
	LCD_command(0x01); // Clear display
	LCD_display_string(lcd_msg);
	

	// Countdown
	for (int8_t i = seconds; i >= 0; i--) {
		display_number(i);
		_delay_ms(1000);
	}
}

int main(void) {
	// ---------- Port Directions ----------
	DDRA |= (1 << RS_PIN) | (1 << RW_PIN) | (1 << E_PIN) |
	(1 << GREEN_LED) | (1 << YELLOW_LED) | (1 << RED_LED);
	DDRC = 0xFF; // LCD data
	DDRB = 0xFF; // 7-seg ones digit
	DDRD = 0xFF; // 7-seg tens digit

	// ---------- LCD Init ----------
	LCD_init();

	while (1) {
		 traffic_light(30, RED_LED, "      STOP");      // Red ? STOP
		traffic_light(10, YELLOW_LED, "     READY");  // Yellow ? READY
		
		traffic_light(30, GREEN_LED, "       GO");  //GRENN-> GO
	}
}
