/*Dada la siguiente estructura:
typedef struct
{
int codigo;
char descripcion[31];
float precio;
}sProductos
a. Crear una variable del tipo sProductos
b. Ingresar por teclado los campos
c. Crear un puntero a dicha estructura
d. Mostrar los datos ingresados mediante el puntero utilizando las dos nomenclaturas posibles
*/
#include<stdio.h>
#include<string.h>
typedef struct 
{
    int codigo;
    char descripcion[31];
    float precio;
}sProductos;

int main()
{
    sProductos producto;
    sProductos *pproducto;
    int mal=0;
    int codigo;
    char descr[31];
    float precio;
    pproducto=&producto;
    do
    {
        if(mal)
            printf("\nIngrese un codigo valido:\t");
        else
            printf("\nIngrese el codigo del producto:\t");
        mal=1;
        scanf("%d",& codigo);
    } while (codigo<=0);
    mal=0;
    producto.codigo=codigo;
    printf("Ingrese la descripcion del producto:\t");
    fflush(stdin);
    gets(descr);
    strcpy(producto.descripcion,descr);
    do
    {
        if(mal)
            printf("\nIngrese un precio valido:\t");
        else
            printf("\nIngrese el precio del producto:\t");
        mal=1;
        scanf("%f",& precio);
    } while (precio<=0);
    mal=0,
    producto.precio=precio;
    printf("\n******PRODUCTO*****");
    printf("\nCODIGO: %d", (*pproducto).codigo);
    printf("\nDESCRIPCION: %s",(*pproducto).descripcion);
    printf("\nPRECIO: %f",(*pproducto).precio);
    return 0;
}