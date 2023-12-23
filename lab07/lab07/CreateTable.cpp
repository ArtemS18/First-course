#include "headers.h"

using namespace std;

// for select unique elements in firstly matrix
void checkTableChar(int TableCharRow[512], int TableCharColumn[512], int& sum1, int& sum2, int i, int g) {
	bool f1 = 1, f2 = 1;
	for (int ide = 0; ide < sum1; ide++) {
		if (TableCharRow[ide] == i) { f1 = 0;break; }
	}
	for (int ide = 0; ide < sum2; ide++) {
		if (TableCharColumn[ide] == g) { f2 = 0;break; }
	}
	if (f1) { TableCharRow[sum1] = i; sum1++; }
	if (f2) { TableCharColumn[sum2] = g; sum2++; }
}
// for define characters which can broke the table.
bool stopList(int t_i) {
	if (t_i != -129 &&t_i != -104 && t_i != -83 && t_i != 10 && t_i != 13 && t_i != 8&&t_i!=9 && t_i != 127 && t_i != 152 && t_i != 173 && t_i != -246) {
		return 1;
	}
	else {
		return 0;
	}
}
void CreateTable(const char outputFile[], int **data_s) {
	ofstream file;
	file.open(outputFile, ios::binary);
	int sum1 = 0, sum2 = 0, t_g, t_i, row, column;
	int TableCharRow[512];
	int TableCharColumn[512];

	file << "   ";
	// create matrix for table
	for (int i = 0; i < 512; i++) {
		for (int g = 0; g < 512; g++) {
			if (data_s[i][g] != 0) {
				checkTableChar(TableCharRow, TableCharColumn, sum1, sum2, i, g);
			}
		}
	}
	// create header row
	for (int i = 0; i < sum1; i++) {
		row = TableCharRow[i];
		if (row > 255) { row = 255 - row; }
		if (stopList(row)) { file << "  "  << char(row) << "  "; file << ' '; }
		else { file << "   -  "; }
	}
	file << '\n' << "";
	for (int _ = 0; _ < sum1; _++) {
		file << "";
	}
	file << '\n';
	// create other table
	int printColumn;
	for (int i = 0; i < sum2; i++) {
		printColumn = TableCharColumn[i];
		column = TableCharColumn[i];
		//cout << printColumn << endl;
		if (printColumn > 255) printColumn = 256- printColumn;
		if (stopList(printColumn)) { file << char(printColumn) << " "; } // create left column
		else { file << "  "; } 
		for (int g = 0; g < sum1; g++) {// create all rows
			row = TableCharRow[g];
			if (data_s[row][column] != 0) {
				file << "|" << setw(5) << data_s[row][column];
			}
			else {
				file << "|     ";
			}
		}
		file << '\n' << "";

		for (int _ = 0; _ < sum1; _++) {
			file << "";
		}
		file << '\n';
	}
	cout << "TABLE SUCCESSFULLY CREATED IN " << outputFile << endl;
}
