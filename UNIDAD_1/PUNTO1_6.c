/*Dado un conjunto de 10 números enteros ordenados de menor a mayor, ingresar por teclado 3 números más
no ordenados. Insertarlos donde correspondan. Mostrar en pantalla la serie inicial y la final. */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void CargarVecRandomCifras(int [],int,int);
void MostrarVec(int[], int);
void OrdenarBurbujeo(int[],int,int);
void IngresarYColocarIntVec(int[],int,int);
void OrdenarIntVec(int[],int,int);
int main()
{

    int v[13]={{0}};
    srand(time(NULL));
    CargarVecRandomCifras(v,10,100);
    OrdenarBurbujeo(v,13,0);
    printf("\nEste es el vector original:");
    MostrarVec(v,13);
    IngresarYColocarIntVec(v,13,3);
    return 0;
}

void IngresarYColocarIntVec(int v[],int ce,int elibre)
{
    int i,num;
    for(i=0;i<elibre;i++)
    {
        printf("\nIngrese el %d numero entero:\t",i+1);
        scanf("%d",& num);
        v[i]=num;
        OrdenarIntVec(v,ce,i);
        //MostrarVec(v,ce);
    }

}

void OrdenarIntVec(int v[],int ce,int idv)
{
    int i,aux,desordenado;
    int num=v[idv];
    for(i=idv;i<ce;i++)
    {
        desordenado=0;
        if(num<v[i])
        {
            aux=v[i];
            v[i]=num;
            num=aux;
            desordenado=1;
        }
        if(i==ce-1 && desordenado==1)
        {
            v[0]=num;
        }
    }
    MostrarVec(v,ce);

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
void OrdenarBurbujeo(int v[],int ce,int op)
{
    int i,j,aux;
    for(i=0;i<ce-1;i++)
    {
        for (j = 0; j < ce-1-i; j++)
        {
            if(op==1 && v[j]<v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
            if(op==0 && v[j]>v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;   
            }
        }  
    }
}