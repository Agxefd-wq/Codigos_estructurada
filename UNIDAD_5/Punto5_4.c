/*Hacer un programa que cargue un vector de 10 enteros y lo muestre usando una función para cargar y otra
mostrar sin utilizar subíndices.*/
#include<stdio.h>

void CargarVect(int[],int);
void MostrarVect(int[],int);
int main()
{
    int vec[10];
    CargarVect(vec,10);
    MostrarVect(vec,10);
    return 0;
}

void CargarVect(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        printf("\nIngrese el %d numero:\t",i+1);
        scanf("%d",v+i);
    }
}

void MostrarVect(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        printf("\n%d",*(v+i));;
    }
}