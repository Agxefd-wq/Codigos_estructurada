/*Se desea hacer un estudio de los alumnos de la Universidad que están cursando
el 4to. año de la carrera de Ingeniería (como máximo hay 5000 alumnos).
Para ello, de cada alumno se ingresan los siguientes datos:
        DNI (entero, entre 1 y 99.999.999)
        Apellido y Nombre (string, de 30 caracteres)
        Domicilio (string, de 30 caracteres)
        Sexo (carácter, ‘F’ o ‘M’)
        Fecha de Nacimiento (enteros, día, mes y año)
        Cantidad de materias aprobadas (entero, mayor o igual a cero)
        Promedio de notas de las materias aprobadas (real, mayor a cero)
La información finaliza con un DNI igual a cero.

Informar:
Los datos de los alumnos ordenados descendente por promedio.*/
#include<stdio.h>
#include<string.h>

#define TAM 5


typedef struct 
{
    int dia;
    int mes;
    int anio;
}fecha;

typedef struct 
{
    int dni;
    int aprobadas;
    float promedio;
    char nombreapell[31];
    char dirreccion[31];
    char sexo[2];
    fecha nacimiento;
}Alumno;

int IngresarYValidarInt(int);
float IngresarYValidarFloat(int);
int IngresarYValidarIntRango(int,int);


int EsFechaValida(int,int,int);
int CantidadDiasDelMes(int,int);
int Bisiesto(int);

void Ordenar(Alumno[],int);
void Mostrar(Alumno[],int);

int main()
{
    Alumno valumno[TAM];
    int i=0;
    int dni;
    int aprobadas;
    float promedio;
    char genero[2];
    printf("\nIngrese el DNI del alumno-Entre 1 y 99.999.999-Ingrese 0 para terminar:\t");
    dni=IngresarYValidarIntRango(-1,10000000);
    while(dni!=0 && i<TAM)
    {
        valumno[i].dni=dni;
        printf("\nIngrese el apellido y nombre del alumno:\t");
        fflush(stdin);
        gets(valumno[i].nombreapell);
        printf("\nIngrese el domicilio:\t");
        fflush(stdin);
        gets(valumno[i].dirreccion);
        printf("\nIngrese el genero 'F' o 'M':\t");
        do
        {
            fflush(stdin);
            gets(genero);
            if(strcmp(genero,"F")!=0 && strcmp(genero,"M")!=0)
                printf("\nERROR-Ingrese un genero correcto:\t");
        } while (strcmp(genero,"F")!=0 && strcmp(genero,"M")!=0);
        strcpy(valumno[i].sexo,genero);
        printf("\nIngrese la fecha de nacimiento");
        do
        {
            printf("\nIngrese el dia:\t");
            scanf("%d",& valumno[i].nacimiento.dia);
            printf("\nIngrese el mes:\t");
            scanf("%d",& valumno[i].nacimiento.mes);
            printf("\nIngrese el anio:\t");
            scanf("%d",& valumno[i].nacimiento.anio);
            if(!EsFechaValida(valumno[i].nacimiento.dia,valumno[i].nacimiento.mes,valumno[i].nacimiento.anio))
                printf("\nERROR-Fecha Invalida.Ingrese una fecha valida");
        }while(!EsFechaValida(valumno[i].nacimiento.dia,valumno[i].nacimiento.mes,valumno[i].nacimiento.anio));
        printf("\nIngrese la cantidad de materias aprobadas:\t");
        aprobadas=IngresarYValidarInt(-1);
        valumno[i].aprobadas=aprobadas;
        printf("\nIngrese el promedio de la notas de las materias aprobadas:\t");
        promedio=IngresarYValidarFloat(-1);
        valumno[i].promedio=promedio;
        i++;
        printf("\nIngrese el DNI del alumno-Entre 1 y 99.999.999-Ingrese 0 para terminar:\t");
        dni=IngresarYValidarIntRango(-1,10000000);
    }
    Mostrar(valumno,i);
    return 0;
}

void Mostrar(Alumno vp[],int ce)
{
    int i;
    printf("\n%5s  %30s  %-30s %3s %8s %8s %10s","DNI","NOMBRE COMPLETO","DIRECCION","SEXO","APROVADAS","PROMEDIO","FECHA DE NACIMIENTO");
    for(i=0;i<ce;i++)
    {
        printf("\n%2d  %30s %-30s %3s  %8d  %.2f %02d/%02d/%d",vp[i].dni,vp[i].nombreapell,vp[i].dirreccion,vp[i].sexo,vp[i].aprobadas,vp[i].promedio,vp[i].nacimiento.dia,vp[i].nacimiento.mes,vp[i].nacimiento.anio);
    }
}

void Ordenar(Alumno vp[],int ce)
{
    int i,j;
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(vp[j].promedio)
        }
    }

}

int IngresarYValidarInt(int li)
{
    int num;
    do
    {
        scanf("%d",& num);
        if(num<li)
            printf("\nERROR-Ingrese un valor mayor a %d:\t",li-1);
    } while (num<li);
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