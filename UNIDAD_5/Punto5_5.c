/*Al programa anterior agregarle una función que reciba la dirección de inicio del vector y un número a buscar
y retorne un puntero al dato encontrado o NULL sino lo encuentra. En el main agregar un proceso de
búsqueda que se repita hasta ingresar un número negativo o cero a buscar. Si se lo encontró se debe
indicar en que posición del vector estaba (calcular dicha posición utilizando la dirección retornada)*/

#include<stdio.h>

void CargarVect(int[],int);
void MostrarVect(int[],int);
int* BuscarPuntero(int*,int,int);
int main()
{
    int *ppos;
    int vec[10];
    int numbuscar;
    int posreal;
    CargarVect(vec,10);
    //MostrarVect(vec,10);
    //pvec=vec;
    printf("\nLa direccion del primer elemento de v es: %x",vec);
    //printf("\nSi no es: %x",vec);
    //printf("\nO es: %x",&vec[2]);
    printf("\nIngrese un numero a buscar-Igual o menor a 0 para terminar:\t");
    scanf("%d",&numbuscar);
    while(numbuscar>0)
    {
        ppos=BuscarPuntero(vec,numbuscar,10);
        if(ppos==NULL)
            printf("\nEl numero no existe en el vector.");
        else
        {
            posreal=ppos-vec;
            printf("\nEl numero existe en el vector.Esta en %d",posreal);
        }
        printf("\nIngrese un numero a buscar-Igual o menor a 0 para terminar:\t");
        scanf("%d",&numbuscar);
    }
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

int* BuscarPuntero(int *v,int num,int ce)
{
    int i=0;
    int *puntero=NULL;
    while(i<ce && puntero==NULL)
    {
        if(*(v+i)==num)
            puntero=v+i;
        else
            i++;
    }
    return puntero;
}