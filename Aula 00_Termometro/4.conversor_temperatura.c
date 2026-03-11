#include <stdio.h>

int main()
{
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
        printf("%i Fahrenheit.\n", f);
        break;
    case 2:
        c = 5*(temperatura-32)/9;
        printf("%i Celsius.\n", c);
        break;
    }
    return 0;
}