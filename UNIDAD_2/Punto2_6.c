/*Se solicita modificar el programa anterior para que además de la butaca y fila ingrese la cantidad de butacas
de la reserva. En dicho caso se deberá verificar si existen a partir de la butaca ingresada la cantidad suficiente
de butacas disponibles consecutivas (tomar siempre hacia la derecha del seleccionado). Si están disponibles
reservar todas las butacas, sino mostrar un mensaje de error.

*/
#include<stdio.h>

void MostrarMat(char[] [9],int,int);
void MostrarButacas(int[],int[],int);
void CargarMatChar(char[][9],int,int,char);
int IngresarYValidarIntRango(int,int);
int IngresarYValidarIntRangoExcepcion(int,int,int);
void ReservasEntradas(char[][9],int[],int[],int[],int,int);
int ReservarButaca(char[][9],int[],int[],int,int,int,int,char,char);
int Buscar(int[],int,int);
int MayorNumVec(int[],int);
void OrdenarBurbujeoDosVec(int[],int[],int);

int main()
{
    char entradas[12][9];//12=filas 9=butacas
    int vnumbutaca[9]={8,6,4,2,1,3,5,7,9};
    int vfila[12]={{0}};
    int vcantbutacaR[9]={{0}};
    int i,j,max;
    CargarMatChar(entradas,12,9,'D');
    ReservasEntradas(entradas,vnumbutaca,vfila,vcantbutacaR,12,9);
    max=MayorNumVec(vfila,12);
    printf("\nLa sala de cine queda asi:");
    MostrarMat(entradas,12,9);
    printf("\nLas filas que quedaron vacias son:");
    for(i=0;i<12;i++)
    {
        if(vfila[i]==0)
            printf("\nFILA %d",i+1);
    }
    printf("\nLas filas con mayor cantidad de espectadores fueron:");
    for(j=0;j<12;j++)
    {
        if(vfila[j]==max)
            printf("\nFILA %d",j+1);
    }
    MostrarButacas(vnumbutaca,vcantbutacaR,9);
    return 0;
}


void ReservasEntradas(char sillas[] [9],int numbutaca[],int cfila[],int cbutaca[],int cf,int cc)
{
    int fila,column,cant_reserva,reserva;
    MostrarMat(sillas,cf,cc);
    printf("\nIngrese el numero de fila que desea reservar-entre 1 y 12- -1 para terminar:\t");
    fila=IngresarYValidarIntRangoExcepcion(-1,1,12);
    while(fila!=-1)
    {   
        fila-=1;
        do
        {
            printf("\nIngrese el numero de butaca \n8-6-4-2-1-3-5-7-9:\t");
            column=IngresarYValidarIntRango(1,9);
            printf("\nIngrese la cantidad que butacas que desea reservar-entre 1 y 9");
            cant_reserva=IngresarYValidarIntRango(1,9);
            reserva=ReservarButaca(sillas,numbutaca,cbutaca,fila,column,cc,cant_reserva,'D','R');
            //if(reserva==1)
            //    printf("\nEl asiento ya a sido reservado.Porfavor ingrese otra butaca.");
            if(reserva)
                printf("\nERROR-Existe un asiento que ya a sido reservado.Ingrese otra butaca o cantidad de asiento.");
        } while(reserva);
        cfila[fila]+=cant_reserva;
        MostrarMat(sillas,cf,cc);
        printf("\nIngrese el numero de fila que desea reservar-entre 1 y 12- -1 para terminar:\t");
        fila=IngresarYValidarIntRangoExcepcion(-1,1,12);
    }

}
int ReservarButaca(char butaca[][9],int numbutaca[],int cont[],int f,int c,int cc,int sillasreservadas,char libre,char ocupado)
{
    int asiento=0,pos,i=0,j;
    pos=Buscar(numbutaca,c,cc);
    /*if(butaca[f][pos]==libre)
    {
        cont[pos]++;
        butaca[f][pos]=ocupado;
        asiento=0;
    }
    else
        asiento=1;*/
        /*    while(pos<cc && i<sillasreservadas)
    {
        if(butaca[f][pos+i]==ocupado)
        {
            asiento=-1;
        }
        i++;
    }
    if(asiento==0)
    {
        if(butaca[f][pos]==ocupado)
        {
            asiento=1;
        }
        else
        {
            for(j=0;j<sillasreservadas;j++)
            {
                cont[pos+j]++;
                butaca[f][pos+j]=ocupado;
            }
        }*/
    while(pos<cc && i<sillasreservadas)
    {
        if(butaca[f][pos+i]==ocupado)
        {
            asiento=-1;
        }
        i++;
    }
    if(asiento==0)
    {
        for(j=0;j<sillasreservadas;j++)
        {
            cont[pos+j]++;
            butaca[f][pos+j]=ocupado;
        }
    }
    return asiento;
}

void MostrarButacas(int numbutaca[],int cant[],int ce)
{
    int i;
    OrdenarBurbujeoDosVec(cant,numbutaca,ce);
    printf("\nBUTACA:\tCANTIDAD:");
    for(i=0;i<ce;i++)
    {
        printf("\n %d\t%d",numbutaca[i],cant[i]);
    }
}

void CargarMatChar(char mat[][9],int cf,int cc,char letra)
{
    int f,c;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
            mat[f] [c]=letra;
    }
}
void MostrarMat(char matr[] [9],int cf,int cc)
{
    int f,c;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            printf("%3c",matr[f] [c]);
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

int IngresarYValidarIntRangoExcepcion(int exc, int li, int ls)
{
    int num;
    do
    {
        scanf("%d",&num);
        if(num!=exc && (num < li || num > ls))
            printf("\nERROR-Ingrese un valor valido:\t");
    }while(num!=exc && (num < li || num > ls));
    return num;
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

int MayorNumVec(int v[],int ce)
{
    int max=v[0],i;
    for(i=1;i<ce;i++)
    {
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

void OrdenarBurbujeoDosVec(int v1[],int v2[],int ce)
{
    int i,j,aux;
    float aux_float;
    for(i=0;i<ce-1;i++)
    {
        for (j = 0; j < ce-1; j++)
        {
            if(v1[j]<v1[j+1])
            {
                aux_float=v1[j];
                v1[j]=v1[j+1];
                v1[j+1]=aux_float;

                aux=v2[j];
                v2[j]=v2[j+1];
                v2[j+1]=aux;
            }
        }  
    }
}
