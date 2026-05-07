/* Realizar el juego de Tatetí para dos jugadores. EL jugador 1 utilizará la letra X y el jugador 2 la letra O para
marcar sus elecciones. El tablero armarlo con una matriz de 3x3 que debe ser visualizada en pantalla en cada
jugada marcando la ubicación elegida por cada jugador. Luego de cada jugada se debe llamar a una función
para verificar si el jugador ganó o no la partida. Si se llega a la última jugada y nadie gana, se debe informar
del empate.
Complemento: Modificar el juego para que sea de un solo jugador. Deberá programar la inteligencia
artificial para que la computadora elija donde realizar la jugada para intentar ganar la partida y no perder
completando el espacio correspondiente cuando haga falta*/

#include <stdio.h>
#define TAM 3

void MostrarTateti(int[] [3],int,int);
void CargaMatIntCon(int[] [3],int,int,int);
void JugadorUno(int [][3]);
void JugadorDos(int [][3]);
int Ganar(int [][3],int,int);
int TatetiFila(int [][3],int,int,int,int);
int TatetiColumn(int [][3],int,int,int,int);
int TatetiCruz(int [][3],int);
int CasillaDisponible(int[][3],int,int);
int IngresarYValidarIntRango(int,int);


int main()
{
    int mtateti[TAM][TAM];
    int i=0,ganador=-1;
    CargaMatIntCon(mtateti,3,3,-10);
    while(i<9 && ganador==-1)
    {
        if(ganador==-1)
        {
            MostrarTateti(mtateti,3,3);
            JugadorUno(mtateti);
            ganador=Ganar(mtateti,3,3);
        }
        i++; 
        if(i==9 && ganador==-1)
        {
            ganador=-2;
        }
        if(ganador==-1)
        {
            MostrarTateti(mtateti,3,3);
            JugadorDos(mtateti);
            ganador=Ganar(mtateti,3,3);
        }
        i++; 
    }
    if(ganador==3)
        printf("\n\t\tGANADOR JUGADOR UNO");
    if(ganador==0)
        printf("\n\t\tGANADOR JUGADOR DOS");
    if(ganador==-2)
    {
        printf("\n\t\tEMPATE");
    }
    MostrarTateti(mtateti,3,3);  
    return 0;
}

void JugadorUno(int m[][3])
{
    int casilla,f,c;
    printf("\n\t\tJUGADOR 1:");
    do
    {
        printf("\nIngrese la fila que desea usar 1-2-3:\t");
        f=IngresarYValidarIntRango(1,3);
        f-=1;
        printf("\nIngrese la casilla 1-2-3:\t");
        c=IngresarYValidarIntRango(1,3);
        c-=1;
        casilla=CasillaDisponible(m,f,c);
        if(casilla)
            printf("\nERROR-Casilla ya ocupada.ingrese una jugada valida.");
    }while(casilla);
    m[f][c]=1;
}

void JugadorDos(int m[][3])
{
    int casilla,f,c;
    printf("\n\t\tJUGADOR 2:");
    do
    {
        printf("\nIngrese la fila que desea usar 1-2-3:\t");
        f=IngresarYValidarIntRango(1,3);
        f-=1;
        printf("\nIngrese la casilla 1-2-3:\t");
        c=IngresarYValidarIntRango(1,3);
        c-=1;
        casilla=CasillaDisponible(m,f,c);
        if(casilla)
            printf("\nERROR-Casilla ya ocupada.ingrese una jugada valida.");
    }while(casilla);
    m[f][c]=0;
}

int CasillaDisponible(int m[][3],int f,int c)
{
    int d=0;
    if(m[f][c]!=-10)
        d=1;
    return d;

}

int Ganar(int m[][TAM],int cf,int cc)
{
    int f=0,c=0;
    int ganador=-1;
    ganador=TatetiFila(m,f,c,cf,cc);
    if(ganador==-1)
    {
        ganador=TatetiColumn(m,f,c,cf,cc);
        if(ganador==-1)
          ganador=TatetiCruz(m,cc);
    }
    return ganador;
}

int TatetiFila(int m[][TAM],int f,int c,int cf,int cc)
{
    int aux,r=-1;
    while(f<cf && r==-1)
    {
        aux=0;
        while(c<cc && r==-1)
        {
            aux+=m[f][c];
            c++;
        }
        c=0;
        if(aux==3||aux==0)
        {
            r=aux;

        }
        else
            f++;
    }
    return r;
}


int TatetiColumn(int m[][TAM],int f,int c,int cf,int cc)
{
    int aux,r=-1;
    while(c<cc && r==-1)
    {
        aux=0;
        while(f<cf && r==-1)
        {
            aux+=m[f][c];
            f++;
        }
        f=0;
        if(aux==3||aux==0)
        {
            r=aux;

        }
        else
            c++;
    }
    return r;
}

int TatetiCruz(int m[][TAM],int cc)
{
    int aux=0,r=-1,i,j,z=0;
    for(i=0;i<cc;i++)
    {
        aux+=m[i][i];
    }
    if(aux==3||aux==0)
    {
        r=aux;
    }
    else
    {
        aux=0;
        for(j=2;j>-1;j--)
        {
            aux+=m[z][j];
            z++;
        }
        if(aux==3||aux==0)
        {
            r=aux;
        } 
    } 
    return r;
}

void CargaMatIntCon(int m[] [3],int cf,int cc,int num)
{
    int f,c;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            m[f][c]=num;
        }
    }
}

void MostrarTateti(int m[] [3],int cf,int cc)
{
    int f,c;
    printf("\n");
    for(f=0;f<cf;f++)
    {
        printf("\t\t");
        for(c=0;c<cc;c++)
        {
            if(m [f][c]==1)
                printf(" X ");
            if(m [f][c]==0)
                printf(" 0 ");
            if(m [f][c]==-10)
                printf(" - ");
        }
        printf("\n");
    }
}

int IngresarYValidarIntRango(int li,int ls)
{
    int num;
    do
    {
        scanf("%d",& num);
        if(num<li || num>ls)
            printf("\nERROR-Ingrese un valor entre %d y %d:\t",li-1,ls+1);
    } while (num<li || num>ls);
    return num;
}