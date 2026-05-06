/*
 * Project name: Click Button and LED Example
 * Description: Using a push button one event
 * Hostpage: https://github.com/LeandroTeodoroRJ/MicrochipExamplesSDCC 
 * Stable: Yes
 * Version: 1.0.0
 * Last Uptate: 17.04.26
 * Dependences: 
 *   gpio.h v1.0.0
 *   sdcc_utils.h v1.0.0
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
#define DEBOUCE_TIME 10000
#define BUTTON_ACTIVE 1
#define BUTTON_NOT_ACTIVE 0


int button_release;
int led_status;

void button_action(){
	led_status = !led_status;
	LED_PORT = led_status;
}

void main(void)
{
	LED_TRIS = OUTPUT;
	LED_PORT = BIT_OFF;
	io_gpio15 = INPUT;
	button_release = BUTTON_NOT_ACTIVE;
	led_status = 0;
	
	while (1) {
		if (button == BUTTON_PRESSED){
		delay_us(DEBOUCE_TIME);
			if (button == BUTTON_PRESSED){
				if (button_release == BUTTON_NOT_ACTIVE){
					button_action();
					button_release = BUTTON_ACTIVE;
				}	
			}
		}else{
			button_release = BUTTON_NOT_ACTIVE;
		}
				
	}
}
