#include<stdio.h>
#define TAM 12

void CargarMat(int[][TAM]);//
void PonerEnCeroM(int[][TAM],int,int);//
void PonerEnCero(int[],int);//
void MostrarMatFila(int[][TAM],int,int);//
void MostrarIgualA(int[],int,int);//
void MostrarVecColumnM(int[][TAM],int,int);//
void MostrarVec(int[], int);//
int ContarIgualA(int[],int,int);//
void SumFilaMatEnV(int[][TAM],int[],int,int);//
void SumColumMatEnV(int[][TAM],int[],int,int);//
int PosicionMaxV(int[],int);//
int Maximo(int[],int);//
int Minimo(int[],int);//
int IngresarYValidarIntRango(int,int);//
int IngresarYValidarInt(int);//

int main()
{
    int supermercado[5] [TAM];
    int vrub[TAM],vsucursal[5];
    int min,sinvta;
    PonerEnCeroM(supermercado,5,TAM);
    PonerEnCero(vrub,TAM);
    PonerEnCero(vsucursal,5);
    CargarMat(supermercado);
    MostrarMatFila(supermercado,5,TAM);
    printf("\nCANTIDAD PEDIDA POR SUCURSAL:");
    SumFilaMatEnV(supermercado,vsucursal,5,TAM);
    MostrarVec(vsucursal,5);
    printf("\nCANTIDAD PEDIDA POR RUBRO:");
    SumColumMatEnV(supermercado,vrub,5,TAM);
    MostrarVec(vrub,TAM);
    printf("\nEl rubro con mayor cantidad de pedida es el:\t%d",PosicionMaxV(vrub,12)+1);
    printf("\nLa cantidad de pedidos del rubro 7 es:");
    MostrarVecColumnM(supermercado,5,6);
    min=Minimo(vsucursal,5);
    printf("\nLa sucursal con menor cantidad de pedidos es:");
    MostrarIgualA(vsucursal,5,min);
    sinvta=ContarIgualA(vrub,TAM,0);
    printf("\nLa cantidad de rubros sin ventas es igual a:\t%d",sinvta);
    return 0;
}

void CargarMat(int m[][TAM])
{
    int rub,sur,cant;
    printf("\nIngrese el numero de la sucursal-entre 1 y 5-0 para terminar:\t");
    sur=IngresarYValidarIntRango(0,5);
    while(sur!=0)
    {
        sur-=1;
        printf("\nIngrese el numero del rubro-entre 1 y 12:\t");
        rub=IngresarYValidarIntRango(1,12);
        rub-=1;
        printf("\nIngrese la cantidad vendida:\t");
        cant=IngresarYValidarInt(1);
        m[sur][rub]+=cant;
        printf("\nIngrese el numero de la sucursal-entre 1 y 5-0 para terminar:\t");
        sur=IngresarYValidarIntRango(0,5);
    }

}

void MostrarMatFila(int m[][TAM],int cf,int cc)
{
    int f,c,i;
    printf("\n");
    printf("\t    0 ");
    for(i=0;i<cc;i++)
    {
        printf("R%d ",i+1);
    }
    for(f=0;f<cf;f++)
    {   
        printf("\nSucursal %d:",f+1);
        for(c=0;c<cc;c++)
        {
            printf("%3d",m[f] [c]);
        }
    }
}

void MostrarVecColumnM(int m[][TAM],int cf,int column)
{
    int i;
    for(i=0;i<cf;i++)
    {
        printf("\n%d",m[i][column]);
    }
}


void MostrarIgualA(int v[],int ce,int num)
{
    int i;
    for(i=0;i<ce;i++)
    {
        if(v[i]==num)
            printf(" %d",i+1);
    }
}


void PonerEnCeroM(int m[][TAM],int cf,int cc)
{
    int f,c;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            m[f][c]=0;
        }
    }
}

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
}

int ContarIgualA(int v[],int ce,int num)
{
    int i,c=0;
    for(i=0;i<ce;i++)
    {
        if(v[i]==num)
            c++;
    }
    return c;
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

int PosicionMaxV(int v[],int ce)
{
    int i,max,pos;
    max=Maximo(v,ce);
    for(i=0;i<ce;i++)
    {
        if(v[i]==max)
            pos=i;
    }
    return pos;
}

int Minimo(int v[],int ce)
{
    int min=v[0],i;
    for(i=1;i<ce;i++)
    {
        if(v[i]<min)
            min=v[i];
    }
    return min;
}

int Maximo(int v[],int ce)
{
    int max=v[0],i;
    for(i=1;i<ce;i++)
    {
        if(v[i]>max)
            max=v[i];
    }
    return max;
}


void SumFilaMatEnV(int mat[][TAM],int v[],int cf,int cc)
{
    int f,c;
    for(f=0;f<cf;f++)
    {
        v[f]=0;
        for(c=0;c<cc;c++)
        {
            v[f]+= mat[f] [c];
        }
    }
}

void SumColumMatEnV(int mat[][TAM],int v[],int cf,int cc)
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

void MostrarVec(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        printf("\n%d",v[i]);
}