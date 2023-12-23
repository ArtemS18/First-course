#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
void getKeys(const char[], int*);
int getCountKeys(const char[]);
long getSize(const char[]);

void Encode(const char [], const char[], const char [], int**);
void Decode(const char [], const char[], const char []);

void fillArr(int**, int);

void CreateTable(const char[], int**);