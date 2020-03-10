// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <vector>

using namespace std;
int main()
{
	const int n = 10;
	vector<int> a,b;
	a.resize(n);
	b.resize(n);
	double tStart = clock() / (double)CLOCKS_PER_SEC;
#pragma omp parallel
	{
		cout << "First Thread" << endl;
		for (int i = 0; i < n; i++) {
			a[i] = ((rand() % 2001) - 1000) / 100;
			cout << "a[ " << i << " ] = " << a[i] << endl;
		}
	}
#pragma omp parallel
	{
		cout << "Second Thread" << endl;
		for (int i = 0; i < n; i++) {
			b[i] = ((rand() % 2001) - 1000) / 100;
			cout << "b[ " << i << " ] = " << b[i] << endl;
		}
	}
	cout << "time = " << clock() / (double)CLOCKS_PER_SEC - tStart << endl;
}