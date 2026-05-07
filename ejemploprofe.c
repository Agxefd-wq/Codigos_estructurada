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

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define TOPE 5   ///5000

typedef struct {int dia;
                int mes;
                int anio;
                }TFecha;


typedef struct {int DNI;
                char ApyNom[31];
                char Dom[31];
                char sex;
                TFecha FNac;
                int cma;
                float prom;
                }TAlumno;


int esDatoVal (int, int, int);
int IngrDatoVal (int, int);
int esDatoValCh (char, char, char);
int esBisiesto (int);
int CantDiasMes (int, int);
int esFechaValida (int, int, int);
TFecha IngrFechaVal ();
int CargaVec (TAlumno[], int);
void Ordenar (TAlumno[], int);
void MostrarVec (TAlumno[], int);


int main ()
{
 TAlumno VAlum[TOPE];

 int cant;

 printf("\nIngresar datos de alumnos - DNI igual a cero para terminar...");
 cant = CargaVec(VAlum, TOPE);
 Ordenar (VAlum, cant);
 printf("\nDNI      Apellido y Nombre              Domicilio                      Sexo Fecha Nac. Cant.Mat.Aprob. Promedio");
 MostrarVec (VAlum, cant);
 return 0;
}

///////////////////////////FUNCIONES//////////////////////////////////////////////////////////////
int esDatoVal (int x, int inf, int sup)
{
    int dato;
    if (x >= inf && x <= sup)
        dato = 1;
    else
        dato = 0;
    return dato;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
int IngrDatoVal (int li, int ls)
{ int dato, error=0;

  do {
        if (error)                                  //Control error para mensaje
            printf("Dato erroneo, nuevo ingreso: ");
        scanf ("%d", &dato);
        error=1;
     } while (esDatoVal (dato, li, ls) == 0);

  return dato;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
int esDatoValCh (char dato, char x, char y)
{
    int bien;
    if (dato == x || dato == y)
        bien = 1;
    else
        bien = 0;
    return bien;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
TFecha IngrFechaVal ()
{
 TFecha f;
 int error=0; //Para controlar mensajes
 do{
    if (error)
        printf("\nFecha erronea");
    error=1;
    printf("\nDia: ");
    scanf("%d", &f.dia);
    printf("\nMes: ");
    scanf("%d", &f.mes);
    printf("\nAnio: ");
    scanf("%d", &f.anio);
   }while (!esFechaValida(f.dia, f.mes, f.anio));

 return f;

}

/////////////////////////////////////////////////////////////////////////////////////////////////
int esFechaValida (int d, int m, int a)
{
 int dv = 0;
 if (a > 1900)
    if (m >= 1 && m <= 12)
        if (d >= 1 && d <= CantDiasMes(m, a))
            dv = 1;

 return dv;
}

////////////////////////////////////////////////////////////////////////////////////////////////
int CantDiasMes(int m, int a)
{
 int cd;

 cd = 31;
 if (m == 4 || m == 6 || m == 9 || m == 11)
    cd = 30;
 else
    if (m == 2)
        cd = 28 + esBisiesto(a);

 return cd;
}

///////////////////////////////////////////////////////////////////////////////////////////////
int esBisiesto(int a)
{
 if ((a%4==0 && a%100!=0) || a%400==0)
    return 1;
 else
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
int CargaVec (TAlumno V[], int ce)
{
 TAlumno aux;
 int i = 0, j, mal;

 printf("\nIngrese DNI: ");
 aux.DNI = IngrDatoVal(0, 99999999); //No contempla carga sin duplicados

 while (aux.DNI != 0 && i < ce)
 {
     mal=0;             //Para control error que produce mensaje en todos los ingresos dentro de la función
     printf("\nIngrese Apellido y Nombre: ");
     fflush (stdin);
     fgets(aux.ApyNom, 31, stdin);

    //Quita enter del fgets o en listado salta linea. Podría ser una función genérica.
     aux.ApyNom[strlen(aux.ApyNom)-1]='\0';

     printf("\nIngrese Domicilio: ");
     fflush (stdin);
     fgets(aux.Dom, 31, stdin);
     aux.Dom[strlen(aux.Dom)-1]='\0';
     do{
        if (mal)
            printf("\nIngreso erroneo, reintentar: ");
        else
            printf("\nIngrese sexo (F o M): ");
        mal=1;
        fflush (stdin);
        scanf("%c", &aux.sex);
        aux.sex = toupper(aux.sex);
        }while (!esDatoValCh(aux.sex, 'F', 'M'));

     mal=0;

     printf("\nIngrese Fecha de Nacimiento");
     aux.FNac=IngrFechaVal();

     do{
        if (mal)
            printf("\nIngreso erroneo, reintentar: ");
        else
            printf("\nIngrese Cantidad de Materias Aprobadas: ");
        mal=1;

        scanf("%d", &aux.cma);
        }while (aux.cma < 0);
     mal=0;

     do{
        if (mal)
            printf("\nIngreso erroneo, reintentar: ");
        else
            printf("\nIngrese Promedio de Materias Aprobadas: ");
        mal=1;

        scanf("%f", &aux.prom);
        }while (aux.prom <= 0);

     V[i] = aux;    //Asignación de la variable aux al vector en la posición i
     i++;

     printf("\nIngrese DNI: ");
     aux.DNI = IngrDatoVal(0, 99999999);
    }
 return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Ordenar(TAlumno V[], int ce)   //Selección
{
 int indMayor, i, j;
 TAlumno aux;

 for (i=0; i<ce-1; i++)
 {
     indMayor = i;
     for (j=i+1; j<ce; j++)
        if (V[j].prom > V[indMayor].prom)
            indMayor = j;

     if (i != indMayor)         //Intercambio con struct
     {
         aux = V[i];
         V[i] = V[indMayor];
         V[indMayor] = aux;
     }
 }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void MostrarVec (TAlumno V[], int ce)
{
 int i;

 for (i=0; i<ce; i++)
    printf("\n%8d %-30s %-30s %-4c %2d/%2d/%4d %15d %8.2f\n",V[i].DNI, V[i].ApyNom, V[i].Dom, V[i].sex, V[i].FNac.dia,
                                       V[i].FNac.mes, V[i].FNac.anio, V[i].cma, V[i].prom);
}










