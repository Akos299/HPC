#include <stdio.h>
#include<stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    double *randTab = malloc(1000 * sizeof(double));
    int i, rank;
    int nb_valeurs = 1000;
    int tag = 100;
    MPI_Status status;
    double stat,end;
    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0)
    {
        for (i = 0; i < nb_valeurs; i++)
            randTab[i] = rand()/(RAND_MAX +1.);
        
        stat = MPI_Wtime();
        MPI_Send(randTab,nb_valeurs,MPI_DOUBLE,1,tag,MPI_COMM_WORLD);
        MPI_Recv(randTab,nb_valeurs,MPI_DOUBLE,1,tag,MPI_COMM_WORLD,&status);
        end = MPI_Wtime();

        printf("La reception et l'envoie du message à durée %f (s) \n", end-stat);
    }

    else if (rank == 1){
        MPI_Recv(randTab,nb_valeurs,MPI_DOUBLE,0,tag,MPI_COMM_WORLD,&status);
        MPI_Send(randTab,nb_valeurs,MPI_DOUBLE,0,tag,MPI_COMM_WORLD);
    }

    MPI_Finalize();
    free(randTab);
    return 0;
}