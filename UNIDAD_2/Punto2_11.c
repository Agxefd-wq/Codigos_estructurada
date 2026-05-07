/*Realizar el juego del rompecabezas de 8, dicho juego comienza con una matriz de 3x3 de números del 1
al 8 desordenados y un espacio en blanco. Como, por ejemplo:
2 5 1
7 6 3
8   4
El objetivo del juego es lograr que los números queden ordenados de la siguiente forma:
Para ello, el jugador puede mover un número a la vez al casillero libre, solo puedo mover alguno de los
números adyacentes al casillero en blando y solo en forma horizontal o vertical. Por ejemplo, tomando
como partida la primera matriz desordenada se podría mover el 6 hacia abajo, el 4 hacia la izquierda o el
8 hacia la derecha.
El jugador deberá ingresar el número que quiere mover y automáticamente moverlo, si es posible, al
casillero libre. Luego cada movimiento se debe controlar si se llega al objetivo de ordenar los números e
informar que se ha ganado la partida. Puede ir contando la cantidad de movimientos que se llevó al
jugador lograr llegar a ordenar el rompecabezas y mostrarlos al finalizar para que pueda volver a jugarlo
y superarse.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 3

void CargarRompeCabezas(int[][TAM],int[],int,int);
void CargarVecAleatorio(int[],int);
int Buscar(int[],int,int);
void MostrarMat(int[] [TAM],int,int);

int main()
{
    int mrompecabeza[TAM][TAM];
    int vrandom[9];
    srand(time(NULL));
    CargarVecAleatorio(vrandom,9);
    CargarRompeCabezas(mrompecabeza,vrandom,TAM,TAM);
    MostrarMat(mrompecabeza,TAM,TAM);
    return 0;
}

void CargarVecAleatorio(int v[],int ce)
{
    int num,pos,i;
    for(i=0;i<ce;i++)
    {
        do
        {
            do{
                num=rand()%10;
            }while(num<1);
            pos=Buscar(v,num,i);
        }while(pos!=-1);
        v[i]=num;
    }
}

void CargarRompeCabezas(int m[][TAM],int v[],int cf,int cc)
{
    int f,c,i=0;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            m[f][c]=v[i];
            i++;
        }
    }
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

void MostrarMat(int matr[] [TAM],int cf,int cc)
{
    int f,c,num;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            num=matr[f][c];
            if(num!=9)
                printf("%3d",matr[f] [c]);
            else
                printf("   ");
        }
        printf("\n");
    }
}
