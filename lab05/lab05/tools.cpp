#include "func.h"
using namespace std;

void printArr(int arr[], int len) {
    if (len > 10){
        for (int i = 0; i < 10; i++) {
            if (i < 9) {
                cout << arr[i] << ", ";
            }
            else {
                cout << arr[i]<<".....";
            }
        }
    }
    else if (len < 10) {
        for (int i = 0; i < len; i++) {
            if (i < len-1) {
                cout << arr[i] << ", ";
            }
            else {
                cout << arr[i];
            }
        }
    }
    else {
        for (int i = 0; i < 10; i++) {
            if (i < 9) {
                cout << arr[i] << ", ";
            }
            else {
                cout << arr[i];
            }
        }
    }
    cout << endl;
}

void random_val(Arry Arr, int x0, int x1, int l1) {
    int randVal;
    for (int i = 0; i < l1; i++) {
        randVal = rand() % (abs(x1 - x0) + 1);
        Arr.copy1[i] = randVal;
        Arr.copy2[i] = randVal;
    }

}

void printRow(char nameArr[], char tape[], int len, int n, int per) {
    cout <<setw(20)<<nameArr <<setw(20)<<tape <<setw(20) <<len << setw(20) << n << setw(20) << per << endl;
}
