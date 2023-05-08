/*
 * File:   TECLADO.c
 * Author: sn1056979
 *
 * Created on 17 de Abril de 2023, 15:02
 */
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF

#include <xc.h>

#define _XTAL_FREQ 4000000

#define linha1 RD0
#define linha2 RD1
#define linha3 RD2
#define linha4 RD3

#define coluna1 RD4
#define coluna2 RD5
#define coluna3 RD6
#define coluna4 RD7



int linha_atual = 0;
char tecla = '_';
int sequencia = 0;


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
            case 4: return '/';
            default:return '_';
        }
    }
    return '_';
}


void main()
{
    TRISD = 0xF0;
    PORTD = 0x00;
    TRISC = 0xC0;
    PORTC = 0x00;
    
    while(1)
    {
        tecla = _le_teclado();
        if (tecla=='1'&& sequencia == 0)
                    sequencia = 1;
                
        if (tecla=='2' && sequencia == 1 )
                    sequencia = 2;
                        
        if (tecla=='3' && sequencia == 2)
                   sequencia = 3;
                       
        if (tecla=='4' && sequencia == 3)
                    sequencia = 4;
                       
                      if (sequencia == 4)
                      LED = 1;
        
       
        if (sequencia == 0 && tecla != 1 && tecla != '_')
            
        if (sequencia == 0 && tecla != 2 && tecla != '_')
                 
        if (sequencia == 0 && tecla != 3 && tecla != '_')
                      
        if (sequencia == 0 && tecla != 4 && tecla != '_')
    
    
                                                          }
    return;
}
       
        