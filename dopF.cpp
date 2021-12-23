#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "dopF.h"

using namespace std;

double** createM(int n, int m)
{
	double** a = new double* [n];
	for (int i = 0; i < n; i++)
		a[i] = new double[m];
	return a;
}
void deleteM(double** a, int n, int m)
{
	for (int i = 0; i < n; i++)
		delete(a[i]);
	delete(a);
}

void outputM(double** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}

double** inputM(int n, int m)
{
	double** a = createM(n, m);
	for (int i = 0; i < n; i++)
	{
		cout << "\n¬ведите строку " << i << ": ";
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	cout << endl;
	return a;
}

double** inputFM(string s, int n, int m)
{
	ifstream f(s);
	double** a = createM(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			f >> a[i][j];
	return a;
	f.close();
}