// Ind1_.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <mpi.h>
#include <vector>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    int rank,
        size;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const int sizeM = 1000;
    double start_time;
    vector<int[sizeM]> M1(sizeM), M2(sizeM), partRes(sizeM), res(sizeM);

    for (int i = 0; i < sizeM; i++) {
        for (int j = 0; j < sizeM; j++) {
            M1[i][j] = 2;
            M2[i][j] = 2;
        }
    }

    start_time = clock() / (double)CLOCKS_PER_SEC;
    int nSend = ceil(sizeM / size);
    MPI_Datatype row, newRow;

    vector<int[sizeM]> M1Part(nSend);

    MPI_Type_contiguous(sizeM, MPI_INT, &row);
    MPI_Type_commit(&row);

    MPI_Bcast(&M2[0], sizeM, row, 0, MPI_COMM_WORLD);
    MPI_Scatter(&M1[0][0], nSend, row, &M1Part[0][0], nSend, row, 0, MPI_COMM_WORLD);

    for (int i = 0; i < M1Part.size(); i++) {
        for (int j = 0; j < sizeM; j++) {
            for (int k = 0; k < sizeM; k++) {
                partRes[j][k] += M1Part[i][k] * M2[j][k];
            }
        }
    }

    for (int i = 0; i < partRes.size(); i++) {
        MPI_Reduce(&partRes[i][0], &res[i][0], sizeM, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    }
    
    if (rank == 0) {
        cout << "Time : " << clock() / (double)CLOCKS_PER_SEC - start_time << endl;
        //for (int i = 0; i < res.size(); i++) {
        //    cout << rank << " : ";
        //    for (int j = 0; j < sizeM; j++) {
        //        cout << res[i][j] << " ";
        //    }
        //    cout << endl;
        //}
    }
    MPI_Finalize();
}