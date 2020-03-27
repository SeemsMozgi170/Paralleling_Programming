// WorkWithMPI.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <mpi.h>
#include <time.h>
#include <vector>

using namespace std;
int main(int argc, char* argv[])
{
    int rank, 
        size;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double start_time;
//-----------------------Vector on Vector(VOV)-----------------------------------------------
    int VOV_sizeVectors = 8000000,
        VOV_nSend = VOV_sizeVectors / size,
        VOV_resPart = 0,
        VOV_res = 0;
    vector<int> VOV_V1(VOV_sizeVectors, 2), 
                VOV_V2(VOV_sizeVectors, 2),
                VOV_V1Part(VOV_nSend),
                VOV_V2Part(VOV_nSend);

    start_time = clock() / (double)CLOCKS_PER_SEC;
    MPI_Scatter(&VOV_V1[0], VOV_nSend, MPI_INT, &VOV_V1Part[0], VOV_nSend, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(&VOV_V2[0], VOV_nSend, MPI_INT, &VOV_V2Part[0], VOV_nSend, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < VOV_V1Part.size(); i++) {
        VOV_resPart += VOV_V1Part[i] * VOV_V2Part[i];
    }

    MPI_Reduce(&VOV_resPart, &VOV_res, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    double VOV_Time = clock() / (double)CLOCKS_PER_SEC - start_time;
//-----------------------Matrix on Vector(MOV)-----------------------------------------------
    int MOV_sizeVector = 8,
        MOV_rowsMatrix = 8,
        MOV_columnsMatrix = 8,
        MOV_nSend = MOV_rowsMatrix / size;

    vector<int> MOV_V(MOV_sizeVector, 2),
                MOV_resPart(MOV_nSend),
                MOV_res(MOV_rowsMatrix);

    vector<vector<int>> MOV_M(MOV_rowsMatrix),
                        MOV_MPart(MOV_nSend);

    for (int i = 0; i < MOV_M.size; i++) {
        MOV_M[i].resize(MOV_columnsMatrix);
        for (int j = 0; j < MOV_M[i].size; j++) {
            MOV_M[i][j] = 2;
        }
    }

    start_time = clock() / (double)CLOCKS_PER_SEC;
    MPI_Bcast(&MOV_V[0], MOV_sizeVector, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(&MOV_M[0], MOV_nSend, MPI_INT, &MOV_MPart[0], MOV_nSend, MPI_INT, 0, MPI_COMM_WORLD);

    cout << MOV_MPart.size << endl;






    if (rank == 0) {
//        printf("Result(Vector on Vector) : %d \n", res);
//        cout << "Time : " << clock() / (double)CLOCKS_PER_SEC - start;
    }
    MPI_Finalize();
}