# PIC_display_lcd
Esta é uma biblioteca de LCD para PIC, criada para o XC8 - MPLABX para uso em atividades didáticas voltadas para educação, para compreender o uso do display LCD alfanumérico,
testada no PIC16F887, para controle via 4 bits.
Este código e seu exemplo de aplicação não devem ser usados para fins comerciais e seu funcionamento não é garantido ou livre de defeitos. Use-os com responsabilidade.  

REQUISITOS:
Para usar a biblioteca a estrutura lcd_pin_t deve ser declarada e inicializada na ordem:
Port RS, pino RS, port EN, pino EN, Port Dados, pino D4, pino D5, pino D6 e pino D7
essa estrutura deve ser passada na função lcd_init

FUNÇÕES:
void lcd_init( lcd_pin_t *lcd_pins);
- inicializa lcd 16x2 com 4 vias nos pinos selecionados pela estrutura "lcd_pin_t"

void limpa(void);
- limpa lcd

void escreve(char lin, char col, char *str);
- escreve string "*str" na linha "lin" a partir da coluna "col" 

void desloca(char casas, char esq);
- desloca visualização na quantidade "casas", para o lado esquerdo se "esq" = 1

void grava_caractere (char pos, char *linhas);
- grava caractere especial na posição "pos" da CGRAM, usando os dados das 8 linhas vindos da array "linhas"

void usa_caractere (char lin, char col, char caractere);
- escreve o caractere "caractere" na linha "lin" e coluna "col". Para escrever o caractere especial, basta usar sua posição gravada na função "grava_caractere"

EXEMPLO:
"lcdtest.c" inicializa o display com RS no RC0, o EN no RD0, e os dados D4 a D7 de RC2 a RC5, escreve a palavra Henrique na segunda linha, a partir da terceira coluna,
desenha um caractere de um robô na primeria linha, segunda coluna e escreve o caractere X na primeira linha, quarta coluna.
