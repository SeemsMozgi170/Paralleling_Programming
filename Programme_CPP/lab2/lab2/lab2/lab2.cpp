// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <mpi.h>
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
    double number_from, number_to;
    vector<double> arrData(size - 1);

    number_from = exp(rank);
    if (rank == 0) {
        for (int i = 0; i < arrData.size(); i++) {
            MPI_Ssend(&number_from, 1, MPI_DOUBLE, i + 1, 0, MPI_COMM_WORLD);
        }
        for (int i = 0; i < arrData.size(); i++) {
            MPI_Recv(&number_to, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            arrData[i] = number_to;
            cout << "Main process : " << arrData[i] << endl;
        }
    }
    else {
        MPI_Recv(&number_to, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        MPI_Ssend(&number_from, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        cout << "Data process " << rank << " : " << number_to << endl;
    }
    MPI_Finalize();
}