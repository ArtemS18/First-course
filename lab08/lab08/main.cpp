#include <iostream>
#include <math.h>
#include <iomanip>

void createMatrix(double** matrix, double x, int N, int M) {
	int i_n, i_m;
	int long fact;
	for (int n = 1; n <= N; n++) {
		fact = 1;
		for (int m = 1; m <= M; m++) {
			i_n = n - 1;
			i_m = m - 1;
			fact *= m;
			if (n > m) {
				matrix[i_n][i_m] = pow(x, n) / fact;
			}
			else if (n < m) {
				matrix[i_n][i_m] = pow(-x, n) / fact;
			}
			else {
				matrix[i_n][i_m] = 1;
			}

		}
	}
}

void printMatrix(double** matrix, int N, int M) {
	int p_m = 0;
	int k = 0;
	int m=0;
	int h=5;

	int p;
	int f;
	std::cout << "Precision / Tupe" << '\n';
	std::cin >> p >> f;
	if (f == 1) { h = 80 /(p+5); }
	else if (f == 2) { h = 80 /(p+9); }
	while (m != M) {
		for (int n = 0; n < N; n++) {
			for (m = k; m < M; m++) {
				if (m % h == 0 && m != k) {
					p_m = m;
					break;
				}
				else {
					if (f == 1){ std::cout << std::fixed <<std::setw(p+5)<<std::setprecision(p) << matrix[n][m]; }
					else if (f == 2){ std::cout << std::scientific << std::setw(p+9) << std::setprecision(p) << matrix[n][m]; }
					
				}
			}
			std::cout << '\n';
		}
		k = p_m;
		std::cout << "__________________________________________\n";
	}
}
double ** foo(double g[10][10]) {
	double** matrix = new double* [10];
	for (int i = 0; i < 10; i++) { matrix[i] = new double[10]; }
	for (int i = 0; i < 10; i++) {
		for (int h = 0; h < 10; h++) {
			matrix[i][h] = g[i][h];
		}
	}
	return matrix;
}
int main() {
	using namespace std;
	int N;
	int M;
	std::cout<<"N/M: \n";
	std::cin >> N >> M;
	double** matrix = new double* [N];
	double x;
	std::cout << "X:\n";
	std::cin >> x;
	for (int i = 0; i < N; i++) { matrix[i] = new double[M]; }
	createMatrix(matrix, x, N, M);
	printMatrix(matrix, N, M);

	double B[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j=0; j < 10; j++) {
			B[i][j] = i * 10 + j;
		}
	}
	double** nB = foo(B);
	printMatrix(nB, 10, 10);
	/*cout << B << " " << endl;
	cout << B[1] << " " << *B + 2 << endl;
	cout << B[2] << " " << *B + 20 << " " << *(B + 2) + 6 << endl;
	cout << *(*(B + 2) - 1) << " " << &B[2][3] << endl;
	cout << *(B[2] - 3) << " " << *(*B + 5) << endl;
	cout << &B[0][23] << " " << *B[2] - 10 << " " << *B[2] << endl;*/

	return 0;

}
