/*
 * Description: General features for PIC
 * Hostpage: https://github.com/LeandroTeodoroRJ/MicrochipExamplesSDCC 
 * Stable: Yes
 * Version: 1.0.0
 * Last Uptate: 05.05.26
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
 * Description:
 * void delay_us(uint16_t iterations)  
 *   -- Delay Microseconds for 20MHz clock external XT
 * 
 * 
  */

//General definitions
#define BIT_HIGH 1
#define BIT_LOW 0
#define BIT_ON 1
#define BIT_OFF 0


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
