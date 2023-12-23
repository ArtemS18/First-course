#include "headers.h"

using namespace std;

void iter(double x1, double E, double func) {
	double f;
	int N = 0;

	do {
		f = fun(x1, func);
		x1 = x1 - f;
		N++;
	} while (abs(f) >= E && N <= 100000);
	cout << "Метод итераций:\n";
	cout << "Значение: " << setprecision(10) << x1 << " Колличество итераций: " << N << endl;
}