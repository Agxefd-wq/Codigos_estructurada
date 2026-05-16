/*Utilizando la siguiente definición de estructura, realice un programa que solicite memoria para 5 alumnos.
struct alumno
{
 int legajo;
 char sexo;
 char nombre[31];
 float promedio;
};
El usuario ingresara por teclado los datos que se cargara en la estructura- Mostrar el nombre de los alumnos
uno debajo del otro. A continuación, mostrar el alumno con mejor promedio.*/
#include<stdio.h>
#include<stdlib.h>
#define TAM 3
typedef struct 
{
    int legajo;
    char sexo;
    char nombre[31];
    float promedio;
}sAlumno;

int esDatoValFloat (float, int, int);
float IngrDatoValFloat (int, int);
int esCharVal(char,int,int);
int BuscarLegajo(sAlumno*,int,int);
void CargarAlumnos(sAlumno*,int);
void MostrarAlumnos(sAlumno*,int);
sAlumno* MayorPromedio(sAlumno*,int);

int main()
{
    sAlumno *alumnos;
    char op;
    int mal=0;
    sAlumno *pmayorpromedio;
    do
    {
        if(mal)
            printf("\nIngrese una opcion valida:\t");
        else
            printf("\nDesea reservar memoria para 5 alumnos?-Y/N:\t");
        mal=1;
        fflush(stdin);
        scanf("%c",& op);
    } while (!esCharVal(op,'Y','N'));
    if(op=='Y')
    {
        alumnos=(sAlumno*)malloc(TAM*sizeof(sAlumno*));
        CargarAlumnos(alumnos,TAM);
        MostrarAlumnos(alumnos,TAM);
        pmayorpromedio=MayorPromedio(alumnos,TAM);
        printf("\nEl alumno con el mayor promedio es: %s",alumnos[pmayorpromedio-alumnos].nombre);
    }
    free(alumnos);
    return 0;
}

int esDatoValFloat (float num, int inf, int sup)
{
    int i;
    if (num >= inf && num <= sup)
        i = 1;
    else
        i = 0;
    return i;
}

float IngrDatoValFloat (int li, int ls)
{ 
    float num;
    int mal=0;
    do {
        if (mal)                                  //Control error para mensaje
            printf("ERROR-Ingrese un valor valido:\t");
        scanf ("%f", &num);
        mal=1;
    } while (esDatoValFloat(num, li, ls) == 0);

  return num;
}

int esCharVal(char c,int i,int j)
{
    int error;
    if(c==i||c==j)
        error=1;
    else
        error=0;
    return error;
}

int BuscarLegajo(sAlumno *v,int abuscar,int ce)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if((*(v+i)).legajo==abuscar)
            pos=i;
        else
            i++;
    }
    return pos;
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
            do
            {
                if(mal)
                    printf("\nIngrese un legajo valido:\t");
                else
                    printf("\nIngrese el legajo del %d alumno:\t",i+1);
                mal=1;
                scanf("%d",&aux.legajo);
            } while (aux.legajo<=0);
            pos=BuscarLegajo(v,aux.legajo,i);
        } while (pos!=-1);
        mal=0;
        printf("\nIngrese el nombre del alumno:\t");
        fflush(stdin);
        gets(aux.nombre);
        do 
        {
            if(mal)
                printf("\nIngrese un genero valido:\t");
            else
                printf("\nIngrese el genero del alumno-F/M:\t");
            mal=1;
            fflush(stdin);
            scanf("%c",&aux.sexo);
        }while(!esCharVal(aux.sexo,'F','M'));   
        mal=0;
        printf("\nIngrese el promedio del alumno:\t");
        aux.promedio=IngrDatoValFloat(0,10);
        *(v+i)=aux;
    }
}

void MostrarAlumnos(sAlumno *v,int ce)
{
    int i;
    printf("\n**********ALUMNOS*********");
    for(i=0;i<ce;i++)
    {
        printf("\nLEGAJO: %d  NOMBRE: %-30s  SEXO: %c",(*(v+i)).legajo,(*(v+i)).nombre,(*(v+i)).sexo);
    }
}

sAlumno* MayorPromedio(sAlumno *v,int ce)
{
    int i;
    sAlumno *pmayor=v;
    for(i=0;i<ce;i++)
    {
        if((*(v+i)).promedio>(*pmayor).promedio)
        {
            pmayor=v+i;
        }
    }
    return pmayor;
}