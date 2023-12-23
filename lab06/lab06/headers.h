#include <iostream>
#include <iomanip>
#include <cmath>

struct I_print {	//данные для печати результатов интегрирования
	const char* name;//название функции
	double i_sum;	//значение интегральной суммы
	double i_toch;	//точное значение интеграла
	int n;	//число разбиений области интегрирования 
	//при котором достигнута требуемая точность
};

typedef double (*TPF)(double);
typedef double (*TPM)(TPF f, double a, double b, int n);

double Integral(TPF f, TPM IntTupe, double eps, double a, double b, int& n);
double IntRect(TPF f, double a, double b, int n);
double IntTrap(TPF f, double a, double b, int n);
double PresInt(int i, double a, double b);

double f1(double);
double f2(double);
double f3(double);
double f4(double);

void PrintTabl(I_print i_prn[], int k);
void fullRow(int k);



