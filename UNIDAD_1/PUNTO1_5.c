/*1.5 Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe
ordenar de forma ascendente la colección con dichos códigos para permitir realizar búsquedas binarias.
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código
de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una
venta de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
    CANT UNIDADES   CÓDIGO
        XXX          XXX
        XXX          XXX
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/

#include<stdio.h>
#define TAM 15

void CargarCodigos(int[],int);
void VentasDia(int[],int[],int[],int);
int IngresarYValidarIntRango(int,int);
int IngresarYValidarInt(int);
int IngresarYValidarIntRangoExcepcion(int,int,int);
int BusquedaBinaria(int[],int,int);
int Buscar(int[],int,int);
int MenorNumVec(int[],int);
void MostrarMenoresVendedores(int[],int);
void OrdenarBurbujeoMayoraMenor(int[],int);
void OrdenarBurbujeoDosVec(int[],int[],int);

int main()
{
    int vcodigo[TAM],vcantidad[TAM]={{0}};
    int vvendedores[5]={{0}};
    int i;
    CargarVecCon(vcantidad,TAM,0);
    CargarVecCon(vvendedores,5,0);
    CargarCodigos(vcodigo,TAM);
    OrdenarBurbujeoMayoraMenor(vcodigo,TAM);
    VentasDia(vvendedores,vcantidad,vcodigo,TAM);
    OrdenarBurbujeoDosVec(vcantidad,vcodigo,TAM);
    printf("\nCANTIDAD UNIDADES:\tCODIGO:");
    for (i=0; i<TAM; i++)
    {
        printf("\n%d\t\t\t%d",vcantidad[i],vcodigo[i]);
    }
    printf("\nLos vendedores con menor cantidad de ventas fueron:");
    MostrarMenoresVendedores(vvendedores,5);
    return 0;
}

void CargarVecCon(int v[],int ce,int num)
{
    int i;
    for(i=0;i<ce;i++)
    {
        v[i]=num;
    }
}
void CargarCodigos(int v[],int ce)
{
    int i,codigo,pos;
    for(i=0;i<ce;i++)
    {
        do
        {
            printf("\nIngrese el codigo del %d producto:\t",i+1);
            codigo=IngresarYValidarIntRango(100,999);
            pos=Buscar(v,codigo,i);
            if(pos!=-1)    
            {
                printf("\nERROR-Codigo de producto ya existente");
            }
            else
                v[i]=codigo;
        }while(pos!=-1);
    }

}

void VentasDia(int vendedores[],int cantidad[],int codigo[],int ce)
{
    int pos,vendedor,codigo_producto,cant_producto;
    printf("\nPorfavor ingrese el codigo del vendedor producto-de 1001 a 1005:\t");
    vendedor=IngresarYValidarIntRangoExcepcion(0,1001,1005);
    while(vendedor != 0)
    {
        vendedor-=1001;
        vendedores[vendedor]++;
        printf("\nIngrese el codigo del producto que fue vendido:\t");
        do
        {
            codigo_producto=IngresarYValidarIntRango(0,1000);
            pos=BusquedaBinaria(codigo,codigo_producto,ce);
            if(pos==-1)
                printf("\nERROR-Ingrese un codigo de producto valido:\t");
        } while (pos==-1);
        printf("\nIngrese la cantidad vendida:\t");
        cant_producto=IngresarYValidarInt(0);
        cantidad[pos]+=cant_producto;
        printf("\nPorfavor ingrese el codigo del vendedor producto:\t");
        vendedor=IngresarYValidarIntRangoExcepcion(0,1001,1005);
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

int BusquedaBinaria(int v[],int buscado,int ce)
{

    int pos=-1,li=0,ls=ce-1,med;
    while(pos==-1 && li<=ls)
    {
        med=(li+ls)/2;
        if(v[med]==buscado)
            pos=med;
        else
        {
            if(buscado<v[med])
                li=med+1;
            else
                ls=med-1;
        }    
    }
    //printf("\n%d",pos);
    return pos;
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

void MostrarMenoresVendedores(int v[],int ce)
{

    int min,i;
    min=MenorNumVec(v,ce);
    for(i=0;i<ce;i++)
    {
        if(v[i]==min)
        {
            printf("\nVENDEDOR %d",i+1001);
        }
    }
}

void OrdenarBurbujeoMayoraMenor(int v[],int ce)
{
    int i,j,aux;
    for(i=0;i<ce-1;i++)
    {
        for (j = 0; j < ce-1-i; j++)
        {
            if(v[j]<v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }  
    }
}
int IngresarYValidarIntRangoExcepcion(int exc, int li, int ls)
{
    int num;
    do
    {
        scanf("%d",&num);
        if(num!=exc && (num < li || num > ls))
            printf("\nERROR-Ingrese un valor valido:\t");
    }while(num!=exc && (num < li || num > ls));
    return num;
}
void OrdenarBurbujeoDosVec(int v1[],int v2[],int ce)
{
    int i,j,aux;
    float aux_float;
    for(i=0;i<ce-1;i++)
    {
        for (j = 0; j < ce-1; j++)
        {
            if(v1[j]<v1[j+1])
            {
                aux_float=v1[j];
                v1[j]=v1[j+1];
                v1[j+1]=aux_float;

                aux=v2[j];
                v2[j]=v2[j+1];
                v2[j+1]=aux;
            }
        }  
    }
}