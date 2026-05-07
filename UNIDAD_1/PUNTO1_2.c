/* Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
 La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades*/

#include<stdio.h>
#define TAM 10


void IngresarCodigo(int[],int);
void RealizarPedidos(int[],int[],int);
int Buscar(int[],int,int);
int IngresarYValidarIntRango(int,int);
int IngresarYValidarInt(int);
int MenorNumVec(int[],int);
int MayorNumVec(int[],int);
void MostrarMayoresVec(int[],int[],int);
void MostrarMenoresVec(int[],int[],int);


int main()
{
    int vcodigos[TAM];
    int vcantidad[TAM]={{0}};
    int i;
    IngresarCodigo(vcodigos,TAM);
    RealizarPedidos(vcodigos,vcantidad,TAM);
    printf("\nPRODUCTOS:\tCANTIDAD:");
    for (i=0; i<TAM; i++)
    {
        printf("\n%d\t\t%d",vcodigos[i],vcantidad[i]);
    }
    printf("\nLos productos que vendieron mas fueron:");
    MostrarMayoresVec(vcodigos,vcantidad,TAM);
    printf("\nLos productos que vedieron menos fueron:");
    MostrarMenoresVec(vcodigos,vcantidad,TAM);
    return 0;
}

void IngresarCodigo(int v[],int ce)
{
    int i,pos;
    int codigo;
    for(i=0;i<ce;i++)
    {
        printf("\nIngrese el codigo del producto numero %d:\t",i+1);
        do
        {
            codigo=IngresarYValidarIntRango(1000,9999);
            pos=Buscar(v,codigo,i);
            if(pos!=-1)
                printf("\nERROR-Dato Duplicado,Ingrese otro:\t");
        }while (pos!=-1);
        v[i]=codigo;
    }
}

void RealizarPedidos(int v1[],int v2[],int ce)
{
    int codigo,cant,pos;
    printf("\nIngrese el codigo del producto que desea elegir-0 para terminar:\t");
    codigo=IngresarYValidarIntRango(0,9999);
    while(codigo!=0)
    {
        pos=Buscar(v1,codigo,ce);
        if(pos!=-1)
        {
            printf("\nIngrese la cantidad vendida:\t");
            cant=IngresarYValidarInt(0);
            v2[pos]+=cant;
        }
        else
            printf("\nERROR-Producto inexistente");
    printf("\nIngrese el codigo del producto que desea elegir-0 para terminar:\t");
    codigo=IngresarYValidarIntRango(0,9999);
    }
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
    return pos;
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

int IngresarYValidarInt(int li)
{
    int num;
    do
    {
        scanf("%d",& num);
        if(num<li)
            printf("\nERROR-Ingrese un valor mayor a %d:\t",li-1);
    } while(num<li);
    return num;
}

void MostrarMayoresVec(int v1[],int v2[],int ce)
{

    int max,i;
    max=MayorNumVec(v2,ce);
    for(i=0;i<ce;i++)
    {
        if(v2[i]==max)
        {
            printf("\n%d",v1[i]);
        }
    }
}

void MostrarMenores(int v1[],int v2[],int ce)
{

    int min,i;
    min=MenorNumVec(v2,ce);
    for(i=0;i<ce;i++)
    {
        if(v2[i]==min)
        {
            printf("\n%d",v1[i]);
        }
    }
}
