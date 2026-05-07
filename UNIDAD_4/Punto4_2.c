/*Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).
Se solicita:
a. Declarar un tipo de dato que contenga la información del medicamento.
b. Declarar un vector de estructura de tipo de datos creado en a.
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.
*/
#include<stdio.h>
#include<string.h>
#define TAM 5
typedef struct 
{
    char codigo[4];
    float precio;
    int stock;
}TLaboratorio;

void INGRESO(TLaboratorio[],int);
void BUSQUEDA_MEDI(TLaboratorio[],int);
void INFORME(TLaboratorio[],int);
int BuscarCharStruct(TLaboratorio[],char[],int);
void SacarSaltoDeChar(char[]);

int main()
{
    TLaboratorio Vmedicamento[TAM];
    INGRESO(Vmedicamento,TAM);
    BUSQUEDA_MEDI(Vmedicamento,TAM);
    printf("\nLos medicamentos que tienen menos de 10 de stock son:");
    INFORME(Vmedicamento,TAM);
    return 0;
}

void SacarSaltoDeChar(char oracion[])
{
    int largo;
    largo=strlen(oracion);
    if(oracion[largo-1]=='\n')
        oracion[largo-1]='\0';
}


int BuscarCharStruct(TLaboratorio V[],char abuscar[],int ce)
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

void INGRESO(TLaboratorio V[],int ce)
{
    TLaboratorio aux;
    int i,mal,pos;
    for(i=0;i<ce;i++)
    {
        mal=0;
        do
        {
            do
            {
                if(mal)
                    printf("\nERROR-Ingrese un codigo valido:\t");
                else 
                    printf("\nIngrese el codigo del %d medicamento:\t",i+1);
                mal=1;
                fflush(stdin);
                fgets(aux.codigo,4,stdin);
                SacarSaltoDeChar(aux.codigo);
            }while(strlen(aux.codigo)!=3);
            mal=0;
            pos=BuscarCharStruct(V,aux.codigo,ce);
            if(pos!=-1)
                printf("\nERROR-Codigo ya existente");
        } while(pos!=-1);
        mal=0;
        do
        {
            if(mal)
                printf("\nERROR-Ingrese un precio valido:\t");
            else
                printf("\nIngrese el precio del medicamento:\t");
            mal=1;
            scanf("%f",& aux.precio);
        } while (aux.precio<=0);
        mal=0;
        do
        {
            if(mal)
                printf("\nERROR-Ingrese un stock valido");
            else
                printf("\nIngrese el stock del medicamento:\t");
            mal=1;
            scanf("%d",&aux.stock);
        } while (aux.stock<0);
        strcpy(V[i].codigo,aux.codigo);
        V[i].precio=aux.precio;
        V[i].stock=aux.stock;
    }
}

void BUSQUEDA_MEDI(TLaboratorio V[],int ce)
{
    int pos;
    char aux[4];
    printf("\nIngrese el codigo del medicamento que quiere consultar:\t");
    fflush(stdin);
    fgets(aux,4,stdin);
    SacarSaltoDeChar(aux);
    pos=BuscarCharStruct(V,aux,ce);
    if(pos==-1)
        printf("\nEl codigo del medicamento no existe");
    else
        printf("\nEl precio del medicamento es:\t%.2f",V[pos].precio);
}

void INFORME(TLaboratorio V[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        if(V[i].stock<10)
            printf("\nMEDICAMENTO: %s",V[i].codigo);
    }
}