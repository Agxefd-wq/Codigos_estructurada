/*Cargar un vector de enteros con números aleatorios de 3 cifras máximo.
Realizar una función que retorne un puntero al mayor valor del vector
Mostrar el máximo valor mediante el puntero y la posición en la cual se encuentra*/
#include<stdio.h>
#include<time.h>

void CargaAleatoriaTresCifras(int [],int,int,int);
int* PunteroMayNumVec(int[],int);
int main()
{   
    int vAleatorio[10];
    int *pmayor;
    srand(time(NULL));
    CargaAleatoriaTresCifras(vAleatorio,10,100,999);
    pmayor=PunteroMayNumVec(vAleatorio,10);
    printf("\nEl mayor numero del vector es: %d",*pmayor);
    printf("\nSe encuentra en la posicion: %d",pmayor-vAleatorio);
    return 0;
}

void CargaAleatoriaTresCifras(int v[],int ce,int min, int max)
{
    int i=0;
    int num;
    while(i<ce)
    {
        num=rand();
        if(num<=max && num>=min)
        {
            printf("\n%d",num);
            v[i]= num;
            i++;
        }
    }
}

int* PunteroMayNumVec(int v[],int ce)
{
    int i;
    int *pmayor=v;
    for(i=0;i<ce;i++)
    {
        if(*(v+i)>*pmayor)
        {
            pmayor=v+i;
        }
    }
    return pmayor;
}