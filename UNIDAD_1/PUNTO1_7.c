/*Dado un vector de 10 enteros, ingresar un entero por teclado, buscarlo y, si se lo encuentra, generar un nuevo
vector con los índices correspondientes a las ubicaciones en el primer vector del entero ingresado.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 10

void IngresarIntYGenerarVec(int [],int [],int);
void CargarVecCon(int[],int,int);
void CargarVecRandomCifras(int [],int,int);
void MostrarVec(int[], int);
int Buscar(int[],int,int);
void NumPosicionesVec(int[],int,int);

int main()
{
    int voriginal[TAM];
    int vnuevo[TAM];
    CargarVecCon(vnuevo,TAM,-1);
    CargarVecRandomCifras(voriginal,TAM,10);
    printf("Este es el primer vector:");
    MostrarVec(voriginal,TAM);
    IngresarIntYGenerarVec(voriginal,vnuevo,TAM);
    printf("\nEste es el vector que contiene las posiciones del numero que ingreso:");
    MostrarVec(vnuevo,TAM);
    return 0;
}

void IngresarIntYGenerarVec(int vviejo[],int vnuevo[],int ce)
{
    int num,pos,i,cont=0;
    do
    {
        printf("\nIngrese un numero entero:\t");
        scanf("%d",& num);
        pos=Buscar(vviejo,num,ce);
        if(pos==-1)
        {
            printf("\nEl numero ingresado no existe en el vector,intente con otro numero.");
        }
    }while(pos==-1);
    for(i=0;i<ce;i++)
    {
        if(vviejo[i]==num)
        {
            vnuevo[cont]=i;
            cont++;
        }
    }
}

void CargarVecCon(int v[],int ce,int num)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=num;
}
void CargarVecRandomCifras(int v[],int ce,int lim)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=rand()%lim;
}

int Buscar(int vec[],int dato,int ce)
{
    int pos=-1,i=0;
    while(pos==-1 && i<ce)
    {
        if(vec[i]==dato)
            pos=i;
        else
            i++;
    }
    //printf("\n%d",pos);
    return pos;
}


void MostrarVec(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        printf("\n%d",v[i]);
}

void NumPosicionesVec(int v[],int ce,int num)
{
    int i;
    for(i=0;i<ce;i++)
    {
        if(v[i]==num)
            printf("\nPosicion:\n%d",i+1);
    }
}
