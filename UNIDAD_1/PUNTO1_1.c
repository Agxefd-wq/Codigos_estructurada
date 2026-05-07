/* Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

void CargarVecRandomCifras(int [],int,int);
void MostrarVec(int[], int);
int MenorNumVec(int[],int);
int MayorNumVec(int[],int);
void MostrarNumRepetVec(int[],int,int);
void MostrarNumPosicionesVec(int[],int,int);


int main()
{
    int v[TAM];
    int min_num,max_num;
    srand(time(NULL));
    CargarVecRandomCifras(v,TAM,1000);
    MostrarVec(v,TAM);
    min_num=MenorNumVec(v,TAM);
    printf("\nEl menor valor del vector es el numero:\t%d",min_num);
    MostrarNumRepetVec(v,TAM,min_num);
    max_num=MayorNumVec(v,TAM);
    printf("\nEl mayor valor del vector es el numero:\t%d",max_num);
    MostrarNumPosicionesVec(v,TAM,max_num);
    return 0;
}

void CargarVecRandomCifras(int v[],int ce,int lim)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=rand()%lim;
}


void MostrarVec(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        printf("\n%d",v[i]);
}

int MenorNumVec(int v[],int ce)
{
    int min=v[0],i;
    for(i=1;i<ce;i++)
    {
        if(v[i]<min)
            min=v[i];
    }
    return min;
}

int MayorNumVec(int v[],int ce)
{
    int max=v[0],i;
    for(i=1;i<ce;i++)
    {
        if(v[i]>max)
            max=v[i];
    }
    return max;
}


void MostrarNumRepetVec(int v[],int ce,int num)
{
    int i,cont=0;
    for(i=0;i<ce;i++)
    {
        if(v[i]==num)
            cont++;
    }
    printf("\nEl numero %d se entra repetido un total de:\t%d",num,cont);
}

void MostrarNumPosicionesVec(int v[],int ce,int num)
{
    int i;
    printf("\nEl numero %d se encuentra en las posiciones:",num);
    for(i=0;i<ce;i++)
    {
        if(v[i]==num)
            printf("\nPosicion:\n%d",i+1);
    }
}
