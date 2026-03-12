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

    //Cálculo de Fatorial: Crie um programa que calcule e imprima o fatorial de um número inteiro fornecido pelo usuário.

    int i, num;
    
    printf("Digite um número inteiro positivo para calcular seu fatorial:\n");

    scanf("%i", &num);

    for (i = 1; num > 1; num--){
        i = i * num;
    }

    printf("%i", i);

    return 0;

}