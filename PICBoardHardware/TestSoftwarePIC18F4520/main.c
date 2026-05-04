//****************************************************************************
//      MOTHERBOARD 16F877A - TESTE DE HARDWARE PARA O PIC18F4520
//****************************************************************************
// Faz a saída definina como sinal oscilar com 5s de intervalo
//****************************************************************************

//Compilador CCS PCWH Ver 4.104

#include <18F4520.h>              //include do 18F4520
#include <string.h>
#include <18F4520_registradores.h>//MAPEAMENTO DE MEÓRIA DOS REGISTRADORES
                                                    

//****************************************************************************
//                    CONFIGURAÇÕES DO COMPILADOR
//****************************************************************************

#use fast_io(a)                  //modo de entrada e saida de dados que
#use fast_io(b)                  //o compilador nao configura o tris

#use delay(clock=20000000)        //clock usual
#fuses HS,NOLVP,NOWDT,PUT,NOPROTECT

//****************************************************************************
//                                BIOS
//****************************************************************************
//****************************  ENTRADAS  ************************************

//*****************************  SAÍDAS  *************************************
//#define  sinal       port_a,1

//****************************************************************************
//                        CONSTANTES E VARIÁVEIS
//****************************************************************************

int   w_temp;
int   status_temp;
int   count;


//***************************************************************************
//                               DRIVES
//***************************************************************************
//#include <usart.h>



//****************************************************************************
//                       Rotinas da interrupcao
//****************************************************************************
//#inline                     //descomentar se for usar o in_line



//****************************************************************************
//                           INTERRUPÇÕES
//****************************************************************************
#int_global
void interrupcao(){
restart_wdt();
disable_interrupts(global);
#asm
movwf w_temp
swapf status,w
movwf status_temp
#endasm


//***************************************************************************
//                          FIM DA INTERRUPCAO
//***************************************************************************
enable_interrupts(global);
#asm
swapf status_temp,w
movwf status
swapf w_temp,f
swapf w_temp,w
#endasm
}

//****************************************************************************
//                             Sub-rotinas
//****************************************************************************

//****************************************************************************
//                          Rotina Principal
//****************************************************************************

void main(){
//********************** CONFIGURAÇÕES INICIAIS *****************************
      setup_timer_0(rtcc_internal); //clock interno, prescaler 1:2
      setup_timer_1(t1_internal|t1_div_by_8); 
      setup_wdt(wdt_off);
      disable_interrupts(global);
      port_b_pullups(false);    //sem pull-up

//    Configuração do tris
//    Bit porta: 76543210
      tris_a = 0b00000000;
      tris_b = 0b00000000;
      tris_c = 0b00000000;
      tris_d = 0b00000000;
      tris_e = 0b00000000;      
//******************** INICIALIZAÇÃO DE VARIÁVEIS ***************************
      count = 0;
      
//****************************************************************************
//                             INICIO DO LOOP
//****************************************************************************
      while(1){  
         restart_wdt();
         output_A(0xff);
         output_B(0xff);
         output_C(0xff);
         output_D(0xff);
         output_high(pin_e0);
         output_high(pin_e1);
         output_high(pin_e2);
         delay_ms(5000);
         output_A(0x00);
         output_B(0x00);
         output_C(0x00);
         output_D(0x00);
         output_low(pin_e0);
         output_low(pin_e1);
         output_low(pin_e2);
         delay_ms(5000);
      }
//********************************* FIM **************************************
}


















































