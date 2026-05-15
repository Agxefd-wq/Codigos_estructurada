#include <stdio.h>

void AsignarValores(int*, float*, char*);

int main(){
    int entero, *pEntero = &entero;
    float flotante, *pFlotante = &flotante;
    char caracter, *pCaracter = &caracter;
    

    AsignarValores(pEntero, pFlotante, pCaracter);

    printf("Los valores ingresados fueron: %d, %f, %c.",*pEntero,*pFlotante,*pCaracter);

    return 0;
}


void AsignarValores(int *e, float *f, char *c){

    printf("Ingrese un entero: ");
    scanf("%d",e);
    printf("Ingrese un flotante: ");
    scanf("%f",f);
    printf("Ingrese un char: ");
    fflush(stdin);
    scanf("%c",c);
}