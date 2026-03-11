//Cálculo de Fatorial: Crie um programa que calcule e imprima o fatorial de um número inteiro fornecido pelo usuário.

#include <stdio.h>

int main()
{
    int i, num;
    
    printf("Digite um numero inteiro positivo para calcular seu fatorial:\n");

    scanf("%i", &num);

    for (i = 1; num > 1; num--){
        i = i * num;
    }

    printf("%i", i);
    
    return 0;
}
