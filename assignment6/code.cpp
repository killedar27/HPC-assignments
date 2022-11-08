#include <cstdio>
#include <cstdlib>
#include <vector>
#include "mpi.h"

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  int my_rank = 0;
  size_t size = atoi(argv[1]);
  // MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> sendbuf(size, my_rank), recvbuf(size);
  MPI_Status st;
  // if (rank == 0) {
  //   MPI_Send(sendbuf.data(), size, MPI_INT, 1, 0, MPI_COMM_WORLD);
  //   MPI_Recv(recvbuf.data(), size, MPI_INT, 1, 0, MPI_COMM_WORLD, &st);
  // } else {
  //   MPI_Send(sendbuf.data(), size, MPI_INT, 0, 0, MPI_COMM_WORLD);
  //   MPI_Recv(recvbuf.data(), size, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
  // }
  MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);
  if (my_rank == 0) {
    MPI_Send (sendbuf.data(), size, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv (recvbuf.data(), size, MPI_INT, 1, 0, MPI_COMM_WORLD, &st);
  } else if (my_rank == 1) {
    MPI_Recv (recvbuf.data(), size, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
    MPI_Send (sendbuf.data(), size, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
  printf("I am %d: Recieved %d\n", my_rank, recvbuf[0]);
  MPI_Finalize();
}