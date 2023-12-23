#include "headers.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const int SIZE = 512;
	const char text[] = "text.txt",
		encoded[] = "encode.txt", 
		decoded[] = "decode.txt",
		keys[] = "keys.txt",
		table[] = "stat.txt";

	int** statisticMatrix = new int*[SIZE];
	for (int i = 0; i < SIZE; i++) { statisticMatrix[i] = new int[SIZE]; }

	Encode(text, encoded, keys, statisticMatrix);
	Decode(encoded, decoded, keys);

	CreateTable(table, statisticMatrix);

	for (int i = 0; i < SIZE; i++) { delete [] statisticMatrix[i]; }
	delete[] statisticMatrix;
}


