#include <iostream>
#include <iomanip>
#include <cmath>

struct I_print {	//������ ��� ������ ����������� ��������������
	const char* name;//�������� �������
	double i_sum;	//�������� ������������ �����
	double i_toch;	//������ �������� ���������
	int n;	//����� ��������� ������� �������������� 
	//��� ������� ���������� ��������� ��������
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



