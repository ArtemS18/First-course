#include "func.h"
using namespace std;

void bouble(int arr[], int len, int& n, int& per) {
    n = 0, per = 0;
    bool f = true;
    for (int i = 0; i < len-1; i++) {
        for (int g = 0; g < len-i-1; g++) {
            if (arr[g]> arr[g+1]){
                swap(arr[g], arr[g+1]);
                f = false;
                per++;
            }
            n++;
        }
        if (f){
            break;
        }
    }
}
void rev_bouble(int arr[], int len, int& n, int& per) {
    n = 0, per = 0;
    bool f = true;
    for (int i = 0; i < len-1; i++) {
        for (int g = 0; g < len-i-1; g++) {
            if (arr[g] < arr[g+1]) {
                swap(arr[g], arr[g+1]);
                f = false;
                per++;
            }
            n++;
        }
        if (f) {
            break;
        }
    }
}

void rev_selection(int arr[], int len, int& n, int& per) {
    n = 0, per = 0;
    for (int j = 0; j < len; j++) {
        int minid = j;
        for (int i = j + 1; i < len; i++) {
            if (arr[minid] < arr[i]) {
                minid = i;
            }
            n++;
        }
        if (minid != j) {
            int _ = arr[minid];
            arr[minid] = arr[j];
            arr[j] = _;
            per++;
        }
    }
}
void selection(int arr[], int len, int& n, int& per) {
    n = 0, per = 0;

    for (int j = 0; j<len; j++) {
        int minid = j;
        for (int i = j+1; i <len; i++) {
            if (arr[minid] > arr[i]) {
                minid = i;
            }
            n++;
        }
        if (minid != j) {
            int _ = arr[minid];
            arr[minid] = arr[j];
            arr[j] = _;
            per++;
        }
    }
}



