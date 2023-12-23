#include <iostream>

using namespace std;

void fillArr(char** m, int l) {
    for (int i = 0; i < l; i++) {
        for (int g = 0; g < l; g++) {
            m[i][g] = char(rand() % 25 + 97);

        }

    }
}

void sortRow(char* m, int l) {
    for (int i = 0; i < l; i++) {
        for (int g = 0; g < l - i-1; g++) {
            if (int(m[g]) > int(m[g + 1])) {
                swap(m[g], m[g + 1]);
            }
        }
    }
}

void sortColum(char** m, int l) {
    for (int i = 0; i < l; i++) {
        for (int g = 0; g < l - i-1; g++) {
            for (int j = 0; j < l; j++) {
                if (int(m[g][j]) > int(m[g + 1][j])) {
                    swap(m[g], m[g + 1]);
                    break;
                }
                else if (int(m[g][j]) < int(m[g + 1][j])) {

                    break;
                }
            }
        }
    }
}
void printM(char** m, int l) {
    for (int i = 0; i < l; i++) {
        for (int g = 0; g < l; g++) {
            cout << int(m[i][g]) << ' ';

        }
        cout << '\n';
    }
}

int main() {
    int k = 4;
    char** m = new char* [k];
    for (int i = 0; i < k; i++) { m[i] = new char[k]; }
    fillArr(m, k);
    printM(m, k);
    cout << '\n';
    for (int i = 0; i < k; i++) {
        sortRow(m[i], k);
    }
    printM(m, k);

    sortColum(m, k);
    cout << '\n';
    printM(m, k);
}

