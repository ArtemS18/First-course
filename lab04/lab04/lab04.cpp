#include "headers.h"

using namespace std;

double fun(double x, double k) {
	return (x - k * cos(x));
}
void main() {
	do {
		system("chcp 1251 > nul");
		double x1, l1, l2;
		double E1 = 0.000001, E2 = 0.00000001, k = 0;
		cout << "��������� ������: ";cin >> x1;
		cout << "����. ���������: ";cin >> k;
		cout << "���������: \n" ;
		cin >> l1 >> l2;
		cout << "���������: x-" << k << "cosx = 0" << " E: " << E1 << endl;
		iter(x1, E1, k);
		niut(x1, E1, k);
		binom(x1,E1, k, l1, l2);
		cout << "\n���������: x-" << k << "cosx = 0" << " E: " << E2 << endl;
		iter(x1, E2, k);
		niut(x1, E2, k);
		binom(x1, E2, k, l1, l2);
		cout << "\n\n";
	} while (1);
}