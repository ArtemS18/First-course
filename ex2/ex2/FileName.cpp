#include <iostream>

using namespace std;

void fillArr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 20 - 10;
    }
}
int findP(int* arr, int len) {
    int P = 1;
    for (int i = 0; i < len; i++) {
        if (arr[i] > 0) { P *= arr[i]; }
    }
    return P;
}

int main() {
    int l = 10;
    int* m = new int[l];
    fillArr(m, l);
    int P = findP(m, l);
    for (int i = 0; i < l; i++) {
        cout << m[i] << ' ';
    }
    cout << '\n' << P;

}