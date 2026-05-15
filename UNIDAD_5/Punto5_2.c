#include<stdio.h>

int main()
{
    int valor1, valor2;
    int *pValor1, *pValor2;
    pValor1 = &valor1;
    pValor2 = &valor2;

    *pValor1 = 10;
    *pValor2 = 15;

    printf("Ingrese segundo valor : %d", *pValor1 + *pValor2);

    return 0;
}