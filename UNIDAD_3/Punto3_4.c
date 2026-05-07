/*Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad exacta
de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y la carga de
los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del día y por cada
venta se ingresa el código de producto y cantidad de unidades vendidas terminando con una cantidad igual
a 0. Se solicita:
a. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
b. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.*/
#include<stdio.h>
#include<string.h>
#define COD 50
#define LIM 4

void SacarSaltoDeChar(char[]);
int CargarCodigos(char[][LIM],char[],float[],int,int);
int VerificarLongChar(char[],int);
void CargarProductos(char[][LIM],char[],int[]);
void ProductoVfloatVint(float[],float[],int[],int);
float SumaVfloat(float[],int);
int IngresarYValidarInt(int);
float IngresarYValidarFloat(int);
int BuscarCharEnChar(char[] [LIM],char[],int);
void MostrarChar(char[][LIM],float[],int);
float Minimo(float[],int);
int Buscar(float[],float,int);
void Ordenar(char[][LIM],float[],int);

int main()
{
    char codigos[COD][LIM];
    char codigoproducto[LIM];
    int cantidadvendidas[COD]={{0}};
    float precioproducto[COD],recaudado[COD];
    int tcodigo;
    float min;
    tcodigo=CargarCodigos(codigos,codigoproducto,precioproducto,LIM,COD);
    CargarProductos(codigos,codigoproducto,cantidadvendidas);
    ProductoVfloatVint(recaudado,precioproducto,cantidadvendidas,tcodigo);
    min=Minimo(recaudado,tcodigo);
    printf("\nLa recaudacion total fue:\t%.2f",SumaVfloat(recaudado,tcodigo));
    printf("\nEl producto con menor recaudacion es:\t%s",codigos[Buscar(recaudado,min,tcodigo)]);
    Ordenar(codigos,precioproducto,tcodigo);
    MostrarChar(codigos,precioproducto,tcodigo);
    return 0;
}

int CargarCodigos(char listacodigos[][LIM],char codigo[],float precio[],int cc,int ce)
{
    int pos,cadenavalida,i=0;
    float pr;
    printf("\nIngrese el codigo alfanumerico de 3 caracteres del %d codigo-Ingrese 'FIN' para terminar:\t",i+1);
    fgets(codigo,cc,stdin);
    SacarSaltoDeChar(codigo);
    while(strcmp(codigo,"FIN")!=0 && i<ce)
    {
        do
        {  
            do
            {
                cadenavalida=VerificarLongChar(codigo,3);
                if(!cadenavalida)
                {
                    fflush(stdin);
                    printf("\nERROR-Codigo invalido.Ingrese un codigo de 3 caracteres:\t");
                    fgets(codigo,cc,stdin);
                    SacarSaltoDeChar(codigo);
                }
            }while(!cadenavalida);
            pos=BuscarCharEnChar(listacodigos,codigo,ce);
            if(pos!=-1)
            {
                fflush(stdin);  
                printf("\nERROR-Codigo ya existe.Ingrese un codigo valido:\t");
                fgets(codigo,cc,stdin);
                SacarSaltoDeChar(codigo);
            }
        }while(pos!=-1);
        strcpy(listacodigos[i],codigo);
        fflush(stdin);
        printf("\nIngrese el precio del producto:\t");
        pr=IngresarYValidarFloat(1);
        precio[i]=pr;
        i++;
        fflush(stdin);
        printf("\nIngrese el codigo alfanumerico del %d codigo-Ingrese 'FIN' para terminar:\t",i+1);
        fgets(codigo,cc,stdin);
        SacarSaltoDeChar(codigo);
    }
    return i;
}

int VerificarLongChar(char vn[],int lim)
{
    int largo,cf;
    largo=strlen(vn);
    printf("\n%d",largo);
    if(largo==lim)
        cf=1;
    else
        cf=0;
    return cf;
}

void CargarProductos(char listacodigos[][LIM],char codigo[],int cantidad[])
{
    int pos,cant;
    printf("\nIngrese la cantidad que se vendio del producto-Ingrese 0 para terminar:\t");
    cant=IngresarYValidarInt(0);
    while(cant!=0)
    {   
        fflush(stdin);
        printf("\nIngrese el codigo del producto:\t");
        fgets(codigo,4,stdin);
        SacarSaltoDeChar(codigo);
        do
        {
            pos=BuscarCharEnChar(listacodigos,codigo,4);
            if(pos==-1)
            {
                fflush(stdin);  
                printf("\nERROR-Codigo inexistente.Ingrese un codigo valido:\t");
                fgets(codigo,4,stdin);
                SacarSaltoDeChar(codigo);
            }
        }while(pos==-1);
        cantidad[pos]+=cant;
        printf("\nIngrese la cantidad que se vendio del producto-Ingrese 0 para terminar:");
        cant=IngresarYValidarInt(0);
    }
}

void SacarSaltoDeChar(char oracion[])
{
    int largo;
    largo=strlen(oracion);
    if(oracion[largo-1]=='\n')
        oracion[largo-1]='\0';
}

int BuscarCharEnChar(char vn[] [LIM],char abuscar[],int ce)
{
    int i=0,pos=-1;
    while(pos==-1 && i<ce)
    {
        if(strcmpi(vn[i],abuscar)==0)
            pos=i;
        else
            i++;
    }
    return pos;
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

void ProductoVfloatVint(float vr[],float vf[],int vi[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        vr[i]=vf[i]*vi[i];
    }
}

float Minimo(float v[],int ce)
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

int Buscar(float vec[],float dato,int ce)
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

float SumaVfloat(float v[],int ce)
{
    int i;
    float total=0;
    for(i=0;i<ce;i++)
    {
        total+=v[i];
    }
    return total;
}
void Ordenar(char vn[][LIM],float vf[],int ce)
{
    int i,j;
    char aux[LIM];
    float faux;
    for (i=0;i<ce-1;i++)
    {
        for (j=0;j<ce-1-i;j++)
        {
            if (strcmpi(vn[j],vn[j+1]) > 0) 
            {
                strcpy(aux, vn[j]);
                strcpy(vn[j],vn[j+1]);
                strcpy(vn[j+1], aux);

                faux=vf[j];
                vf[j]=vf[j+1];
                vf[j+1]=faux;
            }
        }
    }
}


void MostrarChar(char vn[] [LIM],float precio[],int ce)
{
    int i;
    printf("\nCODIGO:         PRECIO:");
    for(i=0;i<ce;i++)
        printf("\n%s\t%.2f",vn[i],precio[i]);
}
