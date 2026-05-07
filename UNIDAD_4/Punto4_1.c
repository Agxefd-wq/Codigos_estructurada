/*Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION CANTIDAD UNIDADES
VENDIDAS
IMPORTE TOTAL
VENDIDO
XXXXXXX XXXX $XXXXX,XX
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define TAM 5
typedef struct 
{
    char codigo[6];
    char descrip[31];
    int cantvend;
    float precio;
    float imprtotal;
}TCatalogo;

int CargarCatalogo(TCatalogo[],int);
void Ventas(TCatalogo[],int);
int BuscarCharStruct(TCatalogo[],char[],int);
void SacarSaltoDeChar(char[]);

int main()
{
    TCatalogo Vcat[TAM];
    int product,i;
    printf("\nIngrese el codigo del producto-Ingrese 'FIN' para terminar:\t");
    product=CargarCatalogo(Vcat,TAM);
    printf("\nIngrese la cantidad vendidad del producto en este mes- 0 para terminar:\t");
    Ventas(Vcat,product);
    printf("\n%2s\t%s %s\t%s %s","DESCRIPCION", "CANTIDAD", "UNIDADES","IMPORTE", "TOTAL");
    printf("\n\t\t   %5s\t%5s","VENDIDAS","VENDIDO");
    for(i=0;i<product;i++)
    {
        printf("\n%-30s\t  %d\t  %.2f",Vcat[i].descrip,Vcat[i].cantvend,Vcat[i].imprtotal);
    }   
    return 0;
}


void SacarSaltoDeChar(char oracion[])
{
    int largo;
    largo=strlen(oracion);
    if(oracion[largo-1]=='\n')
        oracion[largo-1]='\0';
}

int BuscarCharStruct(TCatalogo V[],char abuscar[],int ce)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if(strcmpi(V[i].codigo,abuscar)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}

int CargarCatalogo(TCatalogo V[],int ce)
{
    TCatalogo aux;
    int i=0,mal=0,pos;
    
    do{
        if(mal)
            printf("\nERROR-Ingrese un codigo valido o la condicion de fin:\t");
        mal=1;
        fflush(stdin);
        fgets(aux.codigo,6,stdin);
        SacarSaltoDeChar(aux.codigo);
    }while(strlen(aux.codigo)!=5 && strcmpi(aux.codigo,"FIN")!=0);
    while(i<ce && strcmpi(aux.codigo,"FIN")!=0)
    {
        mal=0;
        do
        {
            if(mal)
                printf("\nERROR-Ingrese un valor correcto:\t");
            else
                printf("\nIngrese el precio del producto:\t");
            mal=1;
            scanf("%f",& aux.precio);
        } while(aux.precio<=0);
        mal=0;
        fflush(stdin);
        printf("\nIngrese la descripcion del producto:\t");
        fgets(aux.descrip,31,stdin);
        SacarSaltoDeChar(aux.descrip);
        do
        {
            if(mal)
                printf("\nERROR-ingrese una cantidad correcta:\t");
            else
                printf("\nIngrese la cantidad vendida el mes anterior:\t");
            mal=1;
            scanf("%d",& aux.cantvend);
        } while(aux.cantvend<0);
        mal=0;
        do
        {
            if(mal)
                printf("\nERROR-Ingrese un importe correcto:\t");
            else
                printf("\nIngrese el importe total del mes pasado:\t");
            mal=1;
            scanf("%f",&aux.imprtotal);
        } while (aux.imprtotal<=0);
        mal=0;
        V[i]=aux;
        i++;
        do
        {
            do{
                if(mal)
                    printf("\nIngrese un codigo valido o la condicion de fin:\t");
                else
                    printf("\nIngrese el codigo del producto-Ingrese 'FIN' para terminar:\t");
                mal=1;
                fflush(stdin);
                fgets(aux.codigo,6,stdin);
                SacarSaltoDeChar(aux.codigo);
            }while(strlen(aux.codigo)!=5 && strcmpi(aux.codigo,"FIN"));
            pos=BuscarCharStruct(V,aux.codigo,ce);
            if(pos!=-1)
                printf("\nERROR.Codigo Repetido.");
        }while(pos!=-1);
    }
    return i;
}

void Ventas(TCatalogo V[],int ce)
{
    char codigo[6];
    int cant,pos,mal=0;
    do
    {
        if(mal)
            printf("\nERROR-Ingrese una cantidad valida:");
        mal=1;
        scanf("%d",& cant);
    } while (cant<0);
    while(cant!=0)
    {
        mal=0;
        do
        {
            if(mal)
                printf("\nERROR-Ingrese un codigo valido:\t");
            else
                printf("\nIngrese el codigo del producto:\t");
            mal=1;
            fflush(stdin);
            fgets(codigo,6,stdin);
            SacarSaltoDeChar(codigo);
            pos=BuscarCharStruct(V,codigo,ce);
        } while (pos==-1 || strlen(codigo)!=5);
        V[pos].cantvend+=cant;        
        V[pos].imprtotal+=V[pos].precio*cant;
        printf("\nIngrese la cantidad vendidad del producto en este mes- 0 para terminar:\t");
        mal=0; 
        do
        {
            if(mal)
                printf("\nERROR-Ingrese una cantidad valida:");
            mal=1;
            scanf("%d",& cant);
        } while (cant<0); 
    }
}