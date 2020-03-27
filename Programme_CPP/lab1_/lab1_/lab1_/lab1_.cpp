// lab1_.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <mpi.h>
#include <time.h>
using namespace std;

double generateDouble(double min, double max) {
    return (double)rand() / (double)RAND_MAX * (max - min) + min;
}
int generateInt(int min, int max) {
    return ((rand() % (2 * max + 1)) - min);
}

int main(int argc, char* argv[]) {
    int rank,
        size;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n;
    double m;

    if (rank > 0) {
        if (rank % 2 == 0) {
            srand(rank);
            n = generateInt(-10, 10);
            cout << "Square process " << rank << " : " << pow(n, 2) << endl;
            cout << "Cube process " << rank << " : " << pow(n, 3) << endl;
        }
        else
        {
            srand(rank);
            m = generateDouble(-10, 10);
            cout << "Square process " << rank << " : " << pow(m, 2) << endl;
            cout << "Cube process " << rank << " : " << pow(m, 3) << endl;
        }
    }
    MPI_Finalize();
}