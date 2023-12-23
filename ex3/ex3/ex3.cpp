#include <iostream>

using namespace std;

int getSize(char* m, int len) {
    int size = 0;
    for (int i = 0; i < len;i++) {
        size++;
        if (m[i] == '\0') {
            return size;
        }
    }

    return size;
}
int main() {
    char* m = new char[100];
    cin.getline(m, 100);
    int len = getSize(m, 100);
    int id;
    cin >> id;
    char cp1 = m[id], cp2 = m[id + 1], cp3 = m[id + 2];
    for (int i = id; i < len; i += 3) {
        swap(cp1, m[i + 3]);
        swap(cp2, m[i + 4]);
        swap(cp3, m[i + 5]);
    }
    m[id] = 'c';
    m[id + 1] = 'a';
    m[id + 2] = 't';
    cout << m;
    return 0;

}