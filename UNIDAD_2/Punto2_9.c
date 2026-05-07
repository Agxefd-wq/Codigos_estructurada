/*Se desea contabilizar los votos recibidos en las elecciones de un club de fútbol. Existen 10 candidatos cada
uno representado por un número de lista diferente (número de 3 cifras no correlativo). La votación se realiza
en 15 sedes distintas codificadas del 1 al 15. Se ingresan los votos registrados en cada una de las sedes
registrando:
• Número de lista
• Número de sede
• Cantidad de votos
(Solo se informan candidatos que recibieron votos).
La carga de votos finaliza con un número de lista igual a 0
Mostrar:
a. Cantidad de votos recibidos por cada candidato en cada sede.
LISTA SEDE1 SEDE2 SEDE3… SEDE15
 873   36     78   99…     XX
 735   XX     XX   XXX…    XX
b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
TOTAL DE VOTOS PORCENTAJE LISTA
800                80%     873
200                20%     735
c. Candidatos que NO recibieron votos en la sede 5.*/
#include<stdio.h>
#define TAM 15

void ContabilizarVotos(int[][TAM],int[],int[],int[],int);
void CargarLista(int[],int);
void MostrarLista(int[][TAM],int[],int,int);
void ObtenerYMostrarVotosTotales(int[],int[],int);
float PorcentajeNum(int,int);
int IngresarYValidarIntRango(int,int);
int IngresarYValidarInt(int);
void OrdenarBurbujeoDosVec(int[],int[],int);
int Buscar(int[],int,int);

int main()
{
    int meleccion[10][15]={{0}};
    int vvotossedecinco[10]={{0}};
    int vlista[10];
    int vcantvotos[10]={{0}};
    int i;
    CargarLista(vlista,10);
    ContabilizarVotos(meleccion,vlista,vvotossedecinco,vcantvotos,10);
    MostrarLista(meleccion,vlista,10,TAM);
    printf("\nLos candidatos que no recibieron votos en la sede 5 son:");
    for(i=0;i<10;i++)
    {
        if(vvotossedecinco[i]==0)
            printf("\nLista: %d",vlista[i]);
    }
    ObtenerYMostrarVotosTotales(vcantvotos,vlista,10);
    return 0;
}

void CargarLista(int v[],int ce)
{
    int i,lista,pos;
    for(i=0;i<ce;i++)
    {
        printf("\nIngrese el %d numero de lista-entre 100 y 999:\t",i+1);
        do
        {
            lista=IngresarYValidarIntRango(100,999);
            pos=Buscar(v,lista,i);
            if(pos!=-1)
            {
                printf("\nERROR-Codigo de lista ya existente");
                printf("\nIngrese el %d numero de lista-entre 100 y 999:\t",i+1);
            }
        }while(pos!=-1);
        v[i]=lista;
    }
}

void ContabilizarVotos(int m[] [TAM],int lista[],int sedecinco[],int cantv[],int cf)
{
    int pos,sede,numlista,cantvotos;
    printf("\nIngrese el codigo de la lista-0 para salir:\t");
    numlista=IngresarYValidarIntRango(0,999);
    while(numlista!=0)
    {
        do
        {
            pos=Buscar(lista,numlista,cf);
            if(pos==-1)
            {
                printf("\nERROR-Codigo inexiste.Ingrese uno valido:\t");
                numlista=IngresarYValidarIntRango(100,999);
            }
        } while (pos==-1);
        printf("\nIngrese la sede-entre 1 y 15:\t");
        sede=IngresarYValidarIntRango(1,15);
        sede-=1;
        if(sede==4)
        {
            sedecinco[pos]++;
        }
        printf("\nIngrese la cantidad de votos:\t");
        cantvotos=IngresarYValidarInt(1);
        cantv[pos]+=cantvotos;
        m[pos][sede]=cantvotos;
        printf("\nIngrese el codigo de la lista-0 para salir:\t");
        numlista=IngresarYValidarIntRango(0,999);
    }

}

void MostrarLista(int m[] [TAM],int lista[],int cf,int cc)
{
    int i,j,z;
    printf("\nLISTA");
    for(i=0;i<cc;i++)
    {
        if(i<2)
            printf(" SEDE%d ",i+1);
        else 
            printf("  SEDE%d ",i+1);
    }
    for(j=0;j<cf;j++)
    {
        printf("\n %d",lista[j]);
        for(z=0;z<cc;z++)
        {
            printf("\t%d",m[j][z]);
        }
    }
}

void ObtenerYMostrarVotosTotales(int cant[],int lista[],int ce)
{
    int i,j,total=0;
    for(i=0;i<ce;i++)
        total+=cant[i];
    OrdenarBurbujeoDosVec(cant,lista,ce);
    printf("\nTOTAL DE VOTOS:   PORCENTAJE:   LISTA:");
    for(j=0;j<ce;j++)
    {
        printf("\n   %d\t\t    %.2f\t   %d",cant[j],PorcentajeNum(total,cant[j]),lista[j]);
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

float PorcentajeNum(int total,int num)
{
    float result;
    result=(num*100)/total;
    return result;
}