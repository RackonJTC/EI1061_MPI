#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#define n 200000

int main( int argc, char *argv[] ) 
{
    int miId, numProcs, tam, i, j;

    j=0;
    int vector[n];
    // Inicializa MPI.
    MPI_Init( & argc, & argv );
    // Definimos número de procesos
    MPI_Comm_size( MPI_COMM_WORLD, & numProcs );
  
    MPI_Comm_rank( MPI_COMM_WORLD, & miId );
	
    MPI_Status estado;	
  	
    tam = n/numProcs;
    printf("Tam= %d\n",tam); 
   
    // Inicializacion vector
    for(i=miId*tam; i<(miId*tam+tam);i++)
    {
        vector[i]=miId;
    }

	
    for(i=0; i<numProcs; i++)
    {  	
	MPI_Bcast (&vector[j],tam, MPI_INT, i, MPI_COMM_WORLD);
	j+=tam;	
    }

    printf("Soy el procesador.  %d de %d y hago Broadcast\n", miId, numProcs );
    printf("Mi vector es: [");
    for(i=0; i<n; i++){printf(" %d ",vector[i]);}
    printf("]\n");

    // Finalizar MPI
    MPI_Finalize();
    return( 0);
  }