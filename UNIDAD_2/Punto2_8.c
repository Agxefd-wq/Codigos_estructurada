/*Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos donde existen 15
departamentos en cada piso. El valor de las expensas es de $ 1000. Para registrar la cobranza se ingresa el
número de piso (1 a 5) y el número de departamento (correlativo de 1 a 15 en cada piso). El ingreso finaliza
con un piso igual a 99.
Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:
*/
#include<stdio.h>
#define TAM 15

float IngresarYValidarFloat(int);
int IngresarYValidarIntRango(int,int);
int IngresarYValidarIntRangoExcepcion(int,int,int);
void CobrarExpensa(float[][TAM],float[]);
float SumaVecFloat(float[],int);
void MostrarRecaudado(float[][TAM],float,int,int);

int main()
{
    float matcobranza[5][TAM]={{0}};
    float vrecaudado[TAM]={{0}};
    float totalrecaudado;
    CobrarExpensa(matcobranza,vrecaudado);
    totalrecaudado=SumaVecFloat(vrecaudado,TAM);
    MostrarRecaudado(matcobranza,totalrecaudado,5,TAM);
    return 0;
}

void CobrarExpensa(float mat[][15],float recaudado[])
{
    int codigo,departamento;
    float dinero;
    printf("\nIngrese el numero de piso-entre 1 y 5-99 para terminar:\t");
    codigo=IngresarYValidarIntRangoExcepcion(99,1,5);
    while(codigo!=99)
    {
        printf("\nIngrese el numero del departamento-entre 1 y 15:\t");
        departamento=IngresarYValidarIntRango(1,15);
        printf("\nIngrese el dinero recaudado:\t");
        dinero=IngresarYValidarFloat(0);
        mat[codigo-1][departamento-1]=dinero;
        recaudado[departamento-1]+=dinero;
        printf("\nIngrese el numero de piso-entre 1 y 5-99 para terminar:\n");
        codigo=IngresarYValidarIntRangoExcepcion(99,1,5);
    }
}

void MostrarRecaudado(float mat[][15],float total,int cf,int cc)
{
    int f,c,i;
    printf("\n\t\t\t\t\t\tTOTAL RECAUDADO:%f\n\t\t\t\t\t\tDEPARTAMENTOS DEUDORES",total);
    printf("\n PISO");
    for(i=0;i<cc;i++)
    {
        if(i>10)
            printf("  DPTO%d",i+1);
        else
            printf("   DPTO%d",i+1);
    }
    for(f=0;f<cf;f++)
    {
        printf("\nPISO%d",f+1);
        for(c=0;c<cc;c++)
        {
            if(mat[f] [c]<1000)
                printf("\t  X");
            else
                printf("\t  ");
        }
    }
}

float SumaVecFloat(float v[],int ce)
{
    int i;
    float num=0;
    for (i = 0; i < ce; i++)
    {
        num+=v[i];
    }
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

int IngresarYValidarIntRangoExcepcion(int exc, int li, int ls)
{
    int num;
    do
    {
        scanf("%d",&num);
        if(num!=exc && (num < li || num > ls))
            printf("\nERROR-Ingrese un valor valido entre %d y %d- %d para terminar:\t",li-1,ls+1,exc);
    }while(num!=exc && (num < li || num > ls));
    return num;
}