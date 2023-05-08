/*
 * File:   lcdtest.c
 * Author: Vitor
 *
 * Created on 21 de Abril de 2023, 10:43
 */

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)

#include <xc.h>
#include "string.h"
#include "biblioteca_lcd.h"
#include <stdio.h>

#define _XTAL_FREQ 4000000

#define lcd_rs RC0
#define lcd_en RC1

#define lcd_d4 RC2
#define lcd_d5 RC3
#define lcd_d6 RC4
#define lcd_d7 RC5

#define linha1  RD0
#define linha2  RD1
#define linha3  RD2
#define linha4  RD3

#define coluna1 RD4
#define coluna2 RD5
#define coluna3 RD6
#define coluna4 RD7



int linha_atual = 0;
char tecla = '_';
int sequencia = 0;
char coluna_atual = 0; 

void _muda_linha ()
{
    // esta fun??o altera para que apenas uma linha seja acionada por vez 
    
    if(linha_atual == 1)
    {
        linha1 = 0;
        linha2 = 1;
        linha3 = 0;
        linha4 = 0;
        linha_atual = 2;
    } else if(linha_atual == 2)
    {
        linha1 = 0;
        linha2 = 0;
        linha3 = 1;
        linha4 = 0;
        linha_atual = 3;
    } else if(linha_atual == 3)
    {
        linha1 = 0;
        linha2 = 0;
        linha3 = 0;
        linha4 = 1;
        linha_atual = 4;
    } else
    {
        linha1 = 1;
        linha2 = 0;
        linha3 = 0;
        linha4 = 0;
        linha_atual = 1;
    }
}

char _le_teclado()
{
    _muda_linha();
    if(coluna1 == 1)
    {
        __delay_ms(100);
        while(coluna1);
        switch(linha_atual){
            case 1: return 'C';
            case 2: return '1';
            case 3: return '4';
            case 4: return '7';
            default:return '_';
        }
    }else if(coluna2 == 1)
    {
        __delay_ms(100);
        while(coluna2);
        switch(linha_atual){
            case 1: return '0';
            case 2: return '2';
            case 3: return '5';
            case 4: return '8';
            default:return '_';
        }
    }else if(coluna3 == 1)
    {
        __delay_ms(100);
        while(coluna3);
        switch(linha_atual){
            case 1: return '=';
            case 2: return '3';
            case 3: return '6';
            case 4: return '9';
            default:return '_';
        }
    }else if(coluna4 == 1)
    {
        __delay_ms(100);
        while(coluna4);
        switch(linha_atual){
            case 1: return '+';
            case 2: return '-';
            case 3: return 'x';
            case 4: return '%';
            default:return '_';
        }
    }
    return '_';
}

lcd_pin_t lcd_pins = {
    &PORTC, 0,
    &PORTC, 1,
    &PORTC, 2, 3, 4, 5
};
//unsigned char var1 [] = ("00000");
//unsigned char var2 [] = ("00000");
//unsigned char var3 [] = ("00000");
int numero_a = 0;
int numero_b = 0;
int numero_c = 0;
int operacao = 0;
char buffer [75];

void main() 

{
    
    TRISC = 0x00;
    PORTC = 0x00;
    TRISD = 0xF0;
    PORTD = 0x00;
    ANSEL = 0x00;
   ANSELH = 0x00;
    
    lcd_init(&lcd_pins);
    escreve(2,2,"V|T0R");
    __delay_ms(2500);
    limpa(),coluna_atual=0;
    
    
    while(1)
    {
        tecla = _le_teclado();
        
        if(tecla>='0'&&tecla<='9'){
            if(operacao == 0){numero_a=numero_a*10+tecla-'0',usa_caractere(1,coluna_atual++,tecla);}
            
            else{numero_b=numero_b*10+tecla-'0',usa_caractere(1,coluna_atual++,tecla);}
        } 
        
        if(tecla == '+'){
            operacao = 1;
          usa_caractere(1,coluna_atual++,'+');           
        }
        
        if(tecla == '-'){
            operacao = 2;
          usa_caractere(1,coluna_atual++,'-');           
        }
        
        if(tecla == '%'){
            operacao = 3;
            usa_caractere(1,coluna_atual++,'%');
        }
          if(tecla == 'x'){
            operacao = 4;
            usa_caractere(1,coluna_atual++,'x');
        }
        


        if(tecla == '='){
        switch(operacao){
        case 1:  numero_c = numero_a + numero_b;
                 usa_caractere(1,coluna_atual++,'=');       
        break;
        case 2:  numero_c = numero_a - numero_b;
                 usa_caractere(1,coluna_atual++,'=');
        break;
        case 3:  numero_c = numero_a / numero_b;
                 usa_caractere(1,coluna_atual++,'=');
        break;
        case 4:  numero_c = numero_a * numero_b;
                 usa_caractere(1,coluna_atual++,'=');
        default:
         //operação invalida.
        break;
        }
     
            sprintf(buffer,"%i",numero_c);
            escreve (2,coluna_atual++,&buffer[0]);
        }
       
        
        if(tecla == 'C'){
            limpa(),coluna_atual = 0;
            numero_a = 0;
            numero_b = 0;
            numero_c = 0;
            operacao = 0;
        }
        }
}
  
        
        
            
        
        
        
            
        
        
        
        
                 
        
    

   
        
        
        
             
                
        
    

