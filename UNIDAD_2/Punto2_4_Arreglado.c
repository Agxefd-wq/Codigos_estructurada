/*La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours a través de 15 agencias en todo
el país. Diariamente cada agencia envía la cantidad de ventas efectuadas de cada tour, indicando agencia,
tours y la cantidad de pasajes. Algunas agencias envían 0 en la cantidad cuando no existen pasajes para un
tour determinado, pero no en todas.
La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
• Código de agencia (de 1 a 15)
• Código de tour (1 a 10)
• Cantidad de pasajes (0 a 20)
Informar:
a. El total de pasajes vendidos por tour en cada agencia.
b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos. (puede repetirse) */
#include<stdio.h>

int IngresarYValidarIntRango(int,int);
void VentasEfectuadas(int[][15]);
void MostrarVentas(int [][15],int,int);
void SumaColumnMatAVec(int[] [15],int[],int,int);
int MayorNumVec(int[],int);

int main()
{
    int matguadalajara [10] [15]={{0}};
    int vagencia[15]={{0}};
    int i,max;
    VentasEfectuadas(matguadalajara);
    SumaColumnMatAVec(matguadalajara,vagencia,10,15);
    MostrarVentas(matguadalajara,10,15);
    max=MayorNumVec(vagencia,15);
    printf("\nLa agencia/s que vendieron la mayor cantidad de pasajes fueron:");
    for(i=0;i<15;i++)
    {
        if(vagencia[i]==max)
            printf("\nAgencia %d",i+1);
    }
    return 0;
}

void VentasEfectuadas(int mat[] [15])
{
    int codigo,tour,cant_pasaje;
    printf("\nIngrese el codigo de la agencia-entre 1 y 15-0 para terminar:\t");
    codigo=IngresarYValidarIntRango(0,15);
    while(codigo!=0)
    {
        codigo-=1;
        printf("\nIngrese el codigo del tour-entre 1 y 10:\t");
        tour=IngresarYValidarIntRango(1,10);
        tour-=1;
        printf("\nIngrese la cantidad de pasajes-max 20:\t");
        cant_pasaje=IngresarYValidarIntRango(0,20);
        mat[tour] [codigo]+=cant_pasaje;
        printf("\nIngrese el codigo de la agencia-entre 1 y 15-0 para terminar:\t");
        codigo=IngresarYValidarIntRango(0,15);
    }
}

void MostrarVentas(int mat[] [15],int cf,int cc)
{
    int f,c,i;
    printf("\n\t");
    for(i=0;i<cc;i++)
    {
        if(i>10)
            printf("  A%d",i+1);
        else
            printf("   A%d ",i+1);
    }
    for(f=0;f<cf;f++)
    {
        printf("\nTour %d",f+1);
        for(c=0;c<cc;c++)
        {
            printf("%6d",mat[f] [c]);
        }
    }
}

int IngresarYValidarIntRango(int li,int ls)
{
    int num;
    do
    {
        scanf("%d",& num);
        if(num<li || num>ls)
            printf("\nERROR-Ingrese un valor entre %d y %d:\t",li-1,ls+1);
    } while (num<li || num>ls);
    return num;
}

void SumaColumnMatAVec(int mat[][15],int v[],int cf,int cc)
{
    int f,c;
    for(c=0;c<cc;c++)
    {
        v[c]=0;
        for(f=0;f<cf;f++)
        {
            v[c]+= mat[f] [c];
        }
    }
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