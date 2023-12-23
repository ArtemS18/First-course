#include "headers.h"

using namespace std;

double f1(double x) {
	return x;
}

double f2(double x) {
	return sin(22 * x);
}

double f3(double x) {
	return x * x * x * x;
}

double f4(double x) {
	return atan(x);
}

double IntRect(TPF f, double a, double b, int n) {
	double S1 = 0;
	double dx = abs(b - a) / n;

	for (int i = 0; i < n;i++) {
		S1 += f(a + dx * (i + 0.5));
	}
	S1 *= dx;
	return S1;
}

double IntTrap(TPF f, double a, double b, int n) {
	double S1 = 0;
	double x = a, dx = abs(b - a) / n;

	for (int i = 0; i < n;i++) {
		S1 += dx * (f(x) + f(x + dx)) / 2;
		x += dx;
	}
	return S1;
}

double Integral(TPF f, TPM IntTupe, double eps, double a, double b, int& n) {
	n = 2;int i = 2;double diff;
	do {
		diff = IntTupe(f, a, b, pow(n, i)) - IntTupe(f, a, b, n * (pow(n, i+1) + 2));
		i++;
	} while ((abs(diff) / 3) > eps);
	n = pow(n, i);
	return IntTupe(f, a, b, n);
}

double PresInt(int i, double a, double b) {
	switch (i) {
	case 0: return  (b * b - a * a) / 2.0;break;
	case 1: return (cos(a * 22.0) - cos(b * 22.0)) / 22.0;break;
	case 2: return (b * b * b * b * b - a * a * a * a * a) / 5.0; break;
	case 3: return b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0; break;
	}
}