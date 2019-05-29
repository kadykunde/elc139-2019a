// Adaptado de www.mpitutorial.com
// Exemplo de implementação do MPI_Bcast usando MPI_Send e MPI_Recv

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv) {

  int myrank;    // "rank" do processo
  int p;         // numero de processos
  int root;      // rank do processo root
  clock_t startTime, endTime;

  // MPI_Init deve ser invocado antes de qualquer outra chamada MPI
  MPI_Init(&argc, &argv);
  // Descobre o "rank" do processo
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  // Descobre o numero de processos
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  
  if (myrank == 0){
	startTime = clock();  
  }

  int data;     // dado a ser enviado
  root = 0;     // define o rank do root
  if (myrank == root) {
	data = 100;
  }
  
  MPI_Bcast(&data, 1, MPI_INT, root, MPI_COMM_WORLD);
  if (myrank == root) {
    printf("Processo %d (root) realizando broadcast do dado %d\n", myrank, data);
  } else {
	printf("Processo %d recebendo dado %d do processo root\n", myrank, data);
  }
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  if (myrank == 0){
    endTime = clock();
	double tempo = (endTime - startTime) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.\n", tempo);
  }
  return 0;
}