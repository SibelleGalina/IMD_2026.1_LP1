#include <stdio.h>
#include <stdlib.h>

// Detecta se o sistema é Windows para carregar a biblioteca correta
#ifdef _WIN32
  #include <windows.h>
#endif

int main() {
    #ifdef _WIN32
      // Configura o terminal do Windows para UTF-8
      SetConsoleOutputCP(65001);
      SetConsoleCP(65001);
    #endif

    //Impressão de Números de 1 a N: Escreva um programa que leia um número inteiro positivo N e imprima todos os números de 1 até N.

    int num;
    
    printf("Digite um número inteiro positivo.\n");
    scanf("%i", &num);
    
    for (int i=1; i<=num; i++){
        printf("%i ", i);
    }

    return 0;
}