/*Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
a. Considerar que las palabras están separadas por un único espacio.
b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo.*/

#include<stdio.h>
#include<string.h>
#define TAM 500

void ContarYMostrarPalabrasDeChar(char[]);
void SacarSaltoDeChar(char[]);

int main()
{
    char frase[TAM];
    printf("\nIngrese un frase de no mas de 500 caracteres:\n");
    fgets(frase,TAM,stdin);
    SacarSaltoDeChar(frase);
    ContarYMostrarPalabrasDeChar(frase);
    return 0;
}

void SacarSaltoDeChar(char oracion[])
{
    int largo;
    largo=strlen(oracion);
    if(oracion[largo-1]=='\n')
        oracion[largo-1]='\0';
}
//Cuenta 1 espacio
/*void ContarYMostrarPalabrasDeChar(char oracion[])
{
    int i;
    int largo,espacio,palabra=0;
    largo=strlen(oracion);
    puts(oracion);
    for(i=0;i<largo-1;i++)
    {
        if((oracion[i]==' ')&& !espacio)
        {
            espacio=1;
            palabra++;
        }
        else
            espacio=0;
    }
    printf("\nLa oracion tiene un total de :\t%d",palabra);   
}*/


//este si cuenta espacio largos
void ContarYMostrarPalabrasDeChar(char oracion[])
{
    int i;
    int largo,espacio,palabra=0;
    largo=strlen(oracion);
    puts(oracion);
    for(i=0;i<largo-1;i++)
    {
        if((oracion[i]==' ')&& !espacio)
        {
            espacio=1;
            palabra++;
        }
        else if(oracion[i]!=' ')
            espacio=0;
    }
    printf("\nLa oracion tiene un total de :\t%d",palabra);   
}