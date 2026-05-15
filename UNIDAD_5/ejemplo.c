#include <stdio.h>

int main()
{
    int dato,*pdato;
    printf("\nIngrese un dato\t");
    scanf("%d",& dato);
    printf("\nEste es dato: %d",dato);
    printf("\nSe encuentra en x: %x",&dato);
    //printf("\nSe encuentra en p: %p",&dato);

    pdato = &dato;
    *pdato=123;
    printf("\nEl contenido de pdato: %x",pdato);
    printf("\nA lo que apunta pdato: %d", *pdato);//para ver lo que almacena
    return 0;
}