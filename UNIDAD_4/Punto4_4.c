/*Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
• Número de cliente (entero de 4 dígitos no correlativos).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).
El ingreso de datos finaliza con un número de cliente 999.
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:
• Código de cliente (entero de 4 dígitos no correlativos).
• Nombre y Apellido (50 caracteres máximo).
Se solicita:
a. Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada
cliente, informando:
CODIGO DE CLIENTE NOMBRE Y APELLIDO TOTAL FACTURADO
X XXXXX                 XXXXXXXX    $ XXXXXXXXX,XX
*/

#include<stdio.h>

#define TAM 3

typedef struct 
{
    int cod;
    char apellynombr[51];
}TCliente;

typedef struct 
{
    TCliente cliente;
    float importe;
    int ventascliente; 
}TVentas;

void CARGA_CLIENTE(TVentas[],int);
void IngresoVentas(TVentas[],int[],int);
void OrdenarImportes(TVentas[],int,int);
int BuscarCliente(TVentas[],int,int);
int esDatoVal (int, int, int);
int IngrDatoVal (int, int);

int main()
{
    int i,j,k,l;
    TVentas Vclientes[TAM];
    int Vvendedores[10]={{0}};
    CARGA_CLIENTE(Vclientes,TAM);
    for(i=0;i<TAM;i++)
    {
        Vclientes[i].importe=0;
        Vclientes[i].ventascliente=0;
    }
    printf("\nIngrese el codigo del cliente que compro-Ingrese 999 para terminar:\t");
    IngresoVentas(Vclientes,Vvendedores,TAM);
    printf("\nLa cantidad de ventas realizadas por cliente fue:");
    for(j=0;j<TAM;j++)
    {
        printf("\nCliente %d: %d",Vclientes[j].cliente.cod,Vclientes[j].ventascliente);
    }
    printf("\nLa cantidad de ventas realizadas por vendedor:\t");
    for(k=0;k<10;k++)
    {
        printf("\nVendedor %d: %d",k+1,Vvendedores[k]);
    }
    OrdenarImportes(Vclientes,TAM,0);
    printf("\n%s %7s %9s","CODIGO DE CLIENTE","NOMBRE Y APELLIDO","TOTAL FACTURADO");
    for(l=0;l<TAM;l++)
    {
        printf("\n%2d\t%5s      %.2f",Vclientes[l].cliente.cod,Vclientes[l].cliente.apellynombr,Vclientes[l].importe);
    }
    return 0;
}

int BuscarCliente(TVentas V[],int abuscar,int ce)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if(V[i].cliente.cod==abuscar)
            pos=i;
        else
            i++;
    }
    return pos;
}

int esDatoVal (int num, int inf, int sup)
{
    int i;
    if (num >= inf && num <= sup)
        i = 1;
    else
        i = 0;
    return i;
}

int IngrDatoVal (int li, int ls)
{ 
    int num, mal=0;
    do {
        if (mal)                                  //Control error para mensaje
            printf("ERROR-Ingrese un valor valido:\t");
        scanf ("%d", &num);
        mal=1;
    } while (esDatoVal (num, li, ls) == 0);

  return num;
}

void CARGA_CLIENTE(TVentas V[],int ce)
{
    TVentas aux;
    int i,mal,pos;
    for(i=0;i<ce;i++)
    {
        mal=0;
        do
        {
            do
            {   
                if(mal)
                    printf("\nIngrese un codigo valido:\t");
                else
                    printf("\nIngrese el codigo del %d cliente-Excepto 999:\t",i+1);
                mal=1;
                aux.cliente.cod=IngrDatoVal(0,9999);
            }while(aux.cliente.cod==999);
            pos=BuscarCliente(V,aux.cliente.cod,i);
            if(pos!=-1)
                printf("\nERROR-CODIGO YA EXISTE.");
        } while(pos!=-1);
        fflush(stdin);
        printf("\nIngrese el apellido y nombre del cliente:\t");
        gets(aux.cliente.apellynombr);
        V[i]=aux;
    }
}

void IngresoVentas(TVentas V[],int vendedores[],int ce)
{
    TVentas aux;
    int mal,pos,numvend,codigo;
    codigo=IngrDatoVal(0,9999);
    while(codigo!=999)
    {
        mal=0;
        do
        {
            pos=BuscarCliente(V,codigo,ce);
            if(pos==-1)
            {
                printf("\nERROR-CODIGO NO EXISTE.");
                printf("\nIngrese un codigo valido:\t");
                codigo=IngrDatoVal(0,9999);
            }
        }while(pos==-1);
        do
        {
            if(mal)
                printf("\nERROR-Ingrese un importe valido:\t");
            else
                printf("\nIngrese el importe de la venta:\t");
            mal=1;
            scanf("%f",& aux.importe);
        }while (aux.importe<=0);
        printf("\nIngrese el numero del vendedor- de 1 a 10:\t");
        numvend=IngrDatoVal(1,10);
        vendedores[numvend-1]++;
        aux.ventascliente=1;
        V[pos].ventascliente+=aux.ventascliente;
        V[pos].importe+=aux.importe;
        printf("\nIngrese el codigo del cliente que compro-Ingrese 999 para terminar:\t");
        codigo=IngrDatoVal(0,9999);
    }
}

void OrdenarImportes(TVentas V[],int ce,int op)
{
    int i,j;
    TVentas aux;
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(op==0)//menor a mayor
            {
                if(V[j].importe<V[j+1].importe)
                {
                    aux=V[j];
                    V[j]=V[j+1];
                    V[j+1]=aux;
                }
            }
            else
            {
                if(V[j].importe>V[j+1].importe)//mayor a menor
                {
                    aux=V[j];
                    V[j]=V[j+1];
                    V[j+1]=aux;
                }
            }
        }
    }
}