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

    //Soma de Números em um Array: Faça um programa que leia 5 números inteiros, armazene-os em um array e calcule a soma total desses números.
    
    int vetor[5];
    int soma = 0;

    printf("Digite 5 numeros para somá-los:\n");

    for (int i = 0; i < 5; i++)
    {
        scanf("%i", &vetor[i]);
        soma = soma + vetor[i];
    }

    printf("A soma total é: %i", soma);

    return 0;
}