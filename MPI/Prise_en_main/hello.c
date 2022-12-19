#include <mpi.h>
#include <stdio.h>

int main( int argc, char **argv) {
    int nb_proc, rank ;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&nb_proc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Hello world from process %d of %d \n", rank+1, nb_proc);


    MPI_Finalize();
}