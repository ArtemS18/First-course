#include "headers.h"

using namespace std;

void binom(double x1, double E, double func, double l1, double l2) {
	int N = 0;
	double f;
	cout << "Метод половинного деления:\n";
	if (fun(l1, func) * fun(l2, func) < 0) {
		do {
			x1 = (l1 + l2) / 2;
			f = fun(x1, func);
			if (fun(l1, func) * fun(x1, func) < 0) {
				l2 = x1;
			}
			else {
				l1 = x1;
			}
			N++;
		} while (abs(f) >= E && N <= 100000);
		cout << "Значение: " << setprecision(10) << x1 << " Колличество итераций: " << N << endl;
	}
	else {
		cout << "Нет корня на интервале " << endl;
	}
}
