#include "headers.h"

using namespace std;

void createIde(int &ide) {
	if (ide < 0) {
		ide = abs(ide) + 256;
	}
}

void Encode(const char inputFileName[], const char outputFileName[], const char keysFileName[], int **statistic) {
	ifstream inpFile;
	ofstream outFile;
	inpFile.open(inputFileName, ios::binary);
	outFile.open(outputFileName, ios::binary);

	fillArr(statistic,512);

	const long size = getSize(inputFileName);
	int NewIde, PreIde;

	int len_keys = getCountKeys(keysFileName);
	int* arr_keys = new int[len_keys];
	getKeys(keysFileName, arr_keys);

	int int_cr; char character;
	for (int i = 0; i < size; i++) {
		inpFile.get(character);
		PreIde = (int)character;
		int_cr = (int)character;
		
		int_cr += 256;
		NewIde = (int_cr + arr_keys[i % len_keys])%256;
		outFile << (char)NewIde;
		
		createIde(NewIde);createIde(PreIde);
		
		statistic[NewIde][PreIde]++;
	}

	delete[] arr_keys;

	inpFile.close();
	outFile.close();
	cout << "FILE " << inputFileName << " SUCCESSFULLY ENCODED IN " << outputFileName << endl;
}
void Decode(const char inputFileName[], const char outputFileName[], const char keysFileName[]) {
	ifstream inpFile;
	ofstream outFile;
	inpFile.open(inputFileName, ios::binary);
	outFile.open(outputFileName, ios::binary);

	const long size = getSize(inputFileName);
	int NewIde;

	int len_keys = getCountKeys(keysFileName);
	int* arr_keys = new int[len_keys];
	getKeys(keysFileName, arr_keys);

	char character;
	int int_cr;
	for (int i = 0; i < size; i++) {
		inpFile.get(character);
		int_cr = (int)character;
		int_cr += 256;
		NewIde = (int_cr - arr_keys[i % len_keys])%256;
		outFile << (char)NewIde;
	}
		
	delete[] arr_keys;
	
	inpFile.close();
	outFile.close();
	cout << "FILE " << inputFileName << " SUCCESSFULLY DECODED IN " << inputFileName << endl;
}

