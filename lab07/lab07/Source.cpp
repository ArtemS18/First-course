#include "headers.h"

using namespace std;

long getSize(const char fileName[]) {
	long size=0;
	ifstream file(fileName, ios::binary);
	size = file.tellg();

	file.seekg(0, std::ios::end);
	size = (long)file.tellg() - size;
	file.close();
	return size;
}

void fillArr(int **arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int g = 0; g < size; g++) {
			arr[i][g] = 0;
		}
	}
}
void getKeys(const char fileName[], int* arr) {
	ifstream fin(fileName, ios::in);
	char ch;
	int sum=0, i=0,  k;
	if (!fin) {
		cout << "Error of file opening." << endl;
		exit(0);
	}
	while (fin.get(ch)) {
		if (ch != ' ' && ch != '\0' && ch != '\n') {
			k = (int)ch;
			if (k < 0) k += 256;
			sum += k;
		}
		else {
			arr[i] = sum%256;
			sum = 0;
			i++;
		}
	}
	fin.close();
}
int getCountKeys(const char fileName[]) {
	ifstream fin(fileName, ios::in);
	char ch;
	int k = 1; 
	if (!fin) {
		cout << "Error of file opening." << endl;
		exit(0);
	}
	while (fin.get(ch)) {
		if (ch == ' ' || ch =='\n') {
			k++;
		}
	}
	fin.close();
	return k;
}
