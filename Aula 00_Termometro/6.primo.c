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

    //Verificação de Número Primo: Desenvolva um programa que leia um número inteiro e determine se ele é um número primo ou não.
    
    int i, x, num;
    int contador = 0;
    
    printf("Digite um número para saber se ele é primo:\n");
    scanf("%i", &num);
    
    for (i = 1; i <= num; i++){
        x = num % i;
        if (x == 0){
            contador += 1;
        }
    }
    
    if (contador == 2)
        printf("É primo!");
    else 
        printf("Não é primo!");

    return 0;
}