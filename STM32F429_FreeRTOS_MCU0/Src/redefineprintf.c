#include <stdio.h>
#include "usart.h"

int fputc(int ch, FILE *f)
{
    while((USART1->SR & USART_SR_TC) == 0);
    USART1->DR = (uint8_t)ch;      
    return ch;
}