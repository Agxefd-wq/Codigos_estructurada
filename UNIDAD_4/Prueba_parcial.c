/*TEMA A*/
#include<stdio.h>
#define TAM 3

typedef struct 
{
    int cod;
    char apellynombr[51];
    int ant;
    float impkm;
}TChofer;

void Viajes(TChofer[],int);
void ViajesDia(TChofer[],int[],int);
int IngrIntVal(int,int);
int esIntVal(int,int,int);
int esCharVal(char,int,int,int,int);
int BuscarChofer(TChofer[],int,int);
int MayorKM(int[],int);
int main()
{
    TChofer v[TAM];
    int kmrecorrido[TAM]={{0}};
    float importetotal[TAM];
    int j,k,l,mayorKM;
    Viajes(v,TAM);
    ViajesDia(v,kmrecorrido,TAM);
    printf("\nCHOFER:\t APELLIDO Y NOMBRE:\t     KMS recorridos:  IMPORTE RECAUDADO:");
    for(j=0;j<TAM;j++)
    {
        importetotal[j]=kmrecorrido[j]*v[j].impkm;
        printf("\n %-4d   %-50s%d   %.2f",v[j].cod,v[j].apellynombr,kmrecorrido[j],importetotal[j]);
    }
    mayorKM=MayorKM(kmrecorrido,TAM);
    printf("\nLos choferes con mas kms recorridos son:");
    for(k=0;k<TAM;k++)
    {
        if(kmrecorrido[k]==mayorKM)
            printf("\nCHOFER %d",v[k].cod);
    }
    printf("\nLos choferes sin kms recorridos son:");
    for(l=0;l<TAM;l++)
    {
        if(kmrecorrido[l]==0)
            printf("\nCHOFER %d",v[l].cod);
    }
    return 0;
}

void Viajes(TChofer v[],int ce)
{
    int i,pos,mal;
    TChofer aux;
    for(i=0;i<ce;i++)
    {
        mal=0;
        do
        {
            if(mal)
                printf("\nIngrese un codigo valido:");
            else
                printf("\nIngrese el codigo del %d conductor-4 digitos:\t",i+1);
            mal=1;
            aux.cod=IngrIntVal(1000,9999);
            pos=BuscarChofer(v,aux.cod,i);
            if(pos!=-1)
                printf("\nERROR-Codigo ya existente.");
        } while (pos!=-1);
        mal=0;
        printf("\nIngrese el apellido y nombre del conductor:\t");
        fflush(stdin);
        gets(aux.apellynombr);
        do
        {
            if(mal)
                printf("\nIngrese una antiguedad valida:\t");
            else
                printf("\nIngrese la antiguedad del conductor:\t");
            mal=1;
            scanf("%d",& aux.ant);
        } while (aux.ant<0);
        mal=0;
        do
        {
            if(mal)
                printf("\nIngrese un importe valido:\t");
            else
                printf("\nIngrese el importe por km-Igual o mayor a 2150:\t");
            mal=1;
            scanf("%f",&aux.impkm);
        } while (aux.impkm<2150);
        v[i]=aux;
    }
}

void ViajesDia(TChofer v[],int km[],int ce)
{
    int cod,kmrecorridos,pos,mal;
    char zona;
    printf("\nIngrese el codigo del chofer-Ingrese 999 para terminar:\t");
    cod=IngrIntVal(999,9999);
    while(cod!=999)
    {
        mal=0;
        do
        {
            pos=BuscarChofer(v,cod,ce);
            if(pos==-1)
            {
                printf("\nERROR-Codigo invalido");
                printf("\nIngrese un codigo valido:\t");
                cod=IngrIntVal(999,9999);
            }
        } while (pos==-1);
        do
        {
            if(mal)
                printf("\nIngrese un km valido:\t");
            else
                printf("\nIngrese los kms recorridos:\t");
            mal=1;
            scanf("%d",& kmrecorridos);
        } while (kmrecorridos<=0);
        mal=0;
        do
        {
            if(mal)
                printf("\nIngrese una zona valida:\t");
            else
                printf("\nIngrese la zona recorrida-L-B-P-N:\t");
            mal=1;
            fflush(stdin);
            scanf("%c",& zona);
        } while (!esCharVal(zona,'L','B','P','N'));
        km[pos]+=kmrecorridos;
        printf("\nIngrese el codigo del chofer-Ingrese 999 para terminar:\t");
        cod=IngrIntVal(999,9999);
    }
}

int BuscarChofer(TChofer v[],int codigo,int ce)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if(v[i].cod==codigo)
            pos=i;
        else
            i++;
    }
    return pos;
}

int esCharVal(char c,int i,int j,int k,int l)
{
    int error;
    if(c==i||c==j||c==k||c==l)
        error=1;
    else
        error=0;
    return error;
}

int MayorKM(int v[],int ce)
{
    int i,max;
    max=v[0];
    for(i=1;i<ce;i++)
    {
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

int IngrIntVal(int li,int ls)
{
    int n,mal=0;
    do
    {
        if(mal)
            printf("\nIngrese un numero correcto:\t");
        mal=1;
        scanf("%d",& n);
    } while(!esIntVal(n,li,ls));
    return n;
}

int esIntVal(int n,int li,int ls)
{
    int error;
    if(n>=li && n<=ls)
        error=1;
    else
        error=0;
    return error;
}