/* Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.
*/

#include<stdio.h>
#include<string.h>
#define TAM 50

void SacarSaltoDeChar(char[]);

void MostrarVec(int[], int);
void MostrarChar(char[][31],int);
int CargarAlumnos(char[] [31],char[],int[],int);
void BuscarAlumnos(char[][31],char[],int[],int);
void CargarDNIAlumnos(int[],int,int);
int IngresarYValidarIntRango(int,int);
int BuscarInt(int[],int,int);
int BuscarCharEnChar(char[] [31],char[],int);
void Ordenar(char[][31],int,int);

int main()
{
    int alumnoscargados;
    char nombresalumnos [TAM] [31];
    char alumnobuscar[31];
    int dnialumnos[TAM];
    alumnoscargados=CargarAlumnos(nombresalumnos,alumnobuscar,dnialumnos,TAM);
    MostrarChar(nombresalumnos,alumnoscargados);
    MostrarVec(dnialumnos,alumnoscargados);
    BuscarAlumnos(nombresalumnos,alumnobuscar,dnialumnos,alumnoscargados);
    Ordenar(nombresalumnos,alumnoscargados,0);
    printf("\nLos alumnos en orden alfabetico de menor a mayor es:");
    MostrarChar(nombresalumnos,alumnoscargados);
    return 0;
}

int CargarAlumnos(char lista_alumno[] [31],char alumno[],int dni[],int ca)
{
    int i=0,pos;
    printf("\nIngrese el nombre del alumno Numero %d-Ingrese 'FIN' para terminar:\t",i+1);
    fgets(alumno,31,stdin);
    SacarSaltoDeChar(alumno);
    while(strcmpi(alumno,"FIN")!=0 && i<ca)
    {
        do
        {
            pos=BuscarCharEnChar(lista_alumno,alumno,ca);
            if(pos!=-1)
            {
                printf("\nERROR-Alumno ya existente.Ingrese un nombre valido:\t");
                fgets(alumno,31,stdin);
                SacarSaltoDeChar(alumno);
            }
        }while(pos!=-1);
        strcpy(lista_alumno[i],alumno);
        CargarDNIAlumnos(dni,i,ca);
        //while(getchar() != '\n');//LINEA DE CODIGO QUE ME DIO LA IA
        fflush(stdin);
        i++;
        printf("\nIngrese el nombre del alumno Numero %d-Ingrese 'FIN' para terminar:\t",i+1);
        fgets(alumno,31,stdin);
        SacarSaltoDeChar(alumno);
    }
    return i;
}

void CargarDNIAlumnos(int dni[],int f,int ce)
{
    int num,pos;
    printf("\nIngrese el dni del alumno:\t");
    do
    {
        num=IngresarYValidarIntRango(10000000,99999999);
        pos=BuscarInt(dni,num,ce);
        if(pos!=-1)
            printf("\nERROR-El DNI ya existe.Ingrese otro DNI valido:\t");
    } while(pos!=-1);
    dni[f]=num;
}

void BuscarAlumnos(char lista_alumno[] [31],char alumno[],int dni[],int ca)
{
    int pos;
    printf("\nIngrese el nombre del alumno que desea buscar-Ingrese 'NOBUSCARMAS' para terminar:\t");
    fgets(alumno,31,stdin);
    SacarSaltoDeChar(alumno);
    while(strcmpi(alumno,"NOBUSCARMAS")!=0)
    {
        do
        {
            pos=BuscarCharEnChar(lista_alumno,alumno,ca);
            if(pos==-1)
            {
                printf("\nERROR-Alumno no existente.Ingrese un nombre valido:\t");
                fgets(alumno,31,stdin);
                SacarSaltoDeChar(alumno);
            }
        }while(pos==-1);
        printf("\nEl DNI del alumno es:\t%d",dni[pos]);
        printf("\nIngrese el nombre del alumno que desea buscar-Ingrese 'NOBUSCARMAS' para terminar:\t");
        fgets(alumno,31,stdin);
        SacarSaltoDeChar(alumno);
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

int BuscarInt(int vec[],int dato,int ce)
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

int BuscarCharEnChar(char vn[] [31],char abuscar[],int ce)
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

void MostrarVec(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        printf("\n%d",v[i]);
}

void MostrarChar(char vn[] [31],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        puts(vn[i]);
}

void SacarSaltoDeChar(char oracion[])
{
    int largo;
    largo=strlen(oracion);
    if(oracion[largo-1]=='\n')
        oracion[largo-1]='\0';
}

void Ordenar(char vn[][31],int ce,int op)
{
    int i,j;
    char aux[31];
    for (i=0;i<ce-1;i++)
    {
        for (j=0;j<ce-1-i;j++)
        {
            if(op==0)//menor
            {
                if (strcmpi(vn[j],vn[j+1]) > 0) 
                {
                    strcpy(aux, vn[j]);
                    strcpy(vn[j],vn[j+1]);
                    strcpy(vn[j+1], aux);
                }
            }
            if(op==1)//mayor
            {
                if (strcmpi(vn[j],vn[j+1]) < 0) 
                {
                    strcpy(aux, vn[j]);
                    strcpy(vn[j],vn[j+1]);
                    strcpy(vn[j+1], aux);
                }
            }
        }
    }
}