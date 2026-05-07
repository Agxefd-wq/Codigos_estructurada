/*Una empresa desea registrar las ventas realizadas de cada uno de sus 20 productos a lo lardo del año. Los
productos están identificados por códigos numéricos de 3 cifras. Como primera información se ingresa el
precio unitario de cada uno de los productos y su código. Luego por cada venta se ingresa:
• Código de producto
• Día de venta
• Mes de venta
• Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. Informar:
a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
b. El producto con el cual se obtuvo la mayor recaudación.
c. El trimestre de menor recaudación del año.
*/

//////CONSULTAR///////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define TAM 20

void CargarProductos(int[],float[],int);
void CargarVentas(int[][TAM],int[],int[],int);
void MostrarVentas(int[][TAM],int,int);
void EncontrarYMostrarProductoMayorRecaudacion(int[],int[],float[],int);
void EncontrarYMostrarMenorTrimestre(int[][TAM],int[],float[],int,int);
void MostrarVec(int[], int);
void MostrarVecFloat(float[], int);
int EsFechaValida(int,int,int);
int CantidadDiasDelMes(int,int);
int Bisiesto(int);
int IngresarYValidarInt(int);
int IngresarYValidarIntRango(int,int);
float IngresarYValidarFloat(int);
void SumaFilaMatAVec(int[] [20],float[],int,int);
float MenorNumVec(float[],int);
float MayorNumVec(float[],int);
int Buscar(int[],int,int);
int BuscarFloat(float[],float,int);

int main()
{
    int mventasanio[12] [TAM]={{0}};
    int vcodigos[TAM];
    int vcantidad[TAM]={{0}};
    float vprecio[TAM];
    srand(time(NULL));
    CargarProductos(vcodigos,vprecio,TAM);
    MostrarVec(vcodigos,TAM);
    printf("\n");
    MostrarVecFloat(vprecio,TAM);
    CargarVentas(mventasanio,vcodigos,vcantidad,TAM);
    MostrarVentas(mventasanio,12,TAM);
    EncontrarYMostrarProductoMayorRecaudacion(vcodigos,vcantidad,vprecio,TAM);
    EncontrarYMostrarMenorTrimestre(mventasanio,vcantidad,vprecio,12,TAM);
    return 0;
}

void CargarProductos(int codigos[],float precios[],int ce)
{
    int i,cod,val,pos;
    int num1,num2;
    for(i=0;i<ce;i++)
    {
        /*        do
        {
            printf("\nIngrese el codigo del %d producto-entre 99 y 1000:\t",i+1);
            cod=IngresarYValidarIntRango(100,999);
            pos=Buscar(codigos,cod,i);
            if(pos!=-1)
                printf("\nERROR-CODIGO DUPLICADO.Porfavor ingrese un codigo valido.");
        }while(pos!=-1);
        printf("\nIngrese su precio:\t");
        val=IngresarYValidarFloat(0);
        codigos[i]=cod;
        precios[i]=val;*/
        do{
            num1=rand()%1000;
            pos=Buscar(codigos,num1,i);
        }while(pos!=-1);
        num2=rand()%100;
        codigos[i]=num1;
        precios[i]=num2;
    }
}

void CargarVentas(int ventas[][20],int codigos[],int cantidad[],int cc)
{
    int cod,cantvendido,pos,d,m,a=2026;
    int fvalida;
    printf("\nIngrese el codigo del producto-0 para terminar:\t");
    cod=IngresarYValidarIntRango(0,999);
    while(cod!=0)
    {
        do{
            pos=Buscar(codigos,cod,cc);
            if(pos==-1)
            {
                printf("\nERROR-Codigo inexistente.Introduzca uno valido:");
                cod=IngresarYValidarIntRango(100,999);
            }
        }while(pos==-1);
        do
        {
            printf("\nIngrese el dia:\t");
            scanf("%d",& d);
            printf("\nIngrese el mes:\t");
            scanf("%d",& m);
            fvalida=EsFechaValida(d,m,a);
            if(!fvalida)
                printf("\nERROR-Ingrese una fecha valida");
        }while(!fvalida);
        printf("\nIntroduzca la cantidad vendida:");
        cantvendido=IngresarYValidarInt(0);
        ventas[m-1][pos]+=cantvendido;
        cantidad[pos]+=cantvendido;
        printf("\nIngrese el codigo del producto-0 para terminar:\t");
        cod=IngresarYValidarIntRango(0,999);
    }
}

void MostrarVentas(int mat[][20],int cf,int cc)
{
    int f,c,i;
    printf("\n\t");
    for(i=0;i<cc;i++)
    {
        if(i>10)
            printf("  P%d",i+1);
        else
            printf("  P%d ",i+1);
    }
    for(f=0;f<cf;f++)
    {
        printf("\nMes %d",f+1);
        for(c=0;c<cc;c++)
        {
            printf("%6d",mat[f] [c]);
        }
    }
}

void EncontrarYMostrarProductoMayorRecaudacion(int codigos[],int cantidad[],float precios[],int ce)
{
    float vrecaudacion[ce];
    int i,productopos;
    float max;
    for(i=0;i<ce;i++)
    {
        vrecaudacion[i]=cantidad[i]*precios[i];
    }
    max=MayorNumVec(vrecaudacion,ce);
    productopos=BuscarFloat(vrecaudacion,max,20);
    printf("\nEl producto con mayor recaudacion es:\nProducto %d:\t%f",codigos[productopos],max);
}

void EncontrarYMostrarMenorTrimestre(int mat[][20],int cantidad[],float precios[],int cf,int cc)
{
    int i;
    float vtrimestre[cf];
    float vaux[cf];
    for(i=0;i<cf;i++)
    {
        if(i==2)
        {
            SumaFilaMatAVec(mat,vtrimestre,3,cc);
            printf("\n");
            MostrarVecFloat(vtrimestre,cf);
        }
        vaux[]=vtrimestre[];
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

float IngresarYValidarFloat(int li)
{
    float num;
    do
    {
        scanf("%f",& num);
        if(num<li)
            printf("\nERROR-Ingrese un valor mayor a %d:\t",li-1);
    } while(num<li);
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

float MayorNumVec(float v[],int ce)
{
    float max=v[0];
    int i;
    for(i=1;i<ce;i++)
    {
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

float MenorNumVec(float v[],int ce)
{
    float min=v[0];
    int i;
    for(i=1;i<ce;i++)
    {
        if(v[i]<min)
            min=v[i];
    }
    return min;
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

int BuscarFloat(float vec[],float dato,int ce)
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

void MostrarVec(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        printf(" %d ",v[i]);
}

void MostrarVecFloat(float v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        printf(" %5f ",v[i]);
}

void SumaFilaMatAVec(int mat[][20],float v[],int cf,int cc)
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

int EsFechaValida(int d,int m,int a)
{
    int r=0;
    if(a>=1582)
    {
        if(m>=1 && m<=12)
            if(d>=1 && d<=CantidadDiasDelMes(m,a))
                r=1;
    }
    return r;
}

int CantidadDiasDelMes(int m,int a)
{
    int cdm;
    if(m==4||m==6||m==9||m==11)
    {
        cdm=30;
    }
    if(m==2)
        cdm=28+Bisiesto(a);
    else    
        cdm=31;
    return cdm;
}

int Bisiesto(int a)
{
    int i;
    if((a%4==0 && a%100!=0)|| a%400==0)
        i=1;
    else
        i=0;
    return i;
}