/*Desarrolle un programa que solicite el ingreso de un numero entero, que indica a su vez cuantos números
enteros ingresara el usuario. Crear en memoria dinámica el vector para almacenar el tamaño exacto de los
datos y leer los enteros que serán guardados en el vector “dinámico”. Informar el promedio de los datos
ingresados.
*/
#include<stdio.h>
#include<stdlib.h>

void CargarVect(int[],int);
void MostrarVect(int[],int);
float PromedioVect(int[],int);
int main()
{
    int *vNumeros;
    int cantnum;
    float promedio;
    int mal=0;
    do
    {
        if(mal) 
            printf("\nIngrese una cantidad valida:\t");
        else
            printf("\nIngrese la cantidad de numeros que desea ingresar:\t");
        mal=1;
        scanf("%d",& cantnum);
    } while (cantnum<0);
    vNumeros=(int*) calloc(cantnum,sizeof(int*));
    if(vNumeros==NULL)
    {
        printf("\nERROR AL CARGAR MEMORIA.");
        exit(1);
    }
    CargarVect(vNumeros,cantnum);
    MostrarVect(vNumeros,cantnum);
    promedio=PromedioVect(vNumeros,cantnum);
    printf("\nEl promedio de los numeros es: %.2f",promedio);
    free(vNumeros);
    return 0;
}
void CargarVect(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        printf("\nIngrese el %d numero:\t",i+1);
        scanf("%d",v+i);
    }
}

void MostrarVect(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        printf("\n%d",*(v+i));;
    }
}

float PromedioVect(int v[],int ce)
{
    int i;
    float total=0;
    for(i=0;i<ce;i++)
    {
        total+=v[i];
    }
    total=total/ce;
    return total;
}