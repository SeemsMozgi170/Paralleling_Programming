// Vector_on_number.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
	//double tStart = clock() / (double)CLOCKS_PER_SEC;

	const int n = 2000;
	const int m = 3000;
	double result = 0;

//====================Вектор на число================================
	double tStart = clock() / (double)CLOCKS_PER_SEC;
	const double Chislo = ((rand() % 200001) - 100000) / 100;

	vector<double> mas1(n);
	for (int i = 0; i < mas1.size(); i++) {
		mas1[i] = (double)((rand() % 200001) - 100000) / 100;
		mas1[i] *= Chislo;
	}
	cout << "time(Vector on Number) = " << clock() / (double)CLOCKS_PER_SEC - tStart << endl;
//====================Вектор на вектор================================
	tStart = clock() / (double)CLOCKS_PER_SEC;

	vector<double> mas2_1(n);
	vector<double> mas2_2(n);
	double res2 = 0;
	for (int i = 0; i < mas2_1.size(); i++) {
		mas2_1[i] = (double)((rand() % 200001) - 100000) / 100;
		mas2_2[i] = (double)((rand() % 200001) - 100000) / 100;
		res2 += mas2_1[i] * mas2_2[i];
	}
	cout << "time(Vector on Vector) = " << clock() / (double)CLOCKS_PER_SEC - tStart << endl;
	mas2_1.clear();
	mas2_2.clear();
//====================Матрица на матрицу================================
	tStart = clock() / (double)CLOCKS_PER_SEC;

	vector<vector<double>> mat3_1(n);
	vector<vector<double>> mat3_2(m);
	for (int i = 0; i < mat3_1.size(); i++) {
		mat3_1[i].resize(m);
		for (int j = 0; j < mat3_1[i].size(); j++) {
			mat3_1[i][j] = ((rand() % 200001) - 100000) / 100;
		}
	}
	for (int i = 0; i < mat3_2.size(); i++) {
		mat3_2[i].resize(n);
		for (int j = 0; j < mat3_2[i].size(); j++) {
			mat3_2[i][j] = ((rand() % 200001) - 100000) / 100;
		}
	}
	vector<vector<double>> res3(n);
	for (int i = 0; i < res3.size(); i++) {
		res3[i].resize(n);
		for (int j = 0; j < mat3_2[0].size(); j++) {
			res3[i][j] = 0;
			for (int k = 0; k < mat3_1[0].size(); k++) {
				res3[i][j] += mat3_1[i][k] * mat3_2[k][j];
			}
		}
	}
	cout << "time(Matrix on Matrix) = " << clock() / (double)CLOCKS_PER_SEC - tStart << endl;
//====================Матрица на число================================
	tStart = clock() / (double)CLOCKS_PER_SEC;
	const double number = ((rand() % 200001) - 100000) / 100;
	vector<vector<double>> mat3(n);
	for (int i = 0; i < mat3.size(); i++) {
		mat3[i].resize(n);
		for (int j = 0; j < mat3[i].size(); j++) {
			mat3[i][j] = ((rand() % 200001) - 100000) / 100;
			mat3[i][j] *= number;
		}
	}
	cout << "time(Matrix on Number) = " << clock() / (double)CLOCKS_PER_SEC - tStart << endl;
//====================Матрица на вектор================================
	vector<double> vec1(m);
	vector<vector<double>> mat4(n);
	for (int i = 0; i < mat4.size(); i++) {
		mat4[i].resize(m);
		for (int j = 0; j < mat4[i].size(); j++) {
			mat4[i][j] = ((rand() % 200001) - 100000) / 100;
		}
	}
	for (int i = 0; i < vec1.size(); i++) {
		vec1[i] = (double)((rand() % 200001) - 100000) / 100;
	}
	vector<double> resVector(n);
	for (int i = 0; i < mat4.size(); i++) {
		for (int j = 0; j < mat4[i].size(); j++) {
			resVector[i] += mat4[i][j] * vec1[j];
		}
	}
	cout << "time(Matrix on Vector) = " << clock() / (double)CLOCKS_PER_SEC - tStart << endl;
}