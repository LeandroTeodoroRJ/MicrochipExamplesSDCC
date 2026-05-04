/*
 * Project name: Blink Led Example 
 * Description: First example to compile with sdcc, modified to work
 * on 16F877A processor.
 * Hostpage: https://github.com/LeandroTeodoroRJ/MicrochipExamplesSDCC 
 * Stable: Yes
 * Version: 1.0.0
 * Last Uptate: 17.04.26
 * Dependences: 
 *   
 * Current: Yes
 * Maintainer: leandroteodoro.engenharia@gmail.com
 * Architecture: Microchip PIC16F877A
 * Compile/Interpreter: SDCC 4.5.0 :: gputils 1.5.2
 * Programer: PicKit 3 :: pk2cmd v1.27.03
 * Operation System: Ubuntu Mint 22 
 * Access: Public
 * Changelog: No
 * Readme and Documents: No
 * Links:
 *
 * Other Notes: 
 *  Original by diegoherranz (Git User) 
 *
 */

// Copyright (C) 2014 Diego Herranz

#define NO_BIT_DEFINES		//Access SFR using sfrname.bitname
#include <pic16f877a.h>
#include <stdint.h> 

// Oscillator Selection External XTAL
// disable watchdog,
// and disable low voltage programming.
__code uint16_t __at (_CONFIG) __configword = _HS_OSC & _WDTE_OFF & _LVP_OFF;


#define LED_PORT PORTCbits.RC0
#define LED_TRIS TRISCbits.TRISC0


void delay_us(uint16_t iterations)  //@20MHz clock
{
	uint16_t i;
	for (i = 0; i < iterations; i++) {
		// Prevent this loop from being optimized away.
		__asm 
			nop
			nop
			nop
			nop
			nop
		__endasm;
	}
}


void main(void)
{
	LED_TRIS = 0; // Pin as output
	LED_PORT = 0; // LED off
	
	while (1) {
		LED_PORT = 1; // LED On
		delay_us(50000); // ~50ms 
		LED_PORT = 0; // LED Off
		delay_us(50000); // ~50ms
	}
}
