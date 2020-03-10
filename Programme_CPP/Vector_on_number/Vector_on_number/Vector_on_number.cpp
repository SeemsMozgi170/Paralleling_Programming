// Vector_on_number.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <omp.h>

using namespace std;
//====================Вектор на число================================
double VectorOnNumberWithParalleling(int n, int numThreads) {
	const double Chislo = ((rand() % 2001) - 1000) / 10;
	vector<double> mas1(n);
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	#pragma omp parallel for num_threads(numThreads)
	for (int i = 0; i < mas1.size(); i++) {
		mas1[i] = ((rand() % 2001) - (double)1000) / 10;
		mas1[i] *= Chislo;
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}

double VectorOnNumberWithoutParalleling(int n) {
	const double Chislo = ((rand() % 2001) - 1000) / 10;
	vector<double> mas1(n);
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	for (int i = 0; i < mas1.size(); i++) {
		mas1[i] = ((rand() % 2001) - (double)1000) / 10;
		mas1[i] *= Chislo;
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}
//====================Вектор на вектор================================
double VectorOnVectorWithParalleling(int n, int numThreads) {
	vector<double> mas2_1(n);
	vector<double> mas2_2(n);
	double res2 = 0;
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	#pragma omp parallel for num_threads(numThreads)
	for (int i = 0; i < mas2_1.size(); i++) {
		mas2_1[i] = ((rand() % 2001) - (double)1000) / 10;
		mas2_2[i] = ((rand() % 2001) - (double)1000) / 100;
		res2 += mas2_1[i] * mas2_2[i];
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}

double VectorOnVectorWithoutParalleling(int n) {
	vector<double> mas2_1(n);
	vector<double> mas2_2(n);
	double res2 = 0;
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	for (int i = 0; i < mas2_1.size(); i++) {
		mas2_1[i] = ((rand() % 2001) - (double)1000) / 10;
		mas2_2[i] = ((rand() % 2001) - (double)1000) / 100;
		res2 += mas2_1[i] * mas2_2[i];
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}
//====================Матрица на матрицу================================
double MatrixOnMatrixWithParalleling(int n1, int m1, int n2, int m2, int numThreads) {
	vector<vector<double>> mat1(n1);
	vector<vector<double>> mat2(n2);
	vector<vector<double>> res(n1);
	for (int i = 0; i < mat1.size(); i++) {
		mat1[i].resize(m1);
		for (int j = 0; j < mat1[i].size(); j++) {
			mat1[i][j] = ((rand() % 2001) - 1000) / 10;
		}
	}
	for (int i = 0; i < mat2.size(); i++) {
		mat2[i].resize(m2);
		for (int j = 0; j < mat2[i].size(); j++) {
			mat2[i][j] = ((rand() % 2001) - 1000) / 10;
		}
	}
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	#pragma omp parallel for num_threads(numThreads)
	for (int i = 0; i < res.size(); i++) {
		res[i].resize(m2);
		#pragma omp parallel for num_threads(numThreads)
		for (int j = 0; j < mat2[0].size(); j++) {
			res[i][j] = 0;
			#pragma omp parallel for num_threads(numThreads)
			for (int k = 0; k < mat1[0].size(); k++) {
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}

double MatrixOnMatrixWithoutParalleling(int n1, int m1, int n2, int m2) {
	vector<vector<double>> mat1(n1);
	vector<vector<double>> mat2(n2);
	vector<vector<double>> res(n1);
	for (int i = 0; i < mat1.size(); i++) {
		mat1[i].resize(m1);
		for (int j = 0; j < mat1[i].size(); j++) {
			mat1[i][j] = ((rand() % 2001) - 1000) / 10;
		}
	}
	for (int i = 0; i < mat2.size(); i++) {
		mat2[i].resize(m2);
		for (int j = 0; j < mat2[i].size(); j++) {
			mat2[i][j] = ((rand() % 2001) - 1000) / 10;
		}
	}
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	for (int i = 0; i < res.size(); i++) {
		res[i].resize(m2);
		for (int j = 0; j < mat2[0].size(); j++) {
			res[i][j] = 0;
			for (int k = 0; k < mat1[0].size(); k++) {
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}
//====================Матрица на число================================
double MatrixOnNumberWithParalleling(int n, int m, int numThreads) {
	const double number = ((rand() % 2001) - 1000) / 10;
	vector<vector<double>> mat(n);
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	#pragma omp parallel for num_threads(numThreads)
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(n);
		#pragma omp parallel for num_threads(numThreads)
		for (int j = 0; j < mat[i].size(); j++) {
			mat[i][j] = ((rand() % 2001) - 1000) / 10;
			mat[i][j] *= number;
		}
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}

double MatrixOnNumberWithoutParalleling(int n, int m) {
	const double number = ((rand() % 2001) - 1000) / 10;
	vector<vector<double>> mat(n);
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(n);
		for (int j = 0; j < mat[i].size(); j++) {
			mat[i][j] = ((rand() % 2001) - 1000) / 10;
			mat[i][j] *= number;
		}
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}
//====================Матрица на вектор================================
double MatrixOnVectorWithParalleling(int n, int m, int numThreads) {
	vector<double> vec(m);
	vector<vector<double>> mat(n);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(m);
		for (int j = 0; j < mat[i].size(); j++) {
			mat[i][j] = ((rand() % 2001) - 1000) / 10;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = ((rand() % 2001) - (double)1000) / 10;
	}
	vector<double> resVector(n);
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	#pragma omp parallel for num_threads(numThreads)
	for (int i = 0; i < mat.size(); i++) {
		#pragma omp parallel for num_threads(numThreads)
		for (int j = 0; j < mat[i].size(); j++) {
			resVector[i] += mat[i][j] * vec[j];
		}
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}

double MatrixOnVectorWithoutParalleling(int n, int m) {
	vector<double> vec(m);
	vector<vector<double>> mat(n);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(m);
		for (int j = 0; j < mat[i].size(); j++) {
			mat[i][j] = ((rand() % 2001) - 1000) / 10;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = ((rand() % 2001) - (double)1000) / 10;
	}
	vector<double> resVector(n);
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			resVector[i] += mat[i][j] * vec[j];
		}
	}
	return clock() / (double)CLOCKS_PER_SEC - tStart;
}

int main()
{
	const int n = 1000;
	const int m = 1000;
//====================Вектор на число================================
	printf("time(Vector on Number Without OMP) = %15.12f\n", VectorOnNumberWithoutParalleling(n));
	printf("time(Vector on Number With OMP(2)) = %15.12f\n", VectorOnNumberWithParalleling(n, 2));
	printf("time(Vector on Number With OMP(4)) = %15.12f\n", VectorOnNumberWithParalleling(n, 4));
	cout << "================================================================================" << endl;
//====================Вектор на вектор================================
	printf("time(Vector on Vector Without OMP) = %15.12f\n", VectorOnVectorWithoutParalleling(n));
	printf("time(Vector on Vector With OMP(2)) = %15.12f\n", VectorOnVectorWithParalleling(n, 2));
	printf("time(Vector on Vector With OMP(4)) = %15.12f\n", VectorOnVectorWithParalleling(n, 4));
	cout << "================================================================================" << endl;
//====================Матрица на матрицу================================
	printf("time(Matrix on Matrix Without OMP) = %15.12f\n", MatrixOnMatrixWithoutParalleling(n, m, m, n));
	printf("time(Matrix on Matrix With OMP(2)) = %15.12f\n", MatrixOnMatrixWithParalleling(n, m, m, n, 2));
	printf("time(Matrix on Matrix With OMP(4)) = %15.12f\n", MatrixOnMatrixWithParalleling(n, m, m, n, 4));
	cout << "================================================================================" << endl;
//====================Матрица на число================================
	printf("time(Matrix on Number Without OMP) = %15.12f\n", MatrixOnNumberWithoutParalleling(n, m));
	printf("time(Matrix on Number With OMP(2)) = %15.12f\n", MatrixOnNumberWithParalleling(n, m, 2));
	printf("time(Matrix on Number With OMP(4)) = %15.12f\n", MatrixOnNumberWithParalleling(n, m, 4));
	cout << "================================================================================" << endl;
//====================Матрица на вектор================================
	printf("time(Matrix on Vector Without OMP) = %15.12f\n", MatrixOnVectorWithoutParalleling(n, m));
	printf("time(Matrix on Vector With OMP(2)) = %15.12f\n", MatrixOnVectorWithParalleling(n, m, 2));
	printf("time(Matrix on Vector With OMP(4)) = %15.12f\n", MatrixOnVectorWithParalleling(n, m, 4));
}