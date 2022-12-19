#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    double *randTab = malloc(1000 * sizeof(double));
    int ii, jj, rank;
    int nb_valeurs = 1000;
    int tag = 100;
    MPI_Status status;
    long  long int sizes[10];
    double stat, end;
    MPI_Init(&argc, &argv);

    for (int i = 0; i < 10; i++)
        sizes[i] = i * (pow(10, i));

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for (jj = 0; jj < 10; jj++)
    {
        if (rank == 0)
        {
            for (ii = 0; ii < nb_valeurs; ii++)
                randTab[ii] = rand() / (RAND_MAX + 1.);

            stat = MPI_Wtime();
            MPI_Send(randTab, nb_valeurs, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD);
            MPI_Recv(randTab, nb_valeurs, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD, &status);
            end = MPI_Wtime();

            printf("La reception et l'envoie du message à durée %f (s) pour un débit de %7.2f (Mo.s)\n", (end - stat),(2.*sizes[jj]*8/1000000.)/(end - stat));
            
        }

        else if (rank == 1)
        {
            MPI_Recv(randTab, nb_valeurs, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &status);
            MPI_Send(randTab, nb_valeurs, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
        }
    }
    MPI_Finalize();
    free(randTab);
    return 0;
}