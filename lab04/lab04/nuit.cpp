#include "headers.h"

using namespace std;

void niut(double x1, double E, double k) {
	int N = 0;
	double f, fp;

	do {
		fp = 1 + k * sin(x1);
		f = fun(x1, k);
		x1 = x1 - (f / fp);
		N++;
	} while (abs(f) >= E && N <= 100000);
	cout << "Метод Ньютона:\n";
	cout << "Значение: " << setprecision(10) << x1 << " Колличество итераций: " << N << endl;
}