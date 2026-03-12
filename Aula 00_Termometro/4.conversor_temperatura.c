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

    //Conversão de Temperatura: Escreva um programa que converta uma temperatura fornecida em graus Celsius para Fahrenheit e vice-versa.
    
    int temperatura;
    int i, c, f;
    
    printf("Escolha a escala de conversão da temperatura:\n"); 
    printf("1 - Celsius para Fahrenheit\n2 - Fahrenheit para Celsius\n");
    scanf("%i", &i);
    
    printf("Agora digite a temperatura que quer converter:\n");
    scanf("%i", &temperatura);
    
    switch (i){
    case 1:
        f = (temperatura/5)*9 + 32;
        printf("%i° Fahrenheit.\n", f);
        break;
    case 2:
        c = 5*(temperatura-32)/9;
        printf("%i° Celsius.\n", c);
        break;
    }

    return 0;
}