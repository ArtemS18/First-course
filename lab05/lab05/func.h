#include <iostream>
#include <array>
#include <iomanip>
#include <algorithm>

struct Arry {
	int* copy1;
	int* copy2;
};

void print(int arr[], int len);

void random_val(Arry Arr, int x0, int x1, int l1);

void bouble(int arr[], int len, int& n, int& per);

void rev_bouble(int arr[], int len, int& n, int& per);

void rev_selection(int arr[], int len, int& n, int& per);

void selection(int arr[], int len, int& n, int& per);

void printRow(char nameArr[], char tape[], int len, int n, int per);

void printArr(int arr[], int len);