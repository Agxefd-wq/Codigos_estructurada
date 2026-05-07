/*Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado
de mayor a menor por nota. */

#include<stdio.h>
#define TAM 60

int IngresoDNINotaAlumno(int[],float[],int);
float IngresarYValidarFloatRango(int,int);
int IngresarYValidarIntRangoExcepcion(int,int,int);
int Buscar(int[],int,int);
void OrdenarBurbujeoDosVec(float[],int[],int);

int main()
{
    int cont,i;
    int vdocumentos[TAM];
    float vnota[TAM];
    cont=IngresoDNINotaAlumno(vdocumentos,vnota,TAM);
    OrdenarBurbujeoDosVec(vnota,vdocumentos,cont);
    printf("\nLISTADO DE ALUMNOS\nDNI:\t\tNOTA:");
    for(i=0;i<cont;i++)
    {
        printf("\n%d\t%f",vdocumentos[i],vnota[i]);
    }
    return 0;

}

int IngresoDNINotaAlumno(int v1[],float v2[],int ce)
{
    int i=0,pos,dni;
    printf("Porfavor ingrese el dni del alumno numero %d:\t",i+1);
    dni=IngresarYValidarIntRangoExcepcion(0,10000000,99999999);
    while(dni > 0 && i<ce)
    {
        v1[i]=dni;
        printf("\nIngrese la nota del alumno:\t");
        v2[i]=IngresarYValidarFloatRango(0,10);
        i++;
        printf("Porfavor ingrese el dni del alumno numero %d:\t",i+1);
        do
        {
            dni=IngresarYValidarIntRangoExcepcion(0,10000000,99999999);
            pos=Buscar(v1,dni,i);
            if(pos!=-1)
                printf("\nERROR-DATO DUPLICADO.Ingrese un dni valido:\t");
        }while(pos!=-1);
    }
    return i;

}

float IngresarYValidarFloatRango(int li, int ls)
{
    float num;
    do
    {
        scanf("%f",&num);
        if(num < li || num > ls)
            printf("\nERROR-Ingrese un valor valido entre %d y %d:\t",li-1,ls+1);
    }while(num < li || num > ls);
    return num;
}

int IngresarYValidarIntRangoExcepcion(int exc, int li, int ls)
{
    int num;
    do
    {
        scanf("%d",&num);
        if(num!=exc && (num < li || num > ls))
            printf("\nERROR-Ingrese un valor valido:\t");
    }while(num!=exc && (num < li || num > ls));
    return num;
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

void OrdenarBurbujeoDosVec(float v1[],int v2[],int ce)
{
    int i,j,aux;
    float aux_float;
    for(i=0;i<ce-1;i++)
    {
        for (j = 0; j < ce-1; j++)
        {
            if(v1[j]<v1[j+1])
            {
                aux_float=v1[j];
                v1[j]=v1[j+1];
                v1[j+1]=aux_float;

                aux=v2[j];
                v2[j]=v2[j+1];
                v2[j+1]=aux;
            }
        }  
    }
}