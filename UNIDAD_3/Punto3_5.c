/*Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama, identificados por su número de
patente, cargado en la memoria principal en un vector de 30 posiciones. Al comenzar el procesamiento de
los alquileres, se ingresa la fecha y la cotización del dólar de ese día. A continuación, se ingresan los
siguientes datos correspondiente a cada alquiler realizado en el día:
• Patente del auto (alfanumérico, de 6 caracteres)
• Cantidad de días de alquiler (entero, mayor que 0)
• Precio diario del alquiles en dólares (real, mayor que 0)
Para finalizar la carga del día, se ingresa una patente de auto igual a “FINDIA”
Determinar e informar:
a. El porcentaje de autos alquilados durante el día.
b. Realizar el informe con el formato siguiente:




*/

#include<stdio.h>
#include<string.h>
#define CC  7
#define FF 30

void SacarSaltoDeChar(char[]);
float Alquileres(char[][CC],char[],float[],int[],int[][3],int[],int);
void ObtenerFechaDevolucion(int[][3],int[],int,int);
void MostrarTabla(char[][CC],char[],float[],int[],int[][3],int[],float,int);

int IngresarYValidarInt(int);
float IngresarYValidarFloat(int);
float SumaVfloat(float[],int);

int BuscarCharEnChar(char[] [CC],char[],int);

int EsFechaValida(int,int,int);
int CantidadDiasDelMes(int,int);
int Bisiesto(int);


int main()
{
    char vsautos[FF][CC]={"111111","222222","333333","444444","555555","666666","777777","888888","999999",
                          "100001","100002","100003","100004","100005","100006","100007","100008","100009",
                          "200001","200002","200003","200004","200005","200006","200007","200008","200009",
                          "000000","000001","000002"
                         };
    char vspatente[CC];
    int valquilerdias[FF]={{0}};
    int vdiadevolucion[FF][3]={{0}};
    int vfecha[3];
    float vpreciodia[FF];
    float vrecaudadoxauto[FF];
    int i,cantautosalquilados=0;
    float porcentaje,dolar;
    dolar=Alquileres(vsautos,vspatente,vpreciodia,valquilerdias,vdiadevolucion,vfecha,FF);
    for(i=0;i<FF;i++)
    {
        if(valquilerdias[i]>=1)
            cantautosalquilados++;
    }
    porcentaje=(cantautosalquilados*100)/FF;
    printf("\nEl porcentaje de autos alquilados es igual al:\t %f",porcentaje);
    MostrarTabla(vsautos,vspatente,vpreciodia,valquilerdias,vdiadevolucion,vfecha,dolar,FF);
    return 0;
}


float Alquileres(char autos[][CC],char patente[],float precioxdia[],int cantidadxdias[],int fechadevolucion[][3],int fecha[],int ce)
{
    float preciodolar,precio;
    int d,m,a;
    int fvalida,pos,cantdias;
    printf("-----INGRESO FECHA ACTUAL----");
    do
    {
        printf("\nIngrese el dia:\t");
        scanf("%d",& d);
        fecha[0]=d;
        printf("\nIngrese el mes:\t");
        scanf("%d",& m);
        fecha[1]=m;
        printf("\nIngrese el anio:\t");
        scanf("%d",& a);
        fecha[2]=a;
        fvalida=EsFechaValida(d,m,a);
        if(!fvalida)
            printf("\nERROR-FECHA INVALIDA.Ingrese una fecha valida.");
    } while(!fvalida);
    printf("\nIngrese el precio del dolar:\t");
    preciodolar=IngresarYValidarFloat(1);
    fflush(stdin);
    printf("\nIngrese la patente del auto que desea buscar-Ingrese 'FINDIA' para terminar:\t");
    fgets(patente,7,stdin);   
    SacarSaltoDeChar(patente);
    while(strcmp(patente,"FINDIA")!=0)
    {
        do
        {
            pos=BuscarCharEnChar(autos,patente,ce);
            if(pos==-1)
            {
                    fflush(stdin);
                    printf("\nERROR-Patente invalida.Ingrese una patente correcta:\t");
                    fgets(patente,7,stdin);
                    SacarSaltoDeChar(patente);
            }
        }while (pos==-1);
        if(cantidadxdias[pos]==0)
        {
            printf("\nIngrese la cantidad de dias que va a ser alquilado:\t");
            cantdias=IngresarYValidarInt(1);
            cantidadxdias[pos]=cantdias;
            ObtenerFechaDevolucion(fechadevolucion,fecha,cantdias,pos);
            printf("\nIngrese el precio por dia del alquiler del auto:\t");
            precio=IngresarYValidarFloat(1);
            precioxdia[pos]=precio;
        }
        else
            printf("\nERROR-El auto ya a sido alquilado.");
        fflush(stdin);
        printf("\nIngrese la patente del auto que desea buscar-Ingrese 'FINDIA' para terminar:\t");
        fgets(patente,7,stdin);   
        SacarSaltoDeChar(patente);
    }
    return preciodolar; 
}

void ObtenerFechaDevolucion(int fechadev[][3],int fecha[],int dias,int f)
{
    int d,m,a;
    d=fecha[0];
    m=fecha[1];
    a=fecha[2];
    a+=dias;
    if(!(d>=1 && d<=CantidadDiasDelMes(m,a)))
    {
        d-=CantidadDiasDelMes(m,a);
        m++;
        if(!(m>=1 && m<=12))
        {
            m-=12;
            a++;
        }
    }
    if(EsFechaValida(d,m,a))
    {
        fechadev[f][0]=d;
        fechadev[f][1]=m;
        fechadev[f][2]=a;
    }
    else
    {
        fechadev[f][0]=-1;
        fechadev[f][1]=-1;
        fechadev[f][2]=-1;  
    }
}

void MostrarTabla(char autos[][CC],char patente[],float precioxdia[],int cantidadxdias[],int fechadevolucion[][3],int fecha[],float dolar,int ce)
{
    int i,j,k;
    float alquilerxdiapesos,recaudaciondolares,recaudacionpesos=0;
    printf("\n");
    printf("\n\t\t\tALQUILER DE AUTOS DEL DIA:");
    for(i=0;i<3;i++)
    {
        printf("%d",fecha[i]);
        if(i==0||i==1)
            printf("/");
    }
    printf("\n\t\t\t  COTIZACION DEL DOLAR: $%.2f",dolar);
    printf("\n");
    printf("NRO DE AUTO\t  ");
    printf("DIAS DE ALQUILER\t");
    printf("PRECIO DEL ALQUILER\t\tFECHA DE DEVOLUCION\n\t\t\t\t\t\tEN PESOS\t\t\tDEL AUTO");
    for(j=0;j<ce;j++)
    {
        alquilerxdiapesos=(cantidadxdias[j]*precioxdia[j])*dolar;
        recaudacionpesos+=alquilerxdiapesos;
        printf("\n%s\t\t\t     %d\t\t\t   %.2f\t\t\t  ",autos[j],cantidadxdias[j],alquilerxdiapesos);
        for(k=0;k<3;k++)
        {
            printf("%d",fechadevolucion[j][k]);
            if(k==0||k==1)
                printf("/");
        }
    }
    recaudaciondolares=recaudacionpesos/dolar;
    printf("\nTOTAL RECAUDADO X ALQUILER (EN PESOS):\t\t$ %f",recaudacionpesos);
    printf("\nTOTAL RECAUDADO X ALQUILER (EN DOLARES):\t\t$ %f",recaudaciondolares);
}

void SacarSaltoDeChar(char oracion[])
{
    int largo;
    largo=strlen(oracion);
    if(oracion[largo-1]=='\n')
        oracion[largo-1]='\0';
}

int BuscarCharEnChar(char vn[] [CC],char abuscar[],int ce)
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