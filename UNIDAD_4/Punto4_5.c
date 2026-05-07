/*De una persona se conoce los siguientes datos:
• Número de Legajo (int, entre 1 y 10.000)
• Apellido (string, 15 caracteres)
• Nombre (string, 15 caracteres)
• Altura (float, mayor de 0)
• Sexo (char, F o M)
• Día de Nacimiento (int, entre 1 y 31
• Mes de Nacimiento (int, ente 1 y 12)
• Año de Nacimiento (int, ente 1950 y 2019)
Se solicita realizar los siguientes procesos:
a. Con datos ingresados por teclado: Crear una Estructura de Datos con los datos enunciados
anteriormente y llamarla PERSONA.
b. Mostrar los datos de la Estructura de Datos del punto a.
c. Con datos ingresados por teclado: Modificar la Estructura de Datos del punto a., crear una Estructura
de Datos que contenga Nombre y Apellido y otra Estructura de Datos que contenga Día/Mes/Año
utilizarla en una nueva Estructurad de Datos llamada PERSONA2.
d. Mostrar los datos de la Estructura de Datos del punto c.
e. Crear una FUNCION que cargue los datos de la Estructurad de Datos del punto c y que retorne los datos
al programa principal (main).
f. Con datos ingresados por teclado: Modificar la Estructurad de Datos llamada PERSONA2 del punto c.
y agregarle un campo/miembro que contenga los códigos de las Materias Aprobadas (pueden llegar a
ser hasta 36 materias) y llamarla PERSONA3.
g. Crear una FUNCION que realice el punto f.
h. Mostrar los datos de la Lista creada en el punto f.
i. Crear una FUNCION que realice el punto h.*/
#include <stdio.h>

typedef struct 
{
    int legajo;
    char apellido[15];
    char nombre[15];
    float altura;
    char sexo;    
    int d;
    int m;
    int a;
}PERSONA;

typedef struct 
{
    char nombre[15];
    char apellido[15];
}NOMBRECOMPL;

typedef struct 
{
    int d;
    int m;
    int a;
}NACIMIENTO;

typedef struct 
{
    NACIMIENTO fecha;
    NOMBRECOMPL nombreapell;
    int legajo;
    float altura;
    char sexo;
}PERSONA2;

typedef struct 
{
    NACIMIENTO fecha;
    NOMBRECOMPL nombreapell;
    int legajo;
    int aprobadas[36];
    float altura;
    char sexo;
}PERSONA3;



int esDatoVal (int, int, int);
int IngrDatoVal (int, int);
int esDatoValCh (char, char, char);
int esBisiesto (int);
int CantDiasMes (int, int);
int esFechaValida (int, int, int);


PERSONA IngresarPersona();
PERSONA2 IngresarPersona2();
int IngresarPersona3(PERSONA3,int);
void MostrarPersona3(PERSONA3,int);
int BuscarInt(int[],int,int);
NACIMIENTO IngrFechaVal();

int main()
{
    //PERSONA p_main;
    //PERSONA2 p2_main;
    PERSONA3 p3_main;
    int materias;
    /*p_main=IngresarPersona();
    printf("\nPERSONA 1:");
    printf("\nNombre: %s",p_main.nombre);
    printf("\nApellido: %s",p_main.apellido);
    printf("\nLegajo: %d",p_main.legajo);
    printf("\nAltura: %.2f",p_main.altura);
    printf("\nSexo: %c",p_main.sexo);
    printf("\nFecha de nacimiento: %d/%d/%d",p_main.d,p_main.m,p_main.a);*/
    /*    p2_main=IngresarPersona2();
    printf("\nPERSONA 2:");
    printf("\nNombre: %s",p2_main.nombreapell.nombre);
    printf("\nApellido: %s",p2_main.nombreapell.apellido);
    printf("\nLegajo: %d",p2_main.legajo);
    printf("\nAltura: %.2f",p2_main.altura);
    printf("\nSexo: %c",p2_main.sexo);
    printf("\nFecha de nacimiento: %d/%d/%d",p2_main.fecha.d,p2_main.fecha.m,p2_main.fecha.a);*/
    materias=IngresarPersona3(p3_main,36);
    MostrarPersona3(p3_main,materias);
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

int esDatoValCh (char dato, char x, char y)
{
    int bien;
    if (dato == x || dato == y)
        bien = 1;
    else
        bien = 0;
    return bien;
}

int esFechaValida (int d, int m, int a)
{
 int dv = 0;
 if (a > 1900)
    if (m >= 1 && m <= 12)
        if (d >= 1 && d <= CantDiasMes(m, a))
            dv = 1;

 return dv;
}

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

int esBisiesto(int a)
{
 if ((a%4==0 && a%100!=0) || a%400==0)
    return 1;
 else
    return 0;
}

PERSONA IngresarPersona()
{
    int mal,f;
    PERSONA p;
    printf("\nIngrese el nombre del alumno:\t");
    gets(p.nombre);
    fflush(stdin);
    printf("\nIngrese el apellido:\t");
    gets(p.apellido);
    printf("\nIngrese el legajo-entre 1 y 10000:\t");
    p.legajo=IngrDatoVal(1,10000);
    mal=0;
    do
    {
        if(mal)
            printf("\nERROR-Ingrese un valor correcto:\t");
        else
            printf("\nIngrese la altura:\t");
        mal=1;
        scanf("%f",& p.altura);
    } while (p.altura<=0);
    mal=0;
    do
    {
        if(mal)
            printf("\nERROR-Ingrese una letra valida:\t");
        else
            printf("\nIngrese el genero- F o M:\t");
        mal=1;
        fflush(stdin);
        scanf("%c",& p.sexo);
    } while (!esDatoValCh(p.sexo,'F','M'));
    do
    {
        printf("\nIngrese la fecha de nacimiento.");
        printf("\nIngrese el dia:\t");
        scanf("%d",& p.d);
        printf("\nIngrese el mes:\t");
        scanf("%d",& p.m);
        printf("\nIngrese el anio:\t");
        scanf("%d",& p.a);
        f=esFechaValida(p.d,p.m,p.a);
        if(!f)
            printf("\nERROR-Fecha invalida.");
    } while (!f);
    return p;
}

PERSONA2 IngresarPersona2()
{
    int mal;
    PERSONA2 p;
    fflush(stdin);
    printf("\nIngrese el nombre del alumno:\t");
    gets(p.nombreapell.nombre);
    fflush(stdin);
    printf("\nIngrese el apellido:\t");
    gets(p.nombreapell.apellido);
    printf("\nIngrese el legajo-entre 1 y 10000:\t");
    p.legajo=IngrDatoVal(1,10000);
    mal=0;
    do
    {
        if(mal)
            printf("\nERROR-Ingrese un valor correcto:\t");
        else
            printf("\nIngrese la altura:\t");
        mal=1;
        scanf("%f",& p.altura);
    } while (p.altura<=0);
    mal=0;
    do
    {
        if(mal)
            printf("\nERROR-Ingrese una letra valida:\t");
        else
            printf("\nIngrese el genero- F o M:\t");
        mal=1;
        fflush(stdin);
        scanf("%c",& p.sexo);
    } while (!esDatoValCh(p.sexo,'F','M'));
    p.fecha=IngrFechaVal();
    return p;
}

int IngresarPersona3(PERSONA3 p,int ce)
{
    PERSONA3 aux;
    int mal,codigo,pos,i=0;
    fflush(stdin);
    printf("\nIngrese el nombre del alumno:\t");
    gets(aux.nombreapell.nombre);
    fflush(stdin);
    printf("\nIngrese el apellido:\t");
    gets(aux.nombreapell.apellido);
    printf("\nIngrese el legajo-entre 1 y 10000:\t");
    aux.legajo=IngrDatoVal(1,10000);
    mal=0;
    do
    {
        if(mal)
            printf("\nERROR-Ingrese un valor correcto:\t");
        else
            printf("\nIngrese la altura:\t");
        mal=1;
        scanf("%f",& aux.altura);
    } while (aux.altura<=0);
    mal=0;
    do
    {
        if(mal)
            printf("\nERROR-Ingrese una letra valida:\t");
        else
            printf("\nIngrese el genero- F o M:\t");
        mal=1;
        fflush(stdin);
        scanf("%c",& aux.sexo);
    } while (!esDatoValCh(aux.sexo,'F','M'));
    aux.fecha=IngrFechaVal();
    printf("\nIngrese el codigo de la %d materia aprobada-Ingrese 999 para terminar:\t",i+1);
    codigo=IngrDatoVal(1,9999);
    while(i<ce && codigo!=999)
    {
        do
        {
            pos=BuscarInt(aux.aprobadas,codigo,i);
        if(pos!=-1)
        {
            printf("\nERROR-Codigo ya existente.Ingrese un codigo valido:\t");
            codigo=IngrDatoVal(1,9999);
        }
        } while (pos!=-1);
        aux.aprobadas[i]=codigo;
        //printf("\n%d",aux.aprobadas[i]);
        i++;
        printf("\nIngrese el codigo de la %d materia aprobada-Ingrese 999 para terminar:\t",i+1);
        codigo=IngrDatoVal(1,9999);
    }
    p=aux;
    //printf("\n%d",p.aprobadas[0]);
    return i;
}

NACIMIENTO IngrFechaVal()
{
    NACIMIENTO f;
    int mal=0;
    printf("\nIngrese la fecha de nacimiento.");
    do
    {
        if(mal)
            printf("\nERROR-Fecha invalida.");
        mal=1;
        printf("\nIngrese el dia:\t");
        scanf("%d",& f.d);
        printf("\nIngrese el mes:\t");
        scanf("%d",& f.m);
        printf("\nIngrese el anio:\t");
        scanf("%d",& f.a);
    } while (!esFechaValida(f.d,f.m,f.a));
    return f;
}

int BuscarInt(int v[],int abuscar,int ce)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if(v[i]==abuscar)
            pos=i;
        else
            i++;
    }
    return pos;
}

void MostrarPersona3(PERSONA3 p,int ce)
{
    int i;
    printf("\nPERSONA 3:");
    printf("\nNombre: %s",p.nombreapell.nombre);
    printf("\nApellido: %s",p.nombreapell.apellido);
    printf("\nLegajo: %d",p.legajo);
    printf("\nAltura: %.2f",p.altura);
    printf("\nSexo: %c",p.sexo);
    printf("\nFecha de nacimiento: %d/%d/%d",p.fecha.d,p.fecha.m,p.fecha.a);
    printf("\nMaterias aprobadas:");
    for(i=0;i<ce;i++)
    {
        printf("\nMateria:\t%d",p.aprobadas[i]);
    }
}