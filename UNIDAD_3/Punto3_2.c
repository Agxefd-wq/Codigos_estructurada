/*Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las funciones de
la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre coma espacio y
apellido) y mostrarlo*/

#include<stdio.h>
#include<string.h>
#define TAM 20

void SacarSaltoDeChar(char[]);


int main()
{
    char nombre[TAM],apellido[TAM],nomcompleto[40];
    printf("Ingrese su primer Nombre:\t");
    fgets(nombre,TAM,stdin);
    printf("\nIngrese su primer Apellido:\t");
    fgets(apellido,TAM,stdin);
    SacarSaltoDeChar(nombre);
    SacarSaltoDeChar(apellido);
    strcpy(nomcompleto,nombre);
    strcat(nomcompleto,", ");
    strcat(nomcompleto,apellido);
    printf("\nEl tercer string es igual: %s",nomcompleto);
    return 0;
}

void SacarSaltoDeChar(char oracion[])
{
    int largo;
    largo=strlen(oracion);
    if(oracion[largo-1]=='\n')
        oracion[largo-1]='\0';
}

/*#include <stdio.h>
#include <string.h>
int main ()
{
char receptor [40] = "Se agrego lo siguiente", dador [] =", me agregue";
printf ("Las cadenas por separado son: \n\t %s\n\t %s", receptor, dador);
strcat (receptor, dador);
printf ("\nLas cadenas unificadas son: \n\t %s ", receptor );
return 0;
}*/
