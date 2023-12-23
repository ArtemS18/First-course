#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int ex1() {
	char flag;
	do {
		short n, m, sum = 0;
		cout << "n: "; cin >> n;
		cout << "m: "; cin >> m;
		if (m < n) {
			for (int i = 5; i < n; i+=5) {
				if (i % m != 0) {
					sum += i;
				}
			}
			cout << sum<<endl;
		}
		cout << "Продолжить работу? (y/n)" << endl; cin >> flag;
	} while (flag == 'y');

	return 0;
}

void ex2() {
	while (true) {
		double p = 1, a, i;
		cout << "a: ";
		cin >> a;
		if (a >= 0) {
			for (i = 2; i <= 8; i += 2) {
				p *= pow(i, 2);
			}
			p -= a;
		}
		else
			for (i = 3; i <= 9; i += 3) {
				p *= (i - 2);
			}
		cout << setprecision(10) << p << endl;

	}
}
void ex3() {
	cout <<"x";
	cout << setw(15) << "Y(x)";
	cout << setw(15) << "S(x)";
	cout << setw(12) << "N" << endl;
	double E = 0.0000001;

	for (double x = 0; x <= 1; x += 0.2) {
		double Y = exp(2 * x), S = 1, p = 1;
		int k=0;
		double n = 1;
		while  (abs(S - Y) > E){
			p *= (2 * x / n);
			S += p;
			k = n;
			n++;
		}
		cout << setw(3)<<x;
		cout << setw(15) << setprecision(7) << Y;
		cout << setw(15) << setprecision(7) << S ;
		cout << setw(10) << k << endl;
	}
}
void ex4() {
	char f;
	do {
		long double y = 1, x, p = 1;
		int k, k1=1;
		cin >> x; cin >> k;
		double n = 3;
		while (k1 <= k) {
			k1 += 1;
			p *= -(n / (n - 1)) * x;
			y += p;
			if (k1 == 3 || k1 == 5 || k1 == 10) {
				cout <<"S" <<k1<<": " << setprecision(10) << y << endl;
			}
			n += 2;
		}
		cout <<"S: " << setprecision(10) << y << endl;
		cout << "Продолжить работу ? (y / n)"; cin >> f;
	} while (f == 'y');
}




int main() {
	system("chcp 1251 > nul");
	short n=0;
	cout << "Выберите номер задания "; cin >> n;
	switch (n){
	case 1: ex1(); break;
	case 2: ex2(); break;
	case 3: ex3(); break;
	case 4: ex4(); break;
	}
	return 0;
}
