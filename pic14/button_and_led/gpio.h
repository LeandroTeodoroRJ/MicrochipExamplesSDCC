/*
 * Description: GPIO library
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
 * 
 * 
  */

#define OUTPUT 0
#define INPUT 1

// GPIO list
#define gpio0		PORTAbits.RA0
#define io_gpio0 	TRISAbits.TRISA0
// ...
#define gpio14		PORTCbits.RC0
#define io_gpio14 	TRISCbits.TRISC0
#define gpio15		PORTCbits.RC1
#define io_gpio15 	TRISCbits.TRISC1


