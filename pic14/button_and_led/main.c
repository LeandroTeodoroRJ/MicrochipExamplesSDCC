/*
 * Project name: Button and LED Examples
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
 * Operational System: Ubuntu Mint 22 
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
#include "sdcc_utils.h"
#include "gpio.h"

// Oscillator Selection External XTAL
// disable watchdog,
// and disable low voltage programming.
__code uint16_t __at (_CONFIG) __configword = _HS_OSC & _WDTE_OFF & _LVP_OFF;


#define LED_PORT gpio14
#define LED_TRIS io_gpio14
#define button gpio15
#define BUTTON_PRESSED BIT_LOW

void main(void)
{
	LED_TRIS = OUTPUT;
	LED_PORT = BIT_OFF;
	io_gpio15 = INPUT;
	
	while (1) {
		if (button == BUTTON_PRESSED){
			LED_PORT = BIT_ON;
		}else{
			LED_PORT = BIT_OFF;
		}
				
	}
}
