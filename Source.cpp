#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
	
void setMatrix(double **M, int n);
void setMatrix_T(double **K, int n);
void compare(double **A, double **M, double **K, int n);
long double fac(int n);
void printMatrix(double **M, int n);

int main()
{
	int n;
	cout << "Enter to n: ";
	cin >> n;

	double** M = new double*[n];
	for (int i(0); i < n; i++)
			M[i] = new double[n];

	double** K = new double*[n];
	for (int i(0); i < n; i++)
		K[i] = new double[n];

	double** A = new double*[n];
	for (int i(0); i < n; i++)
		A[i] = new double[n];

	setMatrix(M, n);

	setMatrix_T(K, n);

	compare(A, M, K, n);

	printMatrix(M, n);
	cout << endl;

	printMatrix(K, n);
	cout << endl;

	printMatrix(A, n);

	system("pause");

	return 0;
}

void setMatrix(double **M, int n) {
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			if (i == j) {
				M[i][j] = 1;
				continue;
			}
			M[i][j] = (cos(i + j) - cos(i - j)) / pow(i + j + 1, 2);
		}
	} 
}

void printMatrix(double **M, int n)
{
	
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			cout <<  setprecision(10)<< setw(20) << M[i][j];
		}
		cout << endl;
	}
}

void setMatrix_T(double **K, int n) {
	double S1(0), S2(0);
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			if (i == j) {
				K[i][j] = 1;
				continue;
			}
			for (int f(0); f < 40; f++) {
				S1 = S1 + (pow(-1, f)*pow(i + j, 2 * f)) / fac(2 * f);
				S2 = S2 + (pow(-1, f)*pow(i - j, 2 * f)) / fac(2 * f);
			}
			K[i][j] = (S1 - S2) / pow(i + j + 1, 2);
		}
	}
}

long double fac(int n) {
	if (n == 0) return 1;
	return n * fac(n - 1);
}

void compare(double **A, double **M, double **K, int n) {
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			A[i][j] = abs(abs(M[i][j]) - abs(K[i][j]));
		}
	}
}