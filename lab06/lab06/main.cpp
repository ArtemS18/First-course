#include "headers.h"

using namespace std;

int main(){
	double E[] = { 0.01, 0.001, 0.0001, 0.00001, 0.000001 };
	TPF F[] = { f1, f2, f3, f4 };
	TPM Metods[] = {IntRect, IntTrap};
	const char* NameF[4] = { "y=x ", "y=sin22x", "y=x^4 ", "y=arctgx" };

	double a; double b; double S; 
	int n=0; int id=0;
	I_print Arr[4 * 2 * 5];

	cout << "A: ";cin >> a; 
	cout << "B: ";cin >> b;
	cout << endl;
	cout << "Loading";

	for (int i = 0; i<5; i++) {
		
		for (int k = 0; k < 2; k++) {
			for (int g = 0; g < 4; g++) {
				Arr[id].name = NameF[g];
				Arr[id].i_sum = Integral(F[g], Metods[k], E[i], a, b, n);
				Arr[id].i_toch = PresInt(g, a, b);
				Arr[id].n = n;
				id++;
			}
			cout << '.';
			
		}
	}
	cout << endl;
	cout << "Finally! Results: " << endl;
	id = 0;
	for (int i = 0; i < 5; i ++) {
		fullRow(59);cout << endl;
		cout<<setprecision(i+2)<<setw(15)<<"EPS = "<<E[i]<<';' <<setprecision(5)<<setw(15) << a << " <= x <= " << b << endl;
		fullRow(59);cout << endl;
		for (int k = 0; k < 2; k++) {
			if (k == 0){
				cout << setw(33)<<"IntRect" << endl;
			}
			else {
				cout << setw(33) <<"IntTrap" << endl;
			}
			PrintTabl(Arr, id * 4);
			id++;
		}
		cout << endl;
	}
	return 0;
}

