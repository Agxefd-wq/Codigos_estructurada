/*Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
a. Declarar un tipo de dato que contenga la información del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.
d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.
e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.*/

#include<stdio.h>
#define TAM 5

typedef struct 
{
    int dni;
    int nt1;
    int nt2;
    char apellynombr[81];
    float ntprom;
}TComision;

int INGRESO(TComision[],int);
void RESULTADO(TComision[],int);
void INFORME_PROMO(TComision[],int);
int BusquedaIntStruct(TComision[],int,int);
int esDatoVal (int, int, int);
int IngrDatoVal (int, int);

int main()
{
    TComision Valumno[TAM];
    int alumnos;
    alumnos=INGRESO(Valumno,TAM);
    printf("\nEsta es la cantidad de alumnos aprobados y desaprovados");
    RESULTADO(Valumno,alumnos);
    INFORME_PROMO(Valumno,alumnos);
    return 0;
}

int BuscarIntStruct(TComision V[],int abuscar,int ce)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if(V[i].dni==abuscar)
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

int INGRESO(TComision V[],int ce)
{
    TComision aux;
    int pos,i=0;
    printf("\nIngrese el DNI del %d alumno:\t",i+1);
    aux.dni=IngrDatoVal(0,99999999);
    while(aux.dni!=0 && i<ce)
    {
        printf("\nIngrese el apellido y nombre del alumno:\t");
        fflush(stdin);
        gets(aux.apellynombr);
        printf("\nIngrese la nota 1:\t");
        aux.nt1=IngrDatoVal(1,10);
        printf("\nIngrese la nota 2:\t");
        aux.nt2=IngrDatoVal(1,10);
        aux.ntprom=(aux.nt1+aux.nt2)/2;
        V[i]=aux;
        i++;
        do
        {
            printf("\nIngrese el DNI del %d alumno:\t",i+1);
            aux.dni=IngrDatoVal(0,99999999);
            pos=BuscarIntStruct(V,aux.dni,ce);
            if(pos!=-1)
                printf("\nERROR-DNI ya existe.Ingrese uno valido.");
        } while (pos!=-1);
    }
    return i;
}

void RESULTADO(TComision V[],int ce)
{
    int i=0,j;
    for(j=0;j<ce;j++)
    {
        if(V[j].nt1>=4 && V[j].nt2>=4)
            i++;
    }
    printf("\nAlumnos aprobados: %d",i);
    printf("\nAlumnos desaporbados: %d",ce-i);
}

/*e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.*/
void INFORME_PROMO(TComision V[],int ce)
{
    int i;
    printf("\n%8s %-40s %-4s","DNI","APELLIDO Y NOMBRE","NOTA PROMEDIO");
    for(i=0;i<ce;i++)
    {
        if(V[i].ntprom>=7)
            printf("\n%8d%-40s\t%.2f",V[i].dni,V[i].apellynombr,V[i].ntprom);
    }
}