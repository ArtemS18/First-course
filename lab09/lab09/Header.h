#pragma once
#include <iostream>
#include <fstream>

const int max_size = 100;
const int l_word = 31;

struct Dictionary {
    char* eng;
    char* rus;

};

Dictionary dict[max_size];
int len = 0;

int Menu();
void AddWord();
void RemoveWord();
void Translete(int);
void PrintAllDict();
void SaveDict();
void DownloadDict();