//Impressão de Números de 1 a N: Escreva um programa que leia um número inteiro positivo N e imprima todos os números de 1 até N.


#include <stdio.h>

int main()
{
    int num;
    
    printf("digite um numero inteiro positivo.\n");
    scanf("%i", &num);
    
    for (int i=1; i<=num; i++){
        printf("%i\n", i);
    }
    
    return 0;
}