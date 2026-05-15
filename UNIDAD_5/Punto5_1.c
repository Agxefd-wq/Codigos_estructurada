#include<stdio.h>

int main()
{
    int dato,*pdato;
    pdato=&dato;
    *pdato=10;
    printf("\nLa direccion de la variable es: %x",&dato);
    printf("\nLa direccion del puntero es: %x",&pdato);
    printf("\nLa variable es: %d", dato);
    printf("\nLa variable desde el puntero es: %d",*pdato);
    printf("\nEl contenido del puntero es: %x",pdato);
    return 0;
}