/* mpiHelloWorldNodeAndRank.c
 * A quick and simple hello world program with info about location
 * Aggretated from many online sources 
 * Current Author: Adam Lavely: adam.lavely@gmail.com
 */

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
  MPI_Init(NULL, NULL);

  // Figure out the total number of MPI tasks (-n coming in)
  int problemSize;
  MPI_Comm_size(MPI_COMM_WORLD, &problemSize);

  // Figure out the individual task number
  int myRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

  // Figure out what node this is on
  char nodeName[MPI_MAX_PROCESSOR_NAME];
  int nameLen;
  MPI_Get_processor_name(nodeName, &nameLen);

  // Print hello world with information about the task
  printf("HELLO WORLD from rank %d out of %d total MPI tasks located on Node %s\n",
         myRank, problemSize, nodeName);

  MPI_Finalize();
}
