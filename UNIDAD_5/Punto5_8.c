/* Dada la estructura alumno:
struct alumno
{
char nom[31];
int dni;
};
Realizar un programa que permita cargar alumnos y mostrarlos. Como máximo permitir 50 alumnos. El ingreso
finaliza con un DNI igual a 0. Realizar una función para cargar y otra para mostrar usando notación de punteros.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char nom[31];
    int dni;
}sAlumno;

int esDatoVal (int, int, int);
int IngrDatoVal (int, int);     
void CargarAlumnos(sAlumno*,int);
void MostrarAlumnos(sAlumno*,int);
int BuscarDni(sAlumno*,int,int);
int main()
{
    sAlumno *alumnos;
    int cantalum;
    printf("\nIngrese la cantidad de alumnos-Maximo 50:\t");
    cantalum=IngrDatoVal(1,50);
    alumnos=(sAlumno*)malloc(cantalum*sizeof(sAlumno*));
    if(alumnos==NULL)
    {
        printf("\nERROR EN LA RESERVA DE MEMORIA.");
        exit(1);
    }
    CargarAlumnos(alumnos,cantalum);
    MostrarAlumnos(alumnos,cantalum);
    free(alumnos);
    return 0;
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

void CargarAlumnos(sAlumno *v,int ce)
{
    sAlumno aux;
    int i;
    int mal=0,pos;
    for(i=0;i<ce;i++)
    {
        do
        {
            if(mal)
                printf("\nIngrese un dni valido:\t");
            else
                printf("\nIngrese el dni del %d alumno:\t",i+1);
            aux.dni=IngrDatoVal(10000000,99999999);
            mal=1;
            pos=BuscarDni(v,aux.dni,i);
        } while(pos!=-1);
        mal=0;
        printf("\nIngrese el nombre del alumno:\t");
        fflush(stdin);
        gets(aux.nom);
        *(v+i)=aux;
    }
}

void MostrarAlumnos(sAlumno *v,int ce)
{
    int i;
    printf("\n**********ALUMNOS*********");
    for(i=0;i<ce;i++)
    {
        printf("\nDNI: %8d  NOMBRE: %s",(*(v+i)).dni,(*(v+i)).nom);
    }
}
int BuscarDni(sAlumno *v,int abuscar,int ce)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if((*(v+i)).dni==abuscar)
            pos=i;
        else
            i++;
    }
    return pos;
}