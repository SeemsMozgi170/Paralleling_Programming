// BandAlghoritmMultyMatrixes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <omp.h>
using namespace std;

double MultyplyingMatrixWithoutOMP(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> C;
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	C.resize(A.size());
	for (int k = 0; k < A.size(); k++) {
		C[k].resize(A.size());
		for (int i = 0; i < B.size(); i++) {
			for (int j = 0; j < B[i].size(); j++) {
				C[k][j] += A[k][j] * B[i][j];
			}
		}
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}

double MultyplyingMatrixWithOMP(vector<vector<int>> A, vector<vector<int>> B, int numThreads) {
	vector<vector<int>> C;
	C.resize(A.size());
	double timeStart = omp_get_wtime();
	int j, k, sum;
	#pragma omp parallel for private(j,k) num_threads(numThreads)
	for (int i = 0; i < A.size(); i++) {
		C[i].resize(A.size());
		for (j = 0; j < B.size(); j++) {
			for (k = 0; k < B[j].size(); k++) {
				C[i][k] += A[i][k] * B[j][k];
			}
		}
	}
	return omp_get_wtime() - timeStart;
}

int main()
{
	vector<vector<int>> A, B;
	int size = 1000;
	A.resize(size); B.resize(size);
	#pragma omp parallel for
	for (int i = 0; i < A.size(); i++) {
		A[i].resize(size);
		#pragma omp parallel for
		for (int j = 0; j < A[i].size(); j++) {
			A[i][j] = ((rand() % 201) - (double)100);
		}
	}
	#pragma omp parallel for
	for (int i = 0; i < B.size(); i++) {
		B[i].resize(size);
		#pragma omp parallel for
		for (int j = 0; j < B[i].size(); j++) {
			B[i][j] = ((rand() % 201) - (double)100);
		}
	}

	cout << "time (Without OMP) = " << MultyplyingMatrixWithoutOMP(A,B) << endl;
	cout << "time (With OMP(2)) = " << MultyplyingMatrixWithOMP(A, B, 2) << endl;
	cout << "time (With OMP(4)) = " << MultyplyingMatrixWithOMP(A, B, 4) << endl;
}